#ifndef FINGEEPRINT_HPP_
#define FINGEEPRINT_HPP_

#include <openssl/sha.h>

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "Constants.hpp"

std::vector<std::pair<std::string, int>> GenerateFingerPrints(
    std::vector<std::vector<double>> &spectogram);

#endif  // FINGEEPRINT_HPP_