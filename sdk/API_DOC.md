# Speaker Interface SDK API 文档

---

## 1. 快速开始

### 1.1 SDK 版本号

```cpp
#include "speaker_interface.h"
#include <cstdio>

int main() {
    std::printf("Speaker SDK %s\n", SpeakerInterface::sdk_version());
}
```

### 1.2 最简示例

最小可运行示例：连接设备，上传音频，断开。

```cpp
#include "speaker_interface.h"
#include <iostream>

int main() {
    SpeakerInterface speaker;
    // H600L 必须在 init() 前调用；S600L 可省略，默认即为 S600L。
    // speaker.set_model(SpeakerInterface::DeviceModel::H600L);
    speaker.set_verbose(true);

    // 连接设备
    if (!speaker.init("192.168.144.67", 14556)) {
        std::cerr << "Init failed" << std::endl;
        speaker.deinit(); // 初始化失败后调用也是安全的
        return 1;
    }

    // 上传音频（无进度回调，进度打到 stderr）
    auto status = speaker.upload_audio("./audio/test.wav");
    if (status != SpeakerInterface::FileOperationStatus::Success) {
        std::cerr << "Upload failed (status=" << static_cast<int>(status) << ")" << std::endl;
        speaker.deinit();
        return 1;
    }

    // 主动关闭 MAVSDK 和 FTP 连接
    speaker.deinit();
    std::cout << "Done" << std::endl;
    return 0;
}
```

---

## 2. 初始化与连接

### 2.1 选择设备型号

SDK 同时支持 S600L 和 H600L。默认型号是 `DeviceModel::S600L`；连接 H600L 时必须在 `init()` 前选择型号：

```cpp
SpeakerInterface speaker;
if (!speaker.set_model(SpeakerInterface::DeviceModel::H600L)) {
    std::cerr << "Set model failed" << std::endl;
    return 1;
}
speaker.init("192.168.144.67", 14556);
```

`set_model()` 在初始化开始后会返回 `false`，当前选择可通过
`get_model()` 查询。

| 功能 | S600L | H600L |
|-----|:-----:|:-----:|
| 喊话、音频、文件、状态、日志、参数 | 支持 | 支持 |
| 内置爆闪灯 | 支持 | 支持 |
| 角度控制 | 不支持 | 支持 |
| 外置探照灯 | 支持 | 不支持 |
| 拍照、录像、镜头与相机网络参数 | 支持 | 不支持 |

在 H600L 模式调用 S600L 专属 API 时，返回 `bool` 的方法会立即返回
`false`；

### 2.2 通过 IP + 端口连接


```cpp
speaker.init("192.168.144.67", 14556);
```

### 2.3 状态查询

```cpp
if (speaker.is_connected()) { /* ... */ }
if (speaker.is_ftp_available()) { /* 可以做文件操作 */ }
```

### 2.4 主动反初始化与重新初始化

```cpp
speaker.deinit();
```

`deinit()` 是 `init()` 的同步、可重复调用的反向操作：它会等待当前正在执行的
阻塞式 SDK 操作和已经进入的会话回调结束，然后关闭连接。
初始化前调用或连续调用多次都不会产生副作用。析构函数也会执行相同清理，
但建议在不再使用连接时显式调用。

主动 `deinit()` 不会触发异常断线回调。调用完成后：

- `is_connected()` 和 `is_ftp_available()` 返回 `false`；
- 命令、参数、相机等 `bool` 接口返回 `false`；
- 文件接口返回 `FileOperationStatus::NoSystem`；
- 查询失败时不会修改调用方传入的输出参数。

同一个对象可以重新使用，型号、日志配置以及尚未取消的音频信息/设备日志
订阅会保留；设备状态缓存和底层订阅句柄则会为新连接重新建立：

```cpp
speaker.deinit();
speaker.set_model(SpeakerInterface::DeviceModel::H600L); // 可选
if (!speaker.init("192.168.144.67", 14556)) {
    // 处理重新初始化失败
}
```

`deinit()` 不能从 SDK 的状态、日志、断线或传输进度回调中调用，否则会等待
当前回调所属操作而造成死锁。请通知业务线程，由业务线程执行反初始化。

### 2.5 连接断开回调

```cpp
speaker.subscribe_on_disconnect([]() {
    std::cerr << "device disconnected!" << std::endl;
});
```

该回调只表示已连接设备发生了非预期链路断开；调用方主动执行 `deinit()` 时
不会触发。回调运行在 SDK 内部线程，不要在回调中调用本 SDK 的其他方法。


---

## 3. 日志系统

SDK 内部日志分**两套**，互不相关：

| 系统 | 来源 | 公共 API | 类型 |
|-----|------|---------|------|
| 设备发过来的日志 | 设备端（speaker）上报 | `subscribe_log_information(cb)` + handle | `LogInformation { text; LogLevel log_level; }` |
| SDK 内部日志 | SDK 库自己 | `set_sdk_log_callback(cb)` 一次性 hook | `SdkLogLevel + string` |

### 3.1 SDK 内部日志级别

```cpp
enum class SdkLogLevel {
    Debug,   // 内部细节（chunk 进度、原始 result code）
    Info,    // 操作启动 / 成功
    Warning, // 警告
    Error    // 操作失败
};
```

### 3.2 设置日志级别

```cpp
// 便捷方法：把所有级别日志（包括 Debug）都打开
speaker.set_verbose(true);

// 精细控制
speaker.set_sdk_log_level(SpeakerInterface::SdkLogLevel::Info);
```

`set_verbose(true)` 等价于 `set_sdk_log_level(SdkLogLevel::Debug)`。

### 3.3 接收 SDK 内部日志

```cpp
speaker.set_sdk_log_callback(
    [](SpeakerInterface::SdkLogLevel level, const std::string& message) {
        std::cerr << "[sdk] [" << sdk_log_level_to_string(level) << "] " << message << std::endl;
    });
```

回调在 SDK 内部线程触发，**不要**调本 SDK 的其他方法。

如果不挂 callback，**只有 Error 级别**会兜底打到 stderr；其他级别静默。

### 3.4 接收设备日志（与 SDK 内部日志无关）

```cpp
auto handle = speaker.subscribe_log_information(
    [](const SpeakerInterface::LogInformation& log) {
        std::cout << "[" << log_level_to_string(log.log_level) << "] " << log.text << std::endl;
    });

// 取消订阅
speaker.unsubscribe_log_information(handle);
```

---

## 4. 文件操作

### 4.1 文件传输进度结构体

带回调的传输 API 通过 `TransferProgress` 报告进度：

```cpp
struct TransferProgress {
    uint32_t bytes_transferred;  // 已传输字节
    uint32_t total_bytes;        // 总字节
    int percentage;              // 0~100
};
```

### 4.2 上传音频

```cpp
// 简单：进度走 stderr
auto s1 = speaker.upload_audio("./audio/test.wav");

// 带进度回调
auto s2 = speaker.upload_audio_with_cb("./audio/test.wav",
    [](const SpeakerInterface::TransferProgress& p) {
        printf("\rUploading %3d%% %u/%u",
               p.percentage, p.bytes_transferred, p.total_bytes);
        if (p.percentage >= 100) printf("\n");
    });
```

回调在内部线程触发，每 chunk 一次，**不要**在回调里调本 SDK 的其他方法。

### 4.3 下载音频

```cpp
// 简单
auto s = speaker.download_audio("audio.wav", "./audio.wav");

// 带进度回调
speaker.download_audio_with_cb("audio.wav", "./audio.wav",
    [](const SpeakerInterface::TransferProgress& p) {
        printf("\rDownloading %3d%%\n", p.percentage);
    });
```

### 4.4 上传固件

```cpp
speaker.upload_firmware("./firmware_v1.0.bin");
// 上传成功后会重启设备

// 带进度回调
speaker.upload_firmware_with_cb("./firmware_v1.0.bin",
    [](const SpeakerInterface::TransferProgress& p) {
        printf("FW upload: %d%%\n", p.percentage);
    });
```

### 4.5 列出音频文件

```cpp
SpeakerInterface::FileList files;
auto status = speaker.list_audio(files);
if (status == SpeakerInterface::FileOperationStatus::Success) {
    for (const auto& d : files.dirs)  std::cout << "[DIR] " << d << "\n";
    for (const auto& f : files.files) std::cout << "       " << f << "\n";
}
```

### 4.6 重命名音频

```cpp
auto status = speaker.rename_audio("old.wav", "new.wav");
```

**注意**：SDK **不**预检目标文件名是否已存在，而是直接尝试重命名
如果需要"严格不覆盖"语义，调用方自己用 `list_audio` 预检：

```cpp
SpeakerInterface::FileList files;
if (speaker.list_audio(files) == SpeakerInterface::FileOperationStatus::Success) {
    bool exists = std::find(files.files.begin(), files.files.end(), "new.wav")
                  != files.files.end();
    if (exists) {
        std::cerr << "target exists, aborting\n";
    } else {
        speaker.rename_audio("old.wav", "new.wav");
    }
}
```

### 4.7 删除音频

```cpp
auto status = speaker.delete_audio("audio.wav");
```

### 4.8 错误码：FileOperationStatus

所有文件操作返回 `FileOperationStatus`（10 个值）：

| 值 | 含义 | 典型场景 |
|----|------|---------|
| `Success` | 操作成功 | 正常完成 |
| `Timeout` | 超时 | 网络差、ack 丢失 |
| `FileIoError` | 文件 I/O 错误 | 磁盘满、I/O 错误 |
| `FileExists` | 目标已存在 | 重命名撞名（设备拒绝覆盖） |
| `FileDoesNotExist` | 源文件不存在 | 删 / 下载 / 重命名时源不在 |
| `FileProtected` | 文件写保护 | 固件区 |
| `InvalidParameter` | 参数非法 | 路径为空 |
| `NoSystem` | SDK 未连接 | 设备断连 |
| `Unknown` | 未知结果 | ftp 协议内部错误 |
| `Failed` | 其它失败 | 笼统兜底 |


调用方拿到 status 后可以自己 switch 出本地化消息：

```cpp
const char* desc(SpeakerInterface::FileOperationStatus s) {
    switch (s) {
        case SpeakerInterface::FileOperationStatus::Success:           return "OK";
        case SpeakerInterface::FileOperationStatus::Timeout:           return "超时";
        case SpeakerInterface::FileOperationStatus::FileExists:        return "目标已存在";
        case SpeakerInterface::FileOperationStatus::FileDoesNotExist: return "源不存在";
        case SpeakerInterface::FileOperationStatus::NoSystem:         return "未连接";
        default:                                                       return "失败";
    }
}
```

---

## 5. 播放控制

播放前需要先订阅音频信息获取 `index`。`subscribe_audio_info` 是**异步**的，回调从内部线程触发，调用方必须**等待回调完成**再调 `play`，否则 `audio_index` 仍是旧值甚至 0。

```cpp
#include <thread>
#include <chrono>

// 先确保文件已上传
speaker.upload_audio("./audio/audio.wav");

// 1. 订阅获取 index
uint32_t audio_index = 0;
bool callback_received = false;
speaker.subscribe_audio_info("audio.wav",
    [&](const SpeakerInterface::AudioFileInfo& info) {
        audio_index = info.index;
        callback_received = true;
        printf("Audio index: %u, format: %s, length: %.1fs\n",
               info.index, info.format.c_str(), info.length_seconds);
    });

// 2. 等待回调完成（最多 5 秒）
const int timeout_ms = 5000;
int elapsed = 0;
while (!callback_received && elapsed < timeout_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    elapsed += 100;
}

if (!callback_received) {
    std::cerr << "Timeout waiting for audio info" << std::endl;
    return 1;
}

// 3. 用拿到的 index 播放
speaker.play(audio_index);       // 单次播放
speaker.loop_play(audio_index);  // 循环播放
speaker.stop();                  // 停止
```

取消订阅：
```cpp
int handle = speaker.subscribe_audio_info("...", [](...){});
// ...
speaker.unsubscribe_audio_info(handle);
```

---

## 6. 实时语音

API 调用顺序与 ffmpeg / ffplay 命令详见发布版 `README.md`。本节只列 C++ 端 API。

### 6.1 实时喊话（GCS → speaker）

```cpp
speaker.start_speak();   // speaker 开始拉流
speaker.stop_speak();    // speaker 停止拉流
```

### 6.2 实时监听（speaker → GCS）

**必须先**设置 `SPK_LAN_IP` 为 GCS 的 IP（通过 `set_param_custom`，见 §10）：

```cpp
speaker.set_param_custom("SPK_LAN_IP", "192.168.144.20"); // IP 替换为地面站实际的IP
speaker.start_listen();   // speaker 开始推流到 GCS
speaker.stop_listen();    // 停止推流
```

---

## 7. 音量与角度

```cpp
speaker.set_volume(75.0f);     // 0.0~100.0
speaker.set_angle(0.0f, 10.0f, 0.0f);  // H600L 专用：roll, pitch, yaw,只有pitch参数有效
```

---

## 8. 灯光

### 8.1 爆闪灯

```cpp
speaker.set_light_mode(1);  // 0~4
speaker.set_light_on_off(true);
```

### 8.2 探照灯（S600L 专用）

只有在型号为 S600L 时，SDK 才会在初始化阶段订阅探照灯状态。

```cpp
// 开关
speaker.set_external_light_on_off(true);

// 读取当前状态
bool on = false;
speaker.get_external_light_status(on);

// 订阅状态变化
speaker.subscribe_external_light_status(
    [](bool on) { std::cout << "ext light: " << (on ? "on" : "off") << "\n"; });
```

---

## 9. 摄像头（S600L 专用）

### 9.1 基本操作

```cpp
speaker.take_picture();
speaker.start_video();
speaker.stop_video();
speaker.switch_lens(0);  // 0 or 1
```

### 9.2 网络参数

```cpp
// 读取
SpeakerInterface::CameraNetworkParams params;
speaker.get_camera_network_params(params);
std::cout << "IP: " << params.ip_address << "\n";
std::cout << "bitrate code: " << params.bitrate << "\n";
std::cout << "resolution code: " << params.resolution << "\n";
std::cout << "encoding code: " << params.encoding << "\n";

// 写入
params.ip_address = "192.168.144.67";
params.bitrate = 3;       // 0=Default, 1=0.5M, 2=1M, 3=2M, 4=3M, 5=4M, 6=0.1M, 7=0.2M
params.resolution = 1;    // 0=Default, 1=1080p, 2=720p, 3=576p
params.encoding = 1;      // 0=Default, 1=H264, 2=H265
speaker.set_camera_network_params(params);
```

---

## 10. 设备信息与参数

### 10.1 设备信息

```cpp
SpeakerInterface::DeviceInfo info;
if (speaker.get_information(info)) {
    std::cout << "Vendor:   " << info.vendor_name << "\n"
              << "Model:    " << info.model_name << "\n"
              << "Serial:   " << info.serial_number << "\n"
              << "Firmware: " << info.firmware_version << "\n";
}
```

### 10.2 参数配置

参数读写有 `set_param_int` / `set_param_float` / `set_param_custom`

最常见的参数配置场景是实时监听需要指定 GCS 的 IP：

```cpp
// 启动实时监听前，必须先告诉 speaker GCS 的 IP
speaker.set_param("SPK_LAN_IP", "192.168.144.20");
speaker.start_listen();
```

其它参数（如音量、灯光模式等）使用专门的 API（§7、§8），**不要**用 `set_param` 覆盖。

---

## 11. 错误码参考

### 11.1 FileOperationStatus（文件操作）

见 §4.8。10 个值，命名与 `mavftppro::Ftp::Result` 对齐。

### 11.2 SdkLogLevel（日志）

见 §3.1。4 个值。

### 11.3 设备 LogLevel（`subscribe_log_information` 收到）

```cpp
enum class LogLevel {
    Debug, Info, Warning, Error, Fatal
};
```

5 个值，与设备固件日志级别对应。

### 11.4 其它

`play` / `set_volume` / `set_angle` / `take_picture` / 灯光 / 摄像头等**仍返回 `bool`**。失败时通过 SDK 日志（`set_sdk_log_callback`）查看原因。

---

## 12. 与本 SDK 配套的 demo

发布版 `demo/` 目录下提供完整可运行的交互式 CLI 示例，覆盖本文档所有 API。启动后输入 `help` 可查看 `upload`、`download`、`list`、`rename`、`play` 等全部命令。

为避免连接错误型号，demo 不使用 SDK 的默认型号；每次启动都必须显式传入
`--model s600l` 或 `--model h600l`。缺少或无法识别的型号会在建立网络连接前退出。

```bash
# S600L
./S600L_client --model s600l 192.168.144.67 14556

# H600L
./S600L_client --model h600l 192.168.144.67 14556
```

demo 在初始化前注册 `subscribe_on_disconnect()`。发生非预期掉线时，回调会立即
打印通知并唤醒独立生命周期线程，由该线程调用 `deinit()`；不会在 SDK 回调线程
内直接反初始化。这样可停止断电后的状态请求重试，同时避免回调自锁。可输入
`connection` 查看 MAVSDK 和 FTP 当前状态。
