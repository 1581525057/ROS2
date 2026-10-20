#include "ball_lora_dashboard/protocol.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

using ball_lora_dashboard::McuFrameDecoder;
using ball_lora_dashboard::encodeKeyFrame;

int main() {
#define CHECK(condition) do { \
  if (!(condition)) { std::cerr << "Failed: " << #condition << '\n'; return 1; } \
} while (false)

  McuFrameDecoder decoder;
  const std::vector<std::uint8_t> first{0xAA, 0x02, 0, 0, 0x80, 0x3F,
                                         0, 0, 0x20, 0xC0, 0x55};
  const std::vector<std::uint8_t> second{0xAA, 0x01, 0x55, 0xAA, 0, 0x3F, 0x55};
  CHECK(decoder.feed(first.data(), 5).empty());
  std::vector<std::uint8_t> remainder(first.begin() + 5, first.end());
  remainder.insert(remainder.end(), second.begin(), second.end());
  const auto frames = decoder.feed(remainder.data(), remainder.size());
  CHECK(frames.size() == 2);
  CHECK(frames[0].raw == first && frames[1].raw == second);
  CHECK(frames[0].values.size() == 2);
  CHECK(frames[0].values[0] == 1.0f && frames[0].values[1] == -2.5f);

  const std::vector<std::uint8_t> invalid{0xAA, 0x00, 0xAA, 0x01,
                                           0, 0, 0x80, 0x3F, 0x00};
  std::vector<std::uint8_t> noisy = invalid;
  noisy.insert(noisy.end(), second.begin(), second.end());
  const auto recovered = decoder.feed(noisy.data(), noisy.size());
  CHECK(recovered.size() == 1 && recovered[0].raw == second);

  const auto stopped_red = encodeKeyFrame(0, false, false);
  const auto started_red = encodeKeyFrame(1, true, false);
  const auto stopped_blue = encodeKeyFrame(2, false, true);
  const auto started_blue = encodeKeyFrame(3, true, true);
  CHECK((stopped_red == std::array<std::uint8_t, 6>{0xA5, 0x5A, 1, 0, 0, 0xFE}));
  CHECK((started_red == std::array<std::uint8_t, 6>{0xA5, 0x5A, 1, 1, 1, 0xFE}));
  CHECK((stopped_blue == std::array<std::uint8_t, 6>{0xA5, 0x5A, 1, 2, 2, 0xFE}));
  CHECK((started_blue == std::array<std::uint8_t, 6>{0xA5, 0x5A, 1, 3, 3, 0xFE}));
}
