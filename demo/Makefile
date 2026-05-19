TARGET := S600L_client
BUILD_DIR := build
CMAKE_BUILD_DIR := build-msvc
CMAKE_CONFIG ?= Release
CMAKE_PLATFORM ?= x64

SDK_ROOT := $(abspath $(CURDIR)/../sdk)
SDK_INC := $(SDK_ROOT)/include

# Auto-detect OS
UNAME_S := $(shell uname -s 2>/dev/null)
ifneq (,$(findstring MINGW,$(UNAME_S)))
    DETECTED_OS := win
else ifneq (,$(findstring MSYS,$(UNAME_S)))
    DETECTED_OS := win
else ifneq (,$(findstring CYGWIN,$(UNAME_S)))
    DETECTED_OS := win
else ifneq (,$(findstring WindowsNT,$(UNAME_S)))
    DETECTED_OS := win
else ifeq ($(OS),Windows_NT)
    DETECTED_OS := win
else
    DETECTED_OS := linux
endif

# Auto-detect ARCH
UNAME_M := $(shell uname -m)
ifeq ($(UNAME_M),x86_64)
    DETECTED_ARCH := x86
else ifeq ($(UNAME_M),aarch64)
    DETECTED_ARCH := aarch64
else
    DETECTED_ARCH := x86
endif

# Allow override
SDK_OS ?= $(DETECTED_OS)
SDK_ARCH ?= $(DETECTED_ARCH)

# SDK_VERSION: required for linux/x86, optional for others
ifeq ($(SDK_OS),linux)
    ifeq ($(SDK_ARCH),x86)
        ifndef SDK_VERSION
            ifneq ($(MAKECMDGOALS),clean)
                $(error SDK_VERSION must be set for linux/x86, e.g. make SDK_VERSION=24.04)
            endif
            SDK_VERSION := 24.04
        endif
        SDK_LIB := $(SDK_ROOT)/lib/$(SDK_OS)/$(SDK_ARCH)/$(SDK_VERSION)
    else
        SDK_LIB := $(SDK_ROOT)/lib/$(SDK_OS)/$(SDK_ARCH)
    endif
else
    SDK_LIB := $(SDK_ROOT)/lib/$(SDK_OS)/$(SDK_ARCH)
endif

SRCS := main.cpp speaker_utils.cpp
CXX ?= g++
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

# OS determines lib path and file extension
ifeq ($(SDK_OS),win)
    LIB_EXT := .dll
    EXE_EXT := .exe
else
    LIB_EXT := .so
    EXE_EXT :=
endif

CXXFLAGS ?= -O2 -g -std=c++17 -Wall -Wextra
CPPFLAGS += -I. -I$(SDK_INC)
LDFLAGS += -L$(SDK_LIB) -Wl,-rpath,'$$ORIGIN'
LDLIBS += -lspeaker_interface -lpthread -ldl

.PHONY: all clean copy print run

ifeq ($(SDK_OS),win)
all:
	cmake -S . -B $(CMAKE_BUILD_DIR) -A $(CMAKE_PLATFORM)
	cmake --build $(CMAKE_BUILD_DIR) --config $(CMAKE_CONFIG)

run: all
	./$(CMAKE_BUILD_DIR)/$(CMAKE_CONFIG)/$(TARGET)$(EXE_EXT) $(IP) 14556

clean:
	rm -rf $(CMAKE_BUILD_DIR) $(BUILD_DIR)
else
all: $(TARGET)

$(TARGET): $(OBJS) copy
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(BUILD_DIR)/$(TARGET)$(EXE_EXT)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

copy:
	@mkdir -p $(BUILD_DIR)
	@if [ -f $(SDK_LIB)/libspeaker_interface$(LIB_EXT) ]; then \
	    cp -u $(SDK_LIB)/libspeaker_interface$(LIB_EXT) $(BUILD_DIR)/; \
	elif [ -f $(SDK_LIB)/speaker_interface$(LIB_EXT) ]; then \
	    cp -u $(SDK_LIB)/speaker_interface$(LIB_EXT) $(BUILD_DIR)/; \
	fi

clean:
	rm -rf $(BUILD_DIR)
endif

print:
	@echo "SDK_OS=$(SDK_OS)"
	@echo "SDK_ARCH=$(SDK_ARCH)"
	@echo "SDK_VERSION=$(SDK_VERSION)"
	@echo "SDK_ROOT=$(SDK_ROOT)"
	@echo "SDK_INC=$(SDK_INC)"
	@echo "SDK_LIB=$(SDK_LIB)"
	@echo "CMAKE_BUILD_DIR=$(CMAKE_BUILD_DIR)"
	@echo "CMAKE_CONFIG=$(CMAKE_CONFIG)"
	@echo "CMAKE_PLATFORM=$(CMAKE_PLATFORM)"

IP := 192.168.144.67
ifneq ($(SDK_OS),win)
run: copy
	./build/$(TARGET)$(EXE_EXT) $(IP) 14556
endif
push:
	ffmpeg -re -i ./audio/audio.wav \
    -vn -acodec aac  \
    -ar 16000 -ac 2 \
    -f rtp -payload_type 97 \
    -sdp_file client_audio.sdp \
    rtp://$(IP):15557

pull:
	ffplay \
    -nodisp \
    -autoexit \
    -protocol_whitelist file,udp,rtp \
	-i ./audio/server_audio.sdp
CAMERA_IP := 192.168.144.19
camera:
	ffplay rtsp://$(CAMERA_IP)/554
