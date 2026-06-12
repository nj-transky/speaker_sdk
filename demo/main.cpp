/**
 * @file main.cpp
 * @brief Demo CLI for the speaker SDK.
 *
 * This is a simple interactive shell that demonstrates every SpeakerInterface API.
 *
 * Usage:
 *   ./S600L_client <ip> <port>
 *   ./S600L_client <connection_url> [ftp_url]
 *
 * Examples:
 *   ./S600L_client 192.168.144.67 14556
 *   ./S600L_client udpin://0.0.0.0:14550
 *   ./S600L_client mqttout://47.120.45.100:1883;client1
 *   ./S600L_client serial:///dev/ttyUSB0:57600
 *   ./S600L_client tcpout://192.168.144.67:14556 tcpout://192.168.144.67:14566
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "speaker_interface.h"
#include "speaker_utils.h"
#include <thread>
#include <chrono>

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
              << "  upload <local_file>               - Upload audio file into speaker\n"
              << "  download <remote_name> <local>    - Download audio file\n"
              << "  upload_fw <firmware_path>          - Upload firmware and restart\n"
              << "  list                              - List audio files\n"
              << "  rename <old_name> <new_name>      - Rename audio file\n"
              << "  delete <filename>                 - Delete audio file\n"
              << "  sub <filename>                    - Subscribe to audio info\n"
              << "  unsub <handle>                    - Unsubscribe audio info\n"
              << "  play <index>                      - Play audio once\n"
              << "  loop <index>                      - Loop-play audio\n"
              << "  stop                              - Stop playback\n"
              << "  status                            - Get speaker status\n"
              << "  status_sub                        - Subscribe to status updates\n"
              << "  listen <start|stop>               - Real-time listen\n"
              << "  speak <start|stop>                - Real-time speak\n"
              << "  volume <0-100>                    - Set volume\n"
              << "  angle <roll> <pitch> <yaw>        - Set angle (H600L)\n"
              << "  light_mode <mode>                 - Set light mode(0-4)\n"
              << "  light <on|off>                    - Light on/off\n"
              << "  ex_light <on|off>                 - External light (S600L)\n"
              << "  ex_light_status                   - Get external light status (S600L)\n"
              << "  take_picture                      - Take photo (S600L)\n"
              << "  start_video                       - Start recording (S600L)\n"
              << "  stop_video                        - Stop recording (S600L)\n"
              << "  switch_lens <0|1>                 - Switch lens (S600L)\n"
              << "  camera_get                - Get camera network params (S600L)\n"
              << "  camera_set <ip> <bitrate> <resolution> <encoding>\n"
              << "                                    - Set camera network params (S600L)\n"
              << "                                      bitrate: 0-7, resolution: 0-3, encoding: 0-2\n"
              << "  information                       - Device info\n"
              << "  storage                           - Storage info\n"
              << "  format                            - Format storage (erases all data!)\n"
              << "  restart                           - Restart speaker\n"
              << "  config set <name> <value>         - Set parameter\n"
              << "  config get <name>                 - Get parameter\n"
              << "  config list                       - List all parameters\n"
              << "  log_sub                           - Subscribe to log\n"
              << "  log_unsub <handle>                 - Unsubscribe log\n"
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
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <ip> <port>\n"
                  << "       " << argv[0] << " <connection_url> [ftp_url]\n"
                  << "  e.g.: " << argv[0] << " 192.168.144.67 14556\n"
                  << "        " << argv[0] << " mqttout://broker:1883;client1\n"
                  << "        " << argv[0] << " serial:///dev/ttyUSB0:57600" << std::endl;
        return 1;
    }

    // 1. Initialize speaker SDK ---
    SpeakerInterface speaker;
    speaker.set_verbose(true);  // Demo mode: show debug/progress output

    std::string first_arg = argv[1];
    bool init_ok = false;

    if (first_arg.find("://") != std::string::npos) {
        // URL mode
        std::string ftp_url = (argc >= 3) ? argv[2] : "";
        init_ok = speaker.init(first_arg, ftp_url, 10);
    } else {
        // Traditional ip port mode
        if (argc < 3) {
            std::cerr << "Usage: " << argv[0] << " <ip> <port>" << std::endl;
            return 1;
        }
        int port = 0;
        try {
            port = std::stoi(argv[2]);
        } catch (...) {
            std::cerr << "Invalid port: " << argv[2] << std::endl;
            return 1;
        }
        init_ok = speaker.init(first_arg, port);
    }

    if (!init_ok) {
        std::cerr << "SDK init failed." << std::endl;
        return 1;
    }

    // Route SDK-internal log messages to stderr so they don't interleave
    // with the per-chunk progress lines that go to stdout.
    speaker.set_sdk_log_callback(
        [](SpeakerInterface::SdkLogLevel level, const std::string& message) {
            std::cerr << "[speaker] [" << sdk_log_level_to_string(level) << "] "
                      << message << std::endl;
        });

    if (!speaker.is_ftp_available()) {
        std::cout << "Note: FTP not available. File operations will not work." << std::endl;
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
            speaker.upload_audio_with_cb(args[1],
                [](const SpeakerInterface::TransferProgress& p) {
                    std::cout << "\rUploading [" << std::setw(3) << p.percentage << "%] "
                              << p.bytes_transferred << " of " << p.total_bytes
                              << std::flush;
                    if (p.percentage >= 100) std::cout << std::endl;
                });

        } else if (cmd == "download" && args.size() >= 3) {
            speaker.download_audio_with_cb(args[1], args[2],
                [](const SpeakerInterface::TransferProgress& p) {
                    std::cout << "\rDownloading [" << std::setw(3) << p.percentage << "%] "
                              << p.bytes_transferred << " of " << p.total_bytes
                              << std::flush;
                    if (p.percentage >= 100) std::cout << std::endl;
                });

        } else if (cmd == "upload_fw" && args.size() >= 2) {
            speaker.upload_firmware_with_cb(args[1],
                [](const SpeakerInterface::TransferProgress& p) {
                    std::cout << "\rUploading firmware [" << std::setw(3) << p.percentage << "%] "
                              << p.bytes_transferred << " of " << p.total_bytes
                              << std::flush;
                    if (p.percentage >= 100) std::cout << std::endl;
                });

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
            auto h = speaker.subscribe_audio_info(args[1],
                [](const SpeakerInterface::AudioFileInfo& info) {
                    std::cout << "Audio: " << info.name
                              << " index=" << info.index
                              << " format=" << info.format
                              << " length=" << info.length_seconds << "s"
                              << std::endl;
                });
            std::cout << "Subscribed (handle=" << h << ")" << std::endl;

        } else if (cmd == "unsub" && args.size() >= 2) {
            int handle = std::stoi(args[1]);
            speaker.unsubscribe_audio_info(handle);

        // ---------- Status ----------
        } else if (cmd == "status") {
            SpeakerInterface::SpeakerStatus s;
            if (speaker.get_status(s)) {
                std::cout << "\n===== SPEAKER STATUS =====" << std::endl;
                std::cout << "  Play mode:    " << play_mode_to_string(s.play_mode) << std::endl;
                std::cout << "  Play status:  " << play_status_to_string(s.play_status) << std::endl;
                std::cout << "  Play time:    " << s.playing_time_s << " s" << std::endl;
                std::cout << "  Volume:       " << s.current_volume << " %" << std::endl;
                std::cout << "  Signal:       " << s.network_module_signal_quality << " %" << std::endl;
                std::cout << "  Latency:      " << s.network_module_latency_ms << " ms" << std::endl;
                std::cout << "  Angle:        roll=" << s.angle.roll << " pitch=" << s.angle.pitch << " yaw=" << s.angle.yaw << std::endl;
                std::cout << "  Light mode:   " << light_mode_to_string(s.light_mode) << std::endl;
                std::cout << "  Light on/off: " << (s.light_on_off == SpeakerInterface::SwitchOnOff::On ? "On" : "Off") << std::endl;
                std::cout << "  Listen:       " << voice_status_to_string(s.real_time_listen_status) << std::endl;
                std::cout << "  Speak:        " << voice_status_to_string(s.real_time_speak_status) << std::endl;
                std::cout << "=========================" << std::endl;
            }

        } else if (cmd == "status_sub") {
            speaker.subscribe_status([](const SpeakerInterface::SpeakerStatus& s) {
                std::cout << "[STATUS] mode=" << play_mode_to_string(s.play_mode)
                          << " status=" << play_status_to_string(s.play_status)
                          << " vol=" << s.current_volume
                          << " time=" << s.playing_time_s << "s"
                          << " signal=" << s.network_module_signal_quality << "%"
                          << " latency=" << s.network_module_latency_ms << "ms"
                          << " listen=" << voice_status_to_string(s.real_time_listen_status)
                          << " speak=" << voice_status_to_string(s.real_time_speak_status)
                          << std::endl;
            });
            std::cout << "Subscribed to status updates." << std::endl;

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

        } else if (cmd == "speak" && args.size() >= 2) {
            if (args[1] == "start") speaker.start_speak();
            else if (args[1] == "stop") speaker.stop_speak();
            else std::cout << "Usage: speak <start|stop>" << std::endl;

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

        } else if (cmd == "ex_light_status") {
            bool on = false;
            if (speaker.get_external_light_status(on)) {
                std::cout << "External light: " << (on ? "On" : "Off") << std::endl;
            }

        // ---------- Camera ----------
        } else if (cmd == "take_picture") {
            speaker.take_picture();

        } else if (cmd == "start_video") {
            speaker.start_video();

        } else if (cmd == "stop_video") {
            speaker.stop_video();

        } else if (cmd == "switch_lens" && args.size() >= 2) {
            speaker.switch_lens(std::stoi(args[1]));

        // ---------- Camera Network Params ----------
        } else if (cmd == "camera_get") {
            SpeakerInterface::CameraNetworkParams params;
            if (speaker.get_camera_network_params(params)) {
                std::cout << "\n===== CAMERA NETWORK PARAMETERS =====" << std::endl;
                std::cout << "  IP Address: " << params.ip_address << std::endl;
                std::cout << "  Bitrate:    " << params.bitrate << " (" << bitrate_to_string(params.bitrate) << ")" << std::endl;
                std::cout << "  Resolution: " << params.resolution << " (" << resolution_to_string(params.resolution) << ")" << std::endl;
                std::cout << "  Encoding:   " << params.encoding << " (" << encoding_to_string(params.encoding) << ")" << std::endl;
                std::cout << "=====================================" << std::endl;
            }

        } else if (cmd == "camera_set" && args.size() >= 5) {
            SpeakerInterface::CameraNetworkParams params;
            params.ip_address = args[1];
            params.bitrate = std::stoi(args[2]);
            params.resolution = std::stoi(args[3]);
            params.encoding = std::stoi(args[4]);

            if (speaker.set_camera_network_params(params)) {
                std::cout << "Camera network parameters set successfully." << std::endl;
                std::cout << "  IP: " << params.ip_address << std::endl;
                std::cout << "  Bitrate: " << bitrate_to_string(params.bitrate) << std::endl;
                std::cout << "  Resolution: " << resolution_to_string(params.resolution) << std::endl;
                std::cout << "  Encoding: " << encoding_to_string(params.encoding) << std::endl;
            }

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

        } else if (cmd == "format") {
            std::cout << "WARNING: This will erase all data on the speaker storage!" << std::endl;
            std::cout << "Type 'yes' to confirm: ";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (confirm == "yes") {
                speaker.format_storage();
            } else {
                std::cout << "Cancelled." << std::endl;
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

        // ---------- Log ----------
        } else if (cmd == "log_sub") {
            auto h = speaker.subscribe_log_information(
                [](const SpeakerInterface::LogInformation& li) {
                    std::cout << "[" << log_level_to_string(li.log_level) << "] " << li.text << std::endl;
                });
            std::cout << "Log subscribed (handle=" << h << ")" << std::endl;

        } else if (cmd == "log_unsub" && args.size() >= 2) {
            int handle = std::stoi(args[1]);
            speaker.unsubscribe_log_information(handle);

        } else {
            std::cout << "Unknown command or missing arguments. Type 'help' for commands." << std::endl;
        }
    }

    std::cout << "Exiting Speaker Client." << std::endl;
    return 0;
}
