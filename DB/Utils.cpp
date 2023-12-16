#include "Utils.hpp"

void drawProgressBar(int percentage) {
    std::cout << "\r[";
    for (int i = 0; i < PROGRESS_BAR_WIDTH; ++i) {
        if (i < percentage)
            std::cout << "=";
        else
            std::cout << " ";
    }
    std::cout << "] " << percentage << "%" << std::flush;
}


void AddFingerPrintsToDB(
    DataBase& db_, std::vector<std::pair<std::string, int>> finger_prints, 
    int song_id) {
  size_t count = finger_prints.size();
  int percentage = 0;
  int hundreadth = (count + PROGRESS_BAR_WIDTH - 1) / PROGRESS_BAR_WIDTH;
  for (size_t i = 0; i < count; ++i) {
    auto [hash_value, offset] = finger_prints[i];
    Hash hash(hash_value, offset, song_id);
    db_.AddHash(hash);
    if (i % hundreadth == 0) {
      drawProgressBar(percentage);
      ++percentage;
    }
  }
  drawProgressBar(PROGRESS_BAR_WIDTH);
}

void AddDataToDB(DataBase& db_, const fs::path& file_path) {
  std::cout << "Processing " << file_path.filename() << "..." << std::endl;
  AudioConverter convertor(file_path.string());
  auto spectogram = GenerateSpectrogram(convertor.GetData());
  auto finger_prints = GetFingerPrints(spectogram);
  std::cout << "Done fingerpinting" << std::endl;
  std::cout << "\t\t Adding to DB..." << std::endl;
  int song_id = db_.getSongRowCount();
  Song song(file_path.filename().string(), song_id);
  db_.AddSong(song);
  AddFingerPrintsToDB(db_, finger_prints, song_id);
  std::cout << "\n\n" << std::endl;
}

void LoadFolder(DataBase& db_, const fs::path& folder_path) {
  for (const auto& entry : fs::directory_iterator(folder_path)) {
    if (fs::is_directory(entry.path())) {
      LoadFolder(db_, entry.path());
    } else if (entry.is_regular_file() &&  entry.path().extension() == ".wav") {
        AddDataToDB(db_, entry.path());
    }
  }
}
