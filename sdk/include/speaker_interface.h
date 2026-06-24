#pragma once
/**
 * @file speaker_interface.h
 * @brief High-level speaker SDK interface for S600L / H600L.
 *
 * This is the ONLY file you need to read as a developer.
 * It wraps all SDK initialization, file transfer, playback, real-time voice,
 * device control, light, camera, and parameter APIs into simple method calls.
 *
 * All methods return data through output parameters or return values --
 * they do NOT print to stdout unless verbose mode is enabled.
 *
 * Quick start:
 *   SpeakerInterface speaker;
 *   std::cout << "Speaker SDK " << SpeakerInterface::sdk_version() << std::endl;
 *   speaker.set_verbose(true);  // optional: enable debug prints
 *   if (!speaker.init("192.168.144.67", 14556)) { ... handle error ... }
 *
 *   // Or connect via URL (TCP/UDP/Serial/MQTT):
 *   speaker.init("tcpout://192.168.144.67:14556", "tcpout://192.168.144.67:14566");
 *   speaker.init("mqttout://broker:1883;client_id");
 *   speaker.init("serial:///dev/ttyUSB0:57600");
 *
 *   // Upload audio
 *   speaker.upload_audio("./local/test.wav");
 *
 *   // Get status
 *   SpeakerInterface::SpeakerStatus status;
 *   speaker.get_status(status);
 *
 *   // Parameters
 *   speaker.set_param_int("SOME_PARAM", 42);
 */

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#ifdef _WIN32
#  ifdef SPEAKER_INTERFACE_BUILD
#    define SPEAKER_INTERFACE_API __declspec(dllexport)
#  else
#    define SPEAKER_INTERFACE_API __declspec(dllimport)
#  endif
#else
#  define SPEAKER_INTERFACE_API __attribute__((visibility("default")))
#endif

// Forward declarations -- developers do NOT need these headers.
namespace mavsdk { class Mavsdk; }

class SPEAKER_INTERFACE_API SpeakerInterface {
public:
    SpeakerInterface();
    ~SpeakerInterface();

    // ==================== Data Structures ====================
    // These are plain structs with no SDK dependency.
    // Developers can use them freely without including any SDK header.

    /** @brief Result of a directory listing operation. */
    struct FileList {
        std::vector<std::string> dirs;   ///< Sub-directory names
        std::vector<std::string> files;  ///< File names
    };

    /** @brief Progress information for an in-flight file transfer. */
    struct TransferProgress {
        uint32_t bytes_transferred{0};  ///< Bytes transferred so far
        uint32_t total_bytes{0};        ///< Total bytes to transfer
        int percentage{0};              ///< 0~100, 0 if total_bytes==0
    };

    /** @brief Status of a file-system operation. */
    enum class FileOperationStatus {
        Success,            ///< Operation completed successfully.
        Timeout,            ///< Operation timed out.
        FileIoError,        ///< File I/O error.
        FileExists,         ///< File already exists.
        FileDoesNotExist,   ///< File does not exist.
        FileProtected,      ///< File is write-protected.
        InvalidParameter,   ///< Caller passed an invalid argument.
        NoSystem,           ///< SDK is not connected to the device.
        Unknown,            ///< Unknown / unspecified result.
        Failed              ///< Operation failed for another reason.
    };

    /** @brief Speaker hardware/firmware information. */
    struct DeviceInfo {
        std::string vendor_name;
        std::string model_name;
        std::string serial_number;
        std::string firmware_version;
    };

    /** @brief Storage capacity information. */
    struct StorageInfo {
        float total_mib{0.0f};      ///< Total storage in MiB
        float used_mib{0.0f};       ///< Used storage in MiB
        float available_mib{0.0f};  ///< Available storage in MiB
    };

    /** @brief Audio file metadata. */
    struct AudioFileInfo {
        std::string name;            ///< audio file name
        uint32_t index{0};            /// audio file index
        std::string format;           /// audio file format
        float length_seconds{0.0f};   /// audio file length in seconds
    };

    /** @brief A single named parameter (int, float, or string). */
    struct ParamValue {
        std::string name;
        enum class Type { Int, Float, String } type{Type::String};
        int int_val{0};
        float float_val{0.0f};
        std::string string_val;
    };

    /** @brief Speaker play mode. */
    enum class PlayMode {
        None,          ///< No active play mode
        SinglePlay,    ///< Play a single audio file
        LoopPlay,      ///< Loop-play an audio file
        RealTimeSpeak  ///< Real-time speak mode
    };

    /** @brief Speaker play status. */
    enum class PlayStatus {
        Idle,     ///< Not playing
        Playing   ///< Currently playing
    };

    /** @brief Real-time voice status. */
    enum class RealTimeVoiceStatus {
        Off,    ///< Real-time voice off
        On,     ///< Real-time voice on
        Error   ///< Real-time voice error
    };

    /** @brief Built-in light mode. */
    enum class LightMode {
        Unknown = 0,  ///< Unknown light mode
        Mode1 = 1,    ///< Light mode 1
        Mode2 = 2,    ///< Light mode 2
        Mode3 = 3,    ///< Light mode 3
        Mode4 = 4     ///< Light mode 4
    };

    /** @brief On/Off switch. */
    enum class SwitchOnOff {
        Off,  ///< Off
        On    ///< On
    };

    /** @brief Device-reported log level (from the speaker via subscribe_log_information). */
    enum class LogLevel {
        Debug,   ///< Debug log level
        Info,    ///< Info log level
        Warning, ///< Warning log level
        Error,   ///< Error log level
        Fatal    ///< Fatal log level
    };

    /** @brief SDK-internal log level (separate from device-reported log level). */
    enum class SdkLogLevel {
        Debug = 0, ///< Debug (per-chunk progress, internal state)
        Info  = 1, ///< Info (operation start/success)
        Warning = 2, ///< Warning
        Error = 3  ///< Error (operation failure)
    };

    /** @brief Callback type for SDK-internal log messages. */
    using SdkLogCallback = std::function<void(SdkLogLevel level, const std::string& message)>;

    /** @brief Gimbal angle values. */
    struct Angle {
        float roll{0.0f};             ///< Roll angle in degrees
        float pitch{0.0f};            ///< Pitch angle in degrees
        float yaw{0.0f};              ///< Yaw angle in degrees
    };

    /** @brief Current speaker status. */
    struct SpeakerStatus {
        PlayMode play_mode{PlayMode::None};        ///< Current play mode
        PlayStatus play_status{PlayStatus::Idle};   ///< Current play status
        float playing_time_s{0.0f};                   ///< Elapsed playback time in seconds
        float current_volume{0.0f};                   ///< Volume percentage (0-100)
        int32_t network_module_signal_quality{0};     ///< Signal quality percentage
        float network_module_latency_ms{0.0f};        ///< Network latency in milliseconds
        Angle angle;
        LightMode light_mode{LightMode::Unknown};
        SwitchOnOff light_on_off{SwitchOnOff::Off};
        RealTimeVoiceStatus real_time_listen_status{RealTimeVoiceStatus::Off};
        RealTimeVoiceStatus real_time_speak_status{RealTimeVoiceStatus::Off};
    };

    /** @brief Log information from the speaker. */
    struct LogInformation {
        std::string text;
        LogLevel log_level{LogLevel::Info};
    };

    // ==================== Configuration ====================

    /**
     * @brief Get the SDK version string (MAJOR.MINOR.PATCH, e.g. "1.3.0").
     *
     * Single source of truth: CMakeLists.txt's project(VERSION ...).
     * Returns a pointer to a baked-in string literal; do not free it.
     */
    static const char* sdk_version();

    /**
     * @brief Enable or disable verbose (debug) output.
     * @param enabled  true = lower log level to Debug (per-chunk progress,
     *                 internal state messages), false = restore Info level.
     *
     * This is a convenience wrapper over set_sdk_log_level(). It does NOT install
     * a callback; the default behavior is: Error messages still go to stderr
     * if no callback is set; other levels are silent.
     */
    void set_verbose(bool enabled);

    /** @brief Check whether the current SDK log level is Debug. */
    bool is_verbose() const;

    /**
     * @brief Set the minimum SDK log level. Messages below this level are dropped.
     * @param level  Minimum level to emit. Default is Info.
     */
    void set_sdk_log_level(SdkLogLevel level);

    /**
     * @brief Install a callback to receive all SDK-internal log messages.
     * @param callback  Called from SDK threads; do NOT call SpeakerInterface
     *                  methods from inside. If nullptr, the default behavior
     *                  applies: Error messages go to stderr, others are silent.
     *
     * This is for SDK-internal log messages only. To receive log messages
     * reported by the speaker device, use subscribe_log_information().
     */
    void set_sdk_log_callback(SdkLogCallback callback);

    // ==================== Initialization ====================

    /**
     * @brief Initialize the SDK and connect to the speaker over TCP.
     * @param ip   Device IP address, e.g. "192.168.144.67"
     * @param port TCP port, e.g. 14556
     * @return true on success (system discovered), false on failure.
     *
     * This performs the full lifecycle:
     *   1. Create instance with GroundStation role.
     *   2. Connect via TCP (tcpout://<ip>:<port>).
     *   3. Wait up to 10 s for speaker system discovery.
     *   4. Create internal FTP-pro backend (port + 10).
     *   5. Set up status/log subscriptions.
     */
    bool init(const std::string& ip, int port);

    /**
     * @brief Initialize the SDK and connect using a connection URL.
     * @param connection_url  Full MAVSDK connection URL, e.g.:
     *   - "tcpout://192.168.144.67:14556"
     *   - "udpout://192.168.144.67:14550"
     *   - "serial:///dev/ttyUSB0:57600"
     *   - "mqttout://47.120.45.100:1883;client_id"
     * @param ftp_url  Optional FTP-pro TCP URL for file operations.
     *   If empty, file operations will be unavailable.
     *   For TCP connections, typically "tcpout://<ip>:<port+10>".
     * @param timeout_s  Timeout in seconds for system discovery (default 10).
     * @return true on success (system discovered), false on failure.
     */
    bool init(const std::string& connection_url,
              const std::string& ftp_url,
              int timeout_s);

    /** @brief Check whether init() succeeded and the system is connected. */
    bool is_connected() const;

    /** @brief Check whether FTP file operations are available. */
    bool is_ftp_available() const;

    /**
     * @brief Subscribe a callback that fires when the device disconnects.
     * @param callback  Called when connection is lost.
     */
    void subscribe_on_disconnect(std::function<void()> callback);

    // ==================== Audio File Operations ====================

    /**
     * @brief Upload a local audio file into the speaker's directory.
     * @param local_path Full local path, e.g. "./audio/test.wav"
     * @return FileOperationStatus.
     *
     * If you want progress delivered to a callback, use upload_audio_with_cb().
     */
    FileOperationStatus upload_audio(const std::string& local_path);

    /**
     * @brief Upload a local audio file into the speaker's directory, with
     *        a per-chunk progress callback.
     * @param local_path Full local path, e.g. "./audio/test.wav"
     * @param progress_cb Progress callback. Called on every chunk from an
     *                    internal thread; do NOT call other
     *                    SpeakerInterface methods from inside.
     * @return FileOperationStatus.
     */
    FileOperationStatus upload_audio_with_cb(const std::string& local_path,
                                             std::function<void(const TransferProgress&)> progress_cb);

    /**
     * @brief Download an audio file from the speaker's  directory.
     * @param remote_filename Filename in  to download.
     * @param local_path Local path to save the file.
     * @return FileOperationStatus.
     *
     * If you want progress delivered to a callback, use download_audio_with_cb().
     */
    FileOperationStatus download_audio(const std::string& remote_filename, const std::string& local_path);

    /**
     * @brief Download an audio file from the speaker's  directory, with
     *        a per-chunk progress callback.
     * @param remote_filename Filename in  to download.
     * @param local_path Local path to save the file.
     * @param progress_cb Progress callback. See upload_audio_with_cb().
     * @return FileOperationStatus.
     */
    FileOperationStatus download_audio_with_cb(const std::string& remote_filename,
                                               const std::string& local_path,
                                               std::function<void(const TransferProgress&)> progress_cb);

    /**
     * @brief List audio files in the speaker's  directory.
     * @param[out] out  Populated with directory entries on success.
     * @return FileOperationStatus.
     */
    FileOperationStatus list_audio(FileList& out);

    /**
     * @brief Rename an audio file on the speaker.
     * @param old_name Current filename.
     * @param new_name New filename.
     * @return FileOperationStatus.
     *
     * The SDK does NOT pre-check whether the target filename already
     * exists. If the target exists, behavior depends on the device
     * firmware: some override, some return `Code::FileExists`. Callers
     * that need a strict "no overwrite" semantic should pre-check via
     * list_audio() and decide themselves.
     */
    FileOperationStatus rename_audio(const std::string& old_name, const std::string& new_name);

    /**
     * @brief Delete an audio file from the speaker.
     * @param filename Filename to delete.
     * @return FileOperationStatus.
     */
    FileOperationStatus delete_audio(const std::string& filename);

    /**
     * @brief Subscribe to audio info updates for a given file.
     * @param filename The audio file name to query.
     * @param callback Called each time audio info is received.
     * @return Opaque handle for unsubscribe_audio_info().
     */
    using AudioInfoHandle = int;
    AudioInfoHandle subscribe_audio_info(const std::string& filename,
                                         std::function<void(const AudioFileInfo&)> callback);

    /**
     * @brief Unsubscribe from audio info updates.
     * @param handle Handle returned by subscribe_audio_info().
     */
    void unsubscribe_audio_info(AudioInfoHandle handle);

    // ==================== Firmware Update ====================

    /**
     * @brief Upload firmware and restart the speaker.
     * @param firmware_local_path Local path to the firmware file.
     * @return true if upload succeeded and restart was issued.
     *
     * If you want progress delivered to a callback, use upload_firmware_with_cb().
     */
    FileOperationStatus upload_firmware(const std::string& firmware_local_path);

    /**
     * @brief Upload firmware and restart the speaker, with a per-chunk
     *        progress callback.
     * @param firmware_local_path Local path to the firmware file.
     * @param progress_cb Progress callback. See upload_audio_with_cb().
     * @return FileOperationStatus.
     */
    FileOperationStatus upload_firmware_with_cb(const std::string& firmware_local_path,
                                                std::function<void(const TransferProgress&)> progress_cb);

    // ==================== Playback Control ====================

    /**
     * @brief Play an audio file once by index, get the index from the subscribe_audio_info
     * @param index 0-based index in the media list.
     * @return true on success.
     */
    bool play(int index);

    /**
     * @brief Play an audio file in loop mode by index.
     * @param index 0-based index in the media list.
     * @return true on success.
     */
    bool loop_play(int index);

    /** @brief Stop the current playback. @return true on success. */
    bool stop();

    // ==================== Status ====================

    /**
     * @brief Get the current speaker status (blocking).
     * @param[out] out  Populated with the latest status on success.
     * @return true if status was retrieved.
     */
    bool get_status(SpeakerStatus& out);

    /**
     * @brief Subscribe to continuous speaker status updates.
     * @param callback  Called each time a new status is received.
     *
     * Replaces any previous subscription.
     */
    void subscribe_status(std::function<void(const SpeakerStatus&)> callback);

    // ==================== Real-Time Voice ====================

    /**
     * @brief Start real-time listening (speaker captures audio and streams to GCS).
     *
     * Before calling this, ensure SPK_LAN_IP param is set to the GCS IP by set_param_custom("SPK_LAN_IP", "ip of gcs")
     * so the speaker knows where to push the audio stream.
     * @return true on success.
     */
    bool start_listen();

    /** @brief Stop real-time listening. @return true on success. */
    bool stop_listen();

    /**
     * @brief Start real-time speaking (GCS pushes audio stream to speaker).
     *
     * Before calling this, start your audio stream sender (e.g. ffmpeg), otherwise, real-time speaking may fail.
     * @return true on success.
     */
    bool start_speak();

    /** @brief Stop real-time speaking. @return true on success. */
    bool stop_speak();

    // ==================== Volume & Angle ====================

    /**
     * @brief Set speaker volume.
     * @param volume_percent 0.0 ~ 100.0
     * @return true on success.
     */
    bool set_volume(float volume_percent);

    /**
     * @brief Set speaker gimbal angle, only use pitch angle (H600L only).
     * @return true on success.
     */
    bool set_angle(float roll, float pitch, float yaw);

    // ==================== Light Control ====================

    /**
     * @brief Set the built-in light mode.
     * @param mode Light mode index from 0 to 4.
     * @return true on success.
     */
    bool set_light_mode(int mode);

    /**
     * @brief Turn the built-in light on or off.
     * @param on true = on, false = off.
     * @return true on success.
     */
    bool set_light_on_off(bool on);

    /**
     * @brief Turn the external light on or off (S600L only).
     * @param on true = on, false = off.
     * @return true on success.
     */
    bool set_external_light_on_off(bool on);

    /**
     * @brief Get the external light on/off status (S600L only).
     * @param[out] on true = on, false = off.
     * @return true if status was retrieved.
     */
    bool get_external_light_status(bool& on);

    /**
     * @brief Subscribe to external light on/off status changes (S600L only).
     * @param callback Called with true (on) or false (off).
     */
    void subscribe_external_light_status(std::function<void(bool on)> callback);

    // ==================== Camera (S600L only) ====================

    /** @brief Take a photo. @return true on success. */
    bool take_picture();

    /** @brief Start video recording. @return true on success. */
    bool start_video();

    /** @brief Stop video recording. @return true on success. */
    bool stop_video();

    /**
     * @brief Switch camera lens.
     * @param lens_id 0 or 1.
     * @return true on success.
     */
    bool switch_lens(int lens_id);

    /** @brief Camera network parameters structure */
    struct CameraNetworkParams {
        std::string ip_address;  // e.g., "192.168.144.67"
        int bitrate;             // 0=Default, 1=0.5M, 2=1M, 3=2M, 4=3M, 5=4M, 6=0.1M, 7=0.2M
        int resolution;          // 0=Default, 1=1080p, 2=720p, 3=576p
        int encoding;            // 0=Default, 1=H264, 2=H265
    };

    /**
     * @brief Get camera network parameters.
     * @param[out] out Populated with network params on success.
     * @return true on success.
     */
    bool get_camera_network_params(CameraNetworkParams& out);

    /**
     * @brief Set camera network parameters.
     * @param params Network parameters to set.
     * @return true on success.
     */
    bool set_camera_network_params(const CameraNetworkParams& params);

    // ==================== Device Info & Parameters ====================

    /**
     * @brief Get speaker hardware/firmware information.
     * @param[out] out  Populated with device info on success.
     * @return true if info was retrieved.
     *
     * Note: this subscribes to a one-shot information update and blocks briefly.
     */
    bool get_information(DeviceInfo& out);

    /**
     * @brief Get storage capacity information.
     * @param[out] out  Populated with storage info on success.
     * @return true if info was retrieved.
     */
    bool get_storage(StorageInfo& out);

    /** @brief Format speaker storage (deletes all content!). @return true on success. */
    bool format_storage();

    /** @brief Restart the speaker. @return true on success. */
    bool restart();

    /**
     * @brief Set a device parameter.
     * @param name  Parameter name, e.g. "SPK_LAN_IP".
     * @param value Parameter value as string. Numeric strings are auto-detected
     *              and sent as int/float; otherwise sent as custom string param.
     * @return true on success.
     *
     * Example: set_param("SPK_LAN_IP", "192.168.144.20")
     */
    bool set_param(const std::string& name, const std::string& value);

    /**
     * @brief Get a device parameter value.
     * @param name       Parameter name.
     * @param[out] out   Populated with the parameter value on success.
     * @return true if the parameter was found.
     */
    bool get_param(const std::string& name, ParamValue& out);

    /**
     * @brief Get all device parameters.
     * @param[out] out   Populated with all parameters on success.
     * @return true on success (even if the list is empty).
     */
    bool get_all_params(std::vector<ParamValue>& out);

    /** @brief Set an integer parameter. @return true on success. */
    bool set_param_int(const std::string& name, int value);

    /** @brief Set a float parameter. @return true on success. */
    bool set_param_float(const std::string& name, float value);

    /** @brief Set a custom string parameter. @return true on success. */
    bool set_param_custom(const std::string& name, const std::string& value);

    /** @brief Get an integer parameter. @return true on success. */
    bool get_param_int(const std::string& name, int& out);

    /** @brief Get a float parameter. @return true on success. */
    bool get_param_float(const std::string& name, float& out);

    /** @brief Get a custom string parameter. @return true on success. */
    bool get_param_custom(const std::string& name, std::string& out);

    // ==================== Log ====================

    /**
     * @brief Subscribe to log information from the speaker.
     * @param callback Called for each log message.
     * @return Opaque handle for unsubscribe_log_information().
     */
    using LogHandle = int;
    LogHandle subscribe_log_information(std::function<void(const LogInformation&)> callback);

    /**
     * @brief Unsubscribe from log information.
     * @param handle Handle returned by subscribe_log_information().
     */
    void unsubscribe_log_information(LogHandle handle);

private:
    struct Impl;
    std::unique_ptr<Impl> _impl;
};
