/**
 * @file main.cpp
 * @brief Demo CLI for the speaker SDK.
 *
 * This is a simple interactive shell that demonstrates every SpeakerInterface API.
 * Developers should read interface.h for the full API reference.
 *
 * Usage:
 *   ./S600L_client <ip> <port>
 *   e.g.: ./S600L_client 192.168.144.67 14556
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "speaker_interface.h"

static std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> tokens;
    std::istringstream iss(s);
    std::string t;
    while (iss >> t) tokens.push_back(t);
    return tokens;
}

static void print_help()
{
    std::cout << "\n===== SPEAKER CLIENT COMMANDS =====\n"
              << "  upload <local_file>               - Upload audio file into media/\n"
              << "  upload_fw <firmware_path>          - Upload firmware and restart\n"
              << "  list                              - List audio files\n"
              << "  rename <old_name> <new_name>      - Rename audio file\n"
              << "  delete <filename>                 - Delete audio file\n"
              << "  sub <filename>                    - Subscribe to audio info\n"
              << "  play <index>                      - Play audio once\n"
              << "  loop <index>                      - Loop-play audio\n"
              << "  stop                              - Stop playback\n"
              << "  listen <start|stop>               - Real-time listen\n"
              << "  speake <start|stop>               - Real-time speak\n"
              << "  volume <0-100>                    - Set volume\n"
              << "  angle <roll> <pitch> <yaw>        - Set angle (H600L)\n"
              << "  light_mode <mode>                 - Set light mode\n"
              << "  light <on|off>                    - Light on/off\n"
              << "  ex_light <on|off>                 - External light (S600L)\n"
              << "  take_picture                      - Take photo (S600L)\n"
              << "  start_video                       - Start recording (S600L)\n"
              << "  stop_video                        - Stop recording (S600L)\n"
              << "  switch_lens <0|1>                 - Switch lens (S600L)\n"
              << "  information                       - Device info\n"
              << "  storage                           - Storage info\n"
              << "  restart                           - Restart speaker\n"
              << "  config set <name> <value>         - Set parameter\n"
              << "  config get <name>                 - Get parameter\n"
              << "  config list                       - List all parameters\n"
              << "  help                              - Show this help\n"
              << "  exit                              - Quit\n"
              << "======================================\n";
}

// Helper: print a ParamValue
static void print_param(const SpeakerInterface::ParamValue& pv)
{
    std::cout << "  " << pv.name << " = ";
    switch (pv.type) {
    case SpeakerInterface::ParamValue::Type::Int:
        std::cout << pv.int_val << " (int)";
        break;
    case SpeakerInterface::ParamValue::Type::Float:
        std::cout << pv.float_val << " (float)";
        break;
    case SpeakerInterface::ParamValue::Type::String:
        std::cout << pv.string_val << " (string)";
        break;
    }
    std::cout << std::endl;
}

int main(int argc, const char* argv[])
{
    // --- Parse command-line arguments ---
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <ip> <port>\n"
                  << "  e.g.: " << argv[0] << " 192.168.144.67 14556" << std::endl;
        return 1;
    }

    const std::string ip = argv[1];
    int port = 0;
    try {
        port = std::stoi(argv[2]);
    } catch (...) {
        std::cerr << "Invalid port: " << argv[2] << std::endl;
        return 1;
    }

    // --- Initialize speaker SDK ---
    SpeakerInterface speaker;
    speaker.set_verbose(true);  // Demo mode: show debug/progress output

    if (!speaker.init(ip, port)) {
        std::cerr << "SDK init failed." << std::endl;
        return 1;
    }

    // --- Interactive command loop ---
    std::cout << "Speaker Client - Interactive Mode" << std::endl;
    print_help();

    while (true) {
        std::cout << "\nEnter command: ";
        std::string line;
        std::getline(std::cin, line);
        auto args = split(line);
        if (args.empty()) continue;

        const std::string& cmd = args[0];

        if (cmd == "exit") {
            break;
        } else if (cmd == "help") {
            print_help();

        // ---------- File operations ----------
        } else if (cmd == "upload" && args.size() >= 2) {
            speaker.upload_audio(args[1]);

        } else if (cmd == "upload_fw" && args.size() >= 2) {
            speaker.upload_firmware(args[1]);

        } else if (cmd == "list") {
            SpeakerInterface::FileList files;
            if (speaker.list_audio(files)) {
                if (!files.dirs.empty()) {
                    std::cout << "Directories:" << std::endl;
                    for (const auto& d : files.dirs)
                        std::cout << "  [DIR] " << d << std::endl;
                }
                std::cout << "Files:" << std::endl;
                for (const auto& f : files.files)
                    std::cout << "  " << f << std::endl;
                std::cout << "Total: " << files.files.size() << " files" << std::endl;
            }

        } else if (cmd == "rename" && args.size() >= 3) {
            speaker.rename_audio(args[1], args[2]);

        } else if (cmd == "delete" && args.size() >= 2) {
            speaker.delete_audio(args[1]);

        } else if (cmd == "sub" && args.size() >= 2) {
            speaker.subscribe_audio_info(args[1],
                [](const SpeakerInterface::AudioFileInfo& info) {
                    std::cout << "Audio: " << info.name
                              << " index=" << info.index
                              << " format=" << info.format
                              << " length=" << info.length_seconds << "s"
                              << std::endl;
                });

        // ---------- Playback ----------
        } else if (cmd == "play" && args.size() >= 2) {
            speaker.play(std::stoi(args[1]));

        } else if (cmd == "loop" && args.size() >= 2) {
            speaker.loop_play(std::stoi(args[1]));

        } else if (cmd == "stop") {
            speaker.stop();

        // ---------- Real-time voice ----------
        } else if (cmd == "listen" && args.size() >= 2) {
            if (args[1] == "start") speaker.start_listen();
            else if (args[1] == "stop") speaker.stop_listen();
            else std::cout << "Usage: listen <start|stop>" << std::endl;

        } else if (cmd == "speake" && args.size() >= 2) {
            if (args[1] == "start") speaker.start_speak();
            else if (args[1] == "stop") speaker.stop_speak();
            else std::cout << "Usage: speake <start|stop>" << std::endl;

        // ---------- Volume / Angle ----------
        } else if (cmd == "volume" && args.size() >= 2) {
            speaker.set_volume(std::stof(args[1]));

        } else if (cmd == "angle" && args.size() >= 4) {
            speaker.set_angle(std::stof(args[1]), std::stof(args[2]), std::stof(args[3]));

        // ---------- Light ----------
        } else if (cmd == "light_mode" && args.size() >= 2) {
            speaker.set_light_mode(std::stoi(args[1]));

        } else if (cmd == "light" && args.size() >= 2) {
            speaker.set_light_on_off(args[1] == "on");

        } else if (cmd == "ex_light" && args.size() >= 2) {
            speaker.set_external_light_on_off(args[1] == "on");

        // ---------- Camera ----------
        } else if (cmd == "take_picture") {
            speaker.take_picture();

        } else if (cmd == "start_video") {
            speaker.start_video();

        } else if (cmd == "stop_video") {
            speaker.stop_video();

        } else if (cmd == "switch_lens" && args.size() >= 2) {
            speaker.switch_lens(std::stoi(args[1]));

        // ---------- Device info ----------
        } else if (cmd == "information") {
            SpeakerInterface::DeviceInfo info;
            if (speaker.get_information(info)) {
                std::cout << "Vendor:   " << info.vendor_name << "\n"
                          << "Model:    " << info.model_name << "\n"
                          << "Serial:   " << info.serial_number << "\n"
                          << "Firmware: " << info.firmware_version << std::endl;
            }

        } else if (cmd == "storage") {
            SpeakerInterface::StorageInfo si;
            if (speaker.get_storage(si)) {
                std::cout << "Total:     " << si.total_mib << " MiB\n"
                          << "Used:      " << si.used_mib << " MiB\n"
                          << "Available: " << si.available_mib << " MiB" << std::endl;
            }

        } else if (cmd == "restart") {
            speaker.restart();

        // ---------- Parameters ----------
        } else if (cmd == "config" && args.size() >= 2) {
            if (args[1] == "set" && args.size() >= 4) {
                speaker.set_param(args[2], args[3]);

            } else if (args[1] == "get" && args.size() >= 3) {
                SpeakerInterface::ParamValue pv;
                if (speaker.get_param(args[2], pv)) {
                    print_param(pv);
                }

            } else if (args[1] == "list") {
                std::vector<SpeakerInterface::ParamValue> params;
                if (speaker.get_all_params(params)) {
                    std::cout << "\n===== SPEAKER PARAMETERS =====" << std::endl;
                    int idx = 1;
                    for (const auto& pv : params) {
                        std::cout << "  " << idx++ << ". ";
                        print_param(pv);
                    }
                    std::cout << "=============================" << std::endl;
                }
            } else {
                std::cout << "Usage: config <set name value | get name | list>" << std::endl;
            }
        } else {
            std::cout << "Unknown command or missing arguments. Type 'help' for commands." << std::endl;
        }
    }

    std::cout << "Exiting Speaker Client." << std::endl;
    return 0;
}
