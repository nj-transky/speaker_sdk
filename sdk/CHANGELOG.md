# Speaker MAVSDK Client SDK — 更新日志
## [1.4.0] - 2026-07-24
### 新增
- 添加对Windows 平台的支持
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
