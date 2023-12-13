CXX = g++
CXXFLAGS = -std=c++20

SRC_DIR = .
AUDIO_MODULE_DIR = AudioModule
MATH_DIR = Math
FINGERPRINT_DIR = FingerPrint
DB_DIR = DB
UI_DIR = UI
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(AUDIO_MODULE_DIR)/*.cpp) $(wildcard $(MATH_DIR)/*.cpp)  $(wildcard $(FINGERPRINT_DIR)/*.cpp) $(wildcard $(DB_DIR)/*.cpp) $(wildcard $(UI_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main
LIBS = -lportaudio -lssl -lcrypto -ltag -lsqlite3 -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:	
	rm -f $(OBJECTS) $(TARGET)

