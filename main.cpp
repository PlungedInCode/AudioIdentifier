#include <string>
// #include "UI/UIManager.hpp"
#include "Logger.hpp"
#include "DB/Utils.hpp"

using namespace Utils;

int main() {

  Logger::SetLogLevel(LogLevel::kTrace);
  Logger::DisableFileStamp();
  Logger::SetStream(OutputStream::kBoth);
  Logger::SetLogFile("20Songs.txt");
  std::string DBTEST_folderPath = "../music/TestFulls";
  std::string SamplesTest_folderPath = "../music/TestSamples";
  std::string Fulls_folderPath = "../music/Fulls";
  std::string Samples_folderPath = "../music/Samples";

  // DataBase db("FLATTEDPEAKS.db");
  // DataBase db("MINMAXFPEAKS.db");
  DataBase db("FLATTEDPEAKSTEST.db");
  // DataBase db("MINMAXFPEAKSTEST.db");

  try {
    // LoadFolder(db, Fulls_folderPath);
    // TestFolder(db, Samples_folderPath);

    LoadFolder(db, DBTEST_folderPath);
    TestFolder(db, SamplesTest_folderPath);
  } catch (const std::exception& e) {
    LOG_ERROR("Error: ", e.what());
    return 1;
  }

  return 0;
}
