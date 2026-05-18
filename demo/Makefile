TARGET := S600L_client
BUILD_DIR := build

CXX ?= g++
CXXFLAGS ?= -O2 -g -std=c++17 -Wall -Wextra

SDK_ROOT := $(abspath $(CURDIR)/../sdk)
SDK_INC := $(SDK_ROOT)/include
SDK_VERSION ?= 20.04
SDK_LIB := $(SDK_ROOT)/lib/linux/x86/$(SDK_VERSION)

SRCS := main.cpp speaker_utils.cpp
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

CPPFLAGS += -I. -I$(SDK_INC)
LDFLAGS += -L$(SDK_LIB) -Wl,-rpath,'$$ORIGIN'

LDLIBS += -lspeaker_interface -lpthread -ldl

.PHONY: all clean copy print run

all: $(TARGET)

$(TARGET): $(OBJS) copy
	$(CXX) $(CXXFLAGS) $< build/speaker_utils.o $(LDFLAGS) $(LDLIBS) -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

copy:
	@mkdir -p $(BUILD_DIR)
	cp -u $(SDK_LIB)/libspeaker_interface.so $(BUILD_DIR)/

clean:
	rm -rf $(BUILD_DIR)

print:
	@echo "SDK_ROOT=$(SDK_ROOT)"
	@echo "SDK_INC=$(SDK_INC)"
	@echo "SDK_LIB=$(SDK_LIB)"

IP := 192.168.144.67
run: copy
	./build/S600L_client $(IP) 14556
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
