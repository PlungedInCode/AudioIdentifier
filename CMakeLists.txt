cmake_minimum_required(VERSION 3.16)
project(AudioIdentifier)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(AudioModule Math DB FingerPrint UI)

add_subdirectory(lib/SimpleLogger)

# Add your source files
add_executable(AudioIdentifier
    AudioModule/AudioConverter.cpp
    AudioModule/AudioExceptions.cpp
    AudioModule/AudioRecorder.cpp
    Math/Field.cpp
    Math/FastFourierTransform.cpp
    DB/Database.cpp
    DB/Utils.cpp
    FingerPrint/FingerPrint.cpp
    UI/Button.cpp
    UI/PopUp.cpp
    UI/UIManager.cpp
    main.cpp
)

# Link libraries
target_link_libraries(AudioIdentifier SimpleLogger portaudio ssl crypto tag sqlite3 sfml-graphics sfml-window sfml-system sfml-audio)