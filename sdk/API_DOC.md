# Speaker Interface SDK API 调用文档

## 初始化流程

```cpp
#include "speaker_interface.h"

SpeakerInterface speaker;
speaker.set_verbose(true);  // 启用调试输出

// 连接设备
if (!speaker.init("192.168.144.67", 14556)) {
    // 连接失败处理
}
```

---

## 音频文件操作

| API | 说明 |
|-----|------|
| `upload_audio(local_path)` | 上传音频文件到喊话器 |
| `list_audio(FileList& out)` | 列出喊话器的音频文件 |
| `rename_audio(old_name, new_name)` | 重命名音频文件 |
| `delete_audio(filename)` | 删除音频文件 |
| `subscribe_audio_info(filename, callback)` | 订阅音频文件信息，获取 index |

---

## 播放控制

**重要**：播放前必须先调用 `subscribe_audio_info` 获取音频文件的 index：

```cpp
// 1. 订阅音频信息，获取 index
uint32_t audio_index = 0;
speaker.subscribe_audio_info("audio.wav", [&](const SpeakerInterface::AudioFileInfo& info) {
    audio_index = info.index;
    printf("Audio index: %u, format: %s, length: %.1fs\n",
           info.index, info.format.c_str(), info.length_seconds);
});

// 2. 根据 index 播放
speaker.play(audio_index);      // 播放一次
speaker.loop_play(audio_index); // 循环播放

// 3. 停止
speaker.stop();
```

---

## 实时语音（喊话和监听, 喊话器 <-> 地面站(GCS)）
### 实时喊话（GCS -> speaker）

GCS 推送音频流到 speaker：

```cpp
// 1. 使用 ffmpeg等工具推送音频到 speaker 的 15557 端口
推流命令可参考README.md
// 2. 喊话器开始拉流
speaker.start_speak();

// 3. 停止拉流
speaker.stop_speak();

// 4. GCS停止推流
```


### 实时监听（speaker -> GCS）

speaker 采集音频并推送到地面站：

```cpp
// 1. 先设置 GCS 的 IP 地址（speaker 会把音频推送到这个地址）
speaker.set_param("SPK_LAN_IP", "192.168.144.20");

// 2. 启动推流
speaker.start_listen();

// 3. GCS 端监听 UDP 端口接收音频流
拉流命令可参考 README.md
```


---

## 音量与角度

| API | 说明 |
|-----|------|
| `set_volume(0~100)` | 设置音量 |
| `set_angle(roll, pitch, yaw)` | 设置角度（H600L 专用）|

---

## 灯光控制

| API | 说明 |
|-----|------|
| `set_light_mode(0~4)` | 设置灯光模式 |
| `set_light_on_off(true/false)` | 开关内置灯光 |
| `set_external_light_on_off(true/false)` | 开关探照灯（S600L 专用）|

---

## 摄像头（S600L 专用）

| API | 说明 |
|-----|------|
| `take_picture()` | 拍照 |
| `start_video()` | 开始录像 |
| `stop_video()` | 停止录像 |
| `switch_lens(0/1)` | 切换镜头 |
| `get_camera_network_params(params)` | 获取摄像头网络参数 |
| `set_camera_network_params(params)` | 设置摄像头网络参数 |

---

## 设备信息与参数

| API | 说明 |
|-----|------|
| `get_information(DeviceInfo& out)` | 获取设备信息 |
| `get_storage(StorageInfo& out)` | 获取存储容量 |
| `restart()` | 重启设备 |
| `set_param(name, value)` | 设置参数 |
| `get_param(name, ParamValue& out)` | 获取参数 |
| `get_all_params(vector<ParamValue>& out)` | 获取所有参数 |

---


## CLI命令参考
```
  upload <local_file>               - Upload audio file into speaker
  upload_fw <firmware_path>          - Upload firmware and restart
  list                              - List audio files
  rename <old_name> <new_name>      - Rename audio file
  delete <filename>                 - Delete audio file
  sub <filename>                    - Subscribe to audio info
  play <index>                      - Play audio once
  loop <index>                      - Loop-play audio
  stop                              - Stop playback
  listen <start|stop>               - Real-time listen
  speak <start|stop>                - Real-time speak
  volume <0-100>                    - Set volume
  angle <roll> <pitch> <yaw>        - Set angle (H600L)
  light_mode <mode>                 - Set light mode(0-4)
  light <on|off>                    - Light on/off
  ex_light <on|off>                 - External light (S600L)
  take_picture                      - Take photo (S600L)
  start_video                       - Start recording (S600L)
  stop_video                        - Stop recording (S600L)
  switch_lens <0|1>                 - Switch lens (S600L)
  camera_get                - Get camera network params (S600L)
  camera_set <ip> <bitrate> <resolution> <encoding>
                                    - Set camera network params (S600L)
                                      bitrate: 0-7, resolution: 0-3, encoding: 0-2
  information                       - Device info
  storage                           - Storage info
  restart                           - Restart speaker
  config set <name> <value>         - Set parameter
  config get <name>                 - Get parameter
  config list                       - List all parameters
  help                              - Show this help
  exit                              - Quit
```
