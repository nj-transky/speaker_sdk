APP        := speaker_sdk_example

SDK_DEMO_ROOT := ../demo
SDK_LIB_ROOT  := ../lib/linux/lib

APP_SRC   := main.cpp
APP_OBJ   := $(APP_SRC:.cpp=.o)

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

all: $(APP)

$(APP): $(APP_OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(APP) $(APP_OBJ)

