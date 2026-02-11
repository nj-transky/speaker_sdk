# 描述
本仓库包含喊话器(S600L/H600L)的SDK和client demo，包含了Linux, Windows和Android三个平台的库。
其中，提供了Linux上的demo，因此，Windows和Android上的开发者请参考demo中的代码开发。
# 项目结构
```
.
├── demo
│   ├── build               // 包含编译生成文件
│   ├── main.cpp            // sdk demo
│   ├── Makefile            // 编译脚本
│   └── speaker_interface.h // 主要api文件
├── lib
│   ├── android             // android 平台的sdk lib
│   ├── linux               // linux 平台的sdk lib
│   └── win                 // windows 平台的sdk lib
├── README.md
└── TODO
```
# 运行
具体请参考`./demo` 下的`README`