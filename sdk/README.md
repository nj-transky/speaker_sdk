# 准备
+ **请首先查阅喊话器用户查看喊话器工作环境和工作电压等参数**
+ **喊话器出厂默认IP为`192.168.144.67`,如自行修改，请在接下来的操作中使用相应的IP**
+ 确保电脑和喊话器在同一局域网下
  + 可通过`ping 192.168.144.67`查看是否在同一局域网
# API 使用
参看 `API_DOC.md`

连接 H600L 时，必须在 `init()` 前指定型号；S600L 为兼容旧程序仍是默认值：

```cpp
SpeakerInterface speaker;
if (!speaker.set_model(SpeakerInterface::DeviceModel::H600L) ||
    !speaker.init("192.168.144.67", 14556)) {
    // 处理初始化失败
}

// 使用结束后主动关闭 MAVSDK 和 FTP 连接
speaker.deinit();
```

`deinit()` 可重复调用；同一个对象在 `deinit()` 后可以重新选择型号并再次
`init()`。析构函数也会执行清理，但建议在不再使用连接时显式调用。

交互式 demo 会在 `init()` 前注册掉线回调。设备心跳超时后，回调只投递事件，
由独立生命周期线程执行 `deinit()`，从而停止状态请求重试且避免在 SDK 回调中
自锁。输入 `connection` 可查看 当前连接状态。demo 采用掉线后关闭
连接的 fail-fast 策略，不会自动等待设备重新连接。

# 编译和运行
```bash
# 编译
cd demo
# Linux
make OS=linux ARCH=x86 SDK_VERSION=22.04
# Win
make
# demo 运行时必须明确指定型号
# 运行 S600L
make MODEL=s600l run
# 运行 H600L
make MODEL=h600l run

# 也可直接运行，--model 不可省略
./build/S600L_client --model s600l 192.168.144.67 14556
./build/S600L_client --model h600l 192.168.144.67 14556
```

# 喊话功能
该喊话器包含实时喊话，录音喊话和文字转语音功能
## 实时喊话
实时喊话需要地面站**先推送实时的音频流，再通过喊话器API开启喊话器端拉流操作**(顺序很重要)。
喊话器会尝试拉流，如果尝试5次无法拉到音频流，将停止拉流，因此建议先推送音频流再使用API开启喊话器的拉流服务
操作如下
1. 在demo下运行`make push`
```bash
ffmpeg -re -i ./audio/audio.wav \
    -vn -acodec aac  \
    -ar 16000 -ac 2 \
    -f rtp -payload_type 97 \
    -sdp_file client_audio.sdp \
    rtp://192.168.144.67:15557

```
2. 在speaker命令行控制中执行`speak start`
![realtime_speaking](demo/audio/realtime_speaking.gif)
## 录音喊话
该功能需要地面站录制音频，然后将音频通过api上传到，然后播放
## 文字转语音
该功能也需要地面站完成文字转语音的功能， 然后将音频上传到喊话器中，然后播放
# 实时监听
同样的，实时监听需要先调用API，**先开启喊话器端的推流，然后地面站拉流**(顺序很重要)
而且实时监听需要通过配置`SPK_LAN_IP`这个参数的值为地面站IP，例如在demo中通过`config set SPK_LAN_IP 192.168.144.12`，这样地面站才可以成功拉流
```bash
ffplay \
-nodisp \
-autoexit \
-protocol_whitelist file,udp,rtp \
-i ./audio/server_audio.sdp
```
![realtime_listening](demo/audio/realtime_listening.gif)

# 前后双摄
相机出厂默认IP为`192.168.144.19`
拉流地址为 `rtsp://192.168.144.19/554`

在demo下运行`make camera`即可拉流
