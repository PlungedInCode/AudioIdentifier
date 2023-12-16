#ifndef SHASHMAQAMFINDER_UTILS_HPP_
#define SHASHMAQAMFINDER_UTILS_HPP_

#include "Math/Spectrogram.hpp"
#include "DB/Database.hpp"
#include "AudioModule/AudioConverter.hpp"
#include "FingerPrint/FingerPrint.hpp"

#include <filesystem>
namespace fs = std::filesystem;


#define PROGRESS_BAR_WIDTH 50

void LoadFolder(DataBase& db_, const fs::path& folder_path);

#endif  // SHASHMAQAMFINDER_UTILS_HPP_