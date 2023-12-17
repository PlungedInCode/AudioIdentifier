#ifndef MATH_UTILS_HPP_
#define MATH_UTILS_HPP_

#pragma once
#include <cstdint>
#include <numbers>

namespace constant {
  const double kPi = std::numbers::pi;
  const double kEps = 1e-6;
  const uint64_t kSamplingRate = 44100;
  const int numInputChannels = 1;
  const int numOutputChannels = 0;
}

#endif //MATH_UTILS_HPP_
