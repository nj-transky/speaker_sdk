# Speaker MAVSDK Client SDK — 更新日志

## [1.5.1] - 2026-08-10
### 修复
- 修复 Windows 上传音频或固件后无法list的问题

## [1.5.0] - 2026-07-26
### 新增
- 新增 `DeviceModel`、`set_model()` 和 `get_model()`，可在运行时选择 S600L 或 H600L
- demo 启动时强制要求 `--model <s600l|h600l>`，并支持通过 `make MODEL=<型号> run` 启动

### 修复
- H600L 调用 S600L 专属的外置探照灯、拍照、录像、镜头切换和相机网络参数 API 时立即返回失败，不再向设备发送无效命令

### 改变
- 为兼容旧调用方，未调用 `set_model()` 时仍默认使用 S600L
- demo 不使用 SDK 的兼容默认值；省略型号或传入未知型号时会在联网前退出
- `set_model()` 必须在 `init()` 前调用；初始化开始后修改型号会返回 `false`
- 非 MSVC 构建启用 `-Wundef`，防止未定义的设备型号宏在预处理条件中被静默当作 `0`

## [1.4.0] - 2026-07-24

### 新增
- 添加 Windows 平台支持
- 新增 `DeviceModel`、`set_model()` 和 `get_model()`，可在运行时选择 S600L 或 H600L
- demo 启动时强制要求 `--model <s600l|h600l>`，并支持通过 `make MODEL=<型号> run` 启动

### 修复
- H600L 初始化时不再订阅其固件未实现的外置探照灯状态，避免持续发送 `MAV_CMD_LIGHT_REQUEST_STATUS (50504)` 并重试超时
- H600L 调用 S600L 专属的外置探照灯、拍照、录像、镜头切换和相机网络参数 API 时立即返回失败，不再向设备发送无效命令
- 外置探照灯状态回调和缓存增加线程同步，并在 SDK 析构时释放订阅句柄
- 修复相机网络参数查询超时后异步回调可能访问已销毁局部对象的问题

### 改变
- 为兼容旧调用方，未调用 `set_model()` 时仍默认使用 S600L
- demo 不使用 SDK 的兼容默认值；省略型号或传入未知型号时会在联网前退出
- `set_model()` 必须在 `init()` 前调用；初始化开始后修改型号会返回 `false`
- 非 MSVC 构建启用 `-Wundef`，防止未定义的设备型号宏在预处理条件中被静默当作 `0`

## [1.3.0] - 2026-06-24

### 新增
- 文件传输进度回调：`upload_audio_with_cb` / `download_audio_with_cb` / `upload_firmware_with_cb`，配合 `TransferProgress` 结构体
- `FileOperationStatus` 枚举
- `SdkLogLevel` 枚举
- `set_sdk_log_level` / `set_sdk_log_callback`（SDK 内部日志路由）
- `sdk_version()` 静态方法
- `API_DOC.md` 重写并恢复为发布产物

### 改变
- **Breaking**: `upload_audio` / `download_audio` / `upload_firmware` / `list_audio` / `rename_audio` / `delete_audio` 返回类型从 `bool` 改为 `FileOperationStatus`（调用方需将 `if (r)` 改为与 `FileOperationStatus::Success` 显式比较）
- `set_verbose` 改为 `set_sdk_log_level` 的便捷封装（不再自动挂 stderr 回调）

### 移除
- 之前为兼容 ABI 引入的"带 `progress_cb = nullptr` 默认参数"的 `_with_cb` 重载（重复功能已由独立的 `*_with_cb` 方法覆盖）
