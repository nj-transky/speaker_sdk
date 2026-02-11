APP_NAME        := speaker_sdk_example

SDK_DEMO_ROOT := ../demo
SDK_LIB_ROOT  := ../lib/linux/lib

BUILD_DIR := build

APP_SRC   := main.cpp
APP_OBJ   := $(addprefix $(BUILD_DIR)/, $(APP_SRC:.cpp=.o))
APP_BIN   := $(BUILD_DIR)/$(APP_NAME)

CXX       := g++
CXXSTD    := -std=c++17

INC      += -I$(SDK_DEMO_ROOT)

LIBDIR   += -L$(SDK_LIB_ROOT)

# Link order matters: first our interface library, then vendor libs.
LIBS     += -lspeaker_interface
LIBS     += -lmavftp_pro
LIBS     += -lmavsdk
LIBS     += -lpaho-mqttpp3
LIBS     += -lpaho-mqtt3a
LIBS     += -ljsoncpp
LIBS     += -lcurl
LIBS     += -llzma
LIBS     += -ltinyxml2
LIBS     += -lpthread

CXXFLAGS := $(CXXSTD) -O2 $(INC)
LDFLAGS  := $(LIBDIR) $(LIBS)

.PHONY: all clean

all: $(APP_BIN)

$(APP_BIN): $(APP_OBJ) | $(BUILD_DIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

SPEAKER_IP := 192.168.144.67
SPEAKER_PORT := 14556
run:
	./$(APP_BIN) $(SPEAKER_IP) $(SPEAKER_PORT)

clean:
	rm -rf ./$(BUILD_DIR)


push:
	ffmpeg -re -i ./audio/audio.wav \
    -vn -acodec aac  \
    -ar 16000 -ac 2 \
    -f rtp -payload_type 97 \
    -sdp_file ./audio/client_audio.sdp \
    rtp://192.168.144.67:15557
pull:
	ffplay \
		-nodisp \
		-autoexit \
		-protocol_whitelist file,udp,rtp \
		-i ./audio/server_audio.sdp
video:
	ffplay "rtsp://192.168.144.19:554"
