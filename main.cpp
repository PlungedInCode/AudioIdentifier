// #include <SFML/Graphics.hpp>
// #include <SFML/Graphics/Color.hpp>
// #include <SFML/Window/Event.hpp>
// #include <filesystem>
// #include <iostream>
// #include <queue>

// #include "AudioModule/AudioConverter.hpp"
// #include "AudioModule/AudioRecorder.hpp"
// #include "DB/Database.hpp"
// #include "FingerPrint/FingerPrint.hpp"
// #include "Math/Spectrogram.hpp"
// #include "UI/Button.hpp"
// #include "UI/PopUp.hpp"

// namespace fs = std::filesystem;

// void AddSongToDb(DataBase& db, const fs::path& file_path) {
//   std::cout << "Adding " << file_path << std::endl;
//   int64_t song_id = db.getSongRowCount();
//   std::cout << "song_id: " << song_id << std::endl;
//   try {
//     Song song(file_path.filename().string(), song_id);
//     db.AddSong(song);
//   } catch (const std::runtime_error& e) {
//     std::cout << "Something went wrong while adding / Or file already exsits. "
//               << file_path << std::endl
//               << e.what() << std::endl;
//     return;
//   }
//   AudioConverter converter(file_path.string());
//   std::vector<std::vector<double>> spect =
//       GenerateSpectrogram(converter.GetData());
//   std::vector<std::pair<std::string, int>> fingerPrints =
//       GetFingerPrints(spect);

//   std::cout << "Fingerprints: " << fingerPrints.size() << std::endl;
//   int64_t cnt = 0;

//   for (const auto [hash, offset] : fingerPrints) {
//     Hash currHash(hash, offset, song_id);
//     db.AddHash(currHash);
//     cnt++;
//     if (cnt % 5000 == 0) {
//       std::cout << cnt << std::endl;
//     }
//   }
// }

// void AddFolderToDb(DataBase& db, const std::string& folder) {
//   fs::path current_folder(folder);
//   std::queue<fs::path> dirs;
//   dirs.push(current_folder);

//   while (!dirs.empty()) {
//     current_folder = dirs.front();
//     dirs.pop();
//     for (const auto& entry : fs::directory_iterator(current_folder)) {
//       const auto filenameStr = entry.path().filename().string();

//       if (entry.is_directory()) {
//         dirs.push(entry.path());
//       } else if (entry.is_regular_file() &&
//                  entry.path().extension().string() == ".wav") {
//         AddSongToDb(db, entry);
//       }
//     }
//   }
// }

// void findSongFromDb(DataBase& db, const fs::path& path) {

//   Song fsong(path.filename().string(), -1);
//   AudioConverter converter(path);

//   std::vector<std::vector<double>> spect =
//       GenerateSpectrogram(converter.GetData());
//   std::vector<std::pair<std::string, int>> fingerPrints =
//       GetFingerPrints(spect);

//   auto newSong = db.getBestMatch(fingerPrints);
//   if (newSong.has_value()) {
//     std::cout << path.filename() << std::endl;
//     std::cout << newSong->getName() << ", " << newSong->getArtist() << ", "
//               << newSong->getAlbum() << ", " << newSong->getID() << std::endl;
//   }
//   std::cout << "----------------------------------" << std::endl;
// }

// void Test(DataBase& db, const std::string& folder) {
//   fs::path current_folder(folder);
//   std::queue<fs::path> dirs;
//   dirs.push(current_folder);

//   while (!dirs.empty()) {
//     current_folder = dirs.front();
//     dirs.pop();
//     for (const auto& entry : fs::directory_iterator(current_folder)) {
//       const auto filenameStr = entry.path().filename().string();

//       if (entry.is_directory()) {
//         dirs.push(entry.path());
//       } else if (entry.is_regular_file() &&
//                  entry.path().extension().string() == ".wav") {
//                   std::cout << entry.path().filename() << std::endl;
//           findSongFromDb(db, entry.path());
//       }
//     }
//   }
// }

// int main() {
  
//   DataBase db("Test.db");
//   AddFolderToDb(db, "music/Fulls");
//   Test(db, "music/Samples");
//   // std::vector<std::vector<double>> spect =
//   // GenerateSpectrogram(recorder.GetData()); std::vector<std::pair<std::string,
//   // int>> fingerPrints = GetFingerPrints(spect);

//   // std::cout << fingerPrints.size() << std::endl;
//   // std::cout << "Done Fingerprinting" << std::endl;
//   // Song newSong = db.getBestMatch(fingerPrints);
//   // std::cout << "AA " << " - " << newSong.getName() << ", "<<
//   // newSong.getArtist() << ", " << newSong.getAlbum() << ", " <<
//   // newSong.getID() << '\n';

//   /*UI*/
  
//   // sf::RenderWindow window(sf::VideoMode(400, 700), "ShazamUI",
//   // sf::Style::Close);

//   // std::unique_ptr<sf::Font> font_ = std::make_unique<sf::Font>();
//   // if (font_->loadFromFile("UI/assets/fonts/Roboto-Regular.ttf")) {
//   //     std::cout << "Font loaded\n";
//   // } else {
//   //     std::cerr << "Failed to load font\n";
//   //     return -1;
//   // }

//   // sf::Text label;
//   // label.setFont(*font_.get());
//   // label.setString("Music Finder");
//   // label.setFillColor(sf::Color::Black);
//   // label.setCharacterSize(24);
//   // label.setOrigin(label.getLocalBounds().width / 2,
//   //                       label.getLocalBounds().height / 2);
//   // label.setPosition(window.getSize().x / 2, 50.f);

//   // PopUp Data;

//   // Button shape(window.getSize().x / 2, window.getSize().y / 2, 100.f);

//   // AudioRecorder recorder;
//   // bool recording = false;
//   // while (window.isOpen()) {

//   //     sf::Event event;
//   //     while (window.pollEvent(event)) {
//   //         if (event.type == sf::Event::Closed) {
//   //             window.close();
//   //         } else if (event.type == sf::Event::KeyPressed) {
//   //             switch (event.key.code) {
//   //                 case sf::Keyboard::Enter:
//   //                     if (!recorder.IsRecording()) {
//   //                         shape.ChangeState();
//   //                         recording = true;
//   //                     }
//   //                     break;
//   //                 case sf::Keyboard::Space:
//   //                     Data.ChangeState();
//   //                 default:
//   //                     break;
//   //             }
//   //         }
//   //     }

//   //     window.clear(sf::Color::White);
//   //     shape.Update();
//   //     window.draw(shape);
//   //     window.draw(label);
//   //     window.draw(Data);
//   //     window.display();

//   //     if (recording) {
//   //         recorder.StartRecording(1);
//   //         std::pair<std::string, std::string> getMatches =
//   //         GetMatches(recorder.GetData()); Data.SetData(getMatches.first,
//   //         getMatches.second); recording = false; shape.ChangeState();
//   //         Data.ChangeState();
//   //     }
//   // }

//   return 0;
// }

// /* TODO:
//             - collizion in DB
//             - Refactoring code for AudioModule
//             - Refactoring code for DB
//             - Refactoring code for UI
//             - Optimization
//             - Threading Front and Back
// */

#include "UI/ShazamUI.hpp"


int main() {
  ShazamUI shz;
  shz.Run();
}