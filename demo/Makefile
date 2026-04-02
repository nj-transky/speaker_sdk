TARGET := S600L_client
BUILD_DIR := build

CXX ?= g++
CXXFLAGS ?= -O2 -g -std=c++17 -Wall -Wextra

SDK_ROOT := $(abspath $(CURDIR)/../sdk)
SDK_INC := $(SDK_ROOT)/include
SDK_LIB := $(SDK_ROOT)/lib/linux/x86

SRCS := main.cpp speaker_utils.cpp
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

# If your environment provides pkg-config for mavsdk, this will pick up -lmavsdk and its deps.
PKG_CONFIG ?= pkg-config
MAVSDK_CFLAGS ?= $(shell $(PKG_CONFIG) --cflags mavsdk 2>/dev/null)
MAVSDK_LIBS ?= $(shell $(PKG_CONFIG) --libs mavsdk 2>/dev/null)

# Third-party bundle root (optional). Override if your libs live elsewhere.
THIRD_PARTY_ROOT ?= $(abspath $(CURDIR)/../third_party/linux/x86)

# Static libraries shipped with sdk_to_user/third_party (x86).
MAVSDK_A ?= $(THIRD_PARTY_ROOT)/mavsdk/lib/libmavsdk.a
MAVFTP_PRO_A ?= $(THIRD_PARTY_ROOT)/mav_ftp_pro/lib/libmavftp_pro.a
LIBCURL_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/libcurl.a
LIBJSONCPP_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/libjsoncpp.a
LIBTINYXML2_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/libtinyxml2.a
LIBPAHO_C_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/libpaho-mqtt3a.a
LIBPAHO_CPP_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/libpaho-mqttpp3.a
LIBLZMA_A ?= $(THIRD_PARTY_ROOT)/third_party/lib/liblzma.a

CPPFLAGS += -I. -I$(SDK_INC) $(MAVSDK_CFLAGS)
LDFLAGS += -L$(SDK_LIB)

# Link order matters for static libs: dependent libs must come AFTER users.
LDLIBS += $(SDK_LIB)/libspeaker_interface.a
LDLIBS += $(MAVSDK_A) $(MAVFTP_PRO_A)
LDLIBS += $(LIBCURL_A) $(LIBJSONCPP_A) $(LIBTINYXML2_A) $(LIBPAHO_C_A) $(LIBPAHO_CPP_A) $(LIBLZMA_A)
LDLIBS += -lpthread -ldl

.PHONY: all clean print

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(BUILD_DIR)/$@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

print:
	@echo "SDK_ROOT=$(SDK_ROOT)"
	@echo "SDK_INC=$(SDK_INC)"
	@echo "SDK_LIB=$(SDK_LIB)"
	@echo "THIRD_PARTY_ROOT=$(THIRD_PARTY_ROOT)"
	@echo "MAVSDK_LIBDIR=$(MAVSDK_LIBDIR)"
	@echo "MAV_FTP_PRO_LIBDIR=$(MAV_FTP_PRO_LIBDIR)"
	@echo "TP_LIBDIR=$(TP_LIBDIR)"
	@echo "MAVSDK_CFLAGS=$(MAVSDK_CFLAGS)"
	@echo "MAVSDK_LIBS=$(MAVSDK_LIBS)"
	@echo "MAV_FTP_PRO_LIBS=$(MAV_FTP_PRO_LIBS)"
IP := 10.18.0.213
run:
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
CAMERA_IP := 10.18.0.215
camera:
	ffplay rtsp://$(CAMERA_IP)/554