#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace ball_lora_dashboard {

struct McuFrame {
  std::vector<float> values;
  std::vector<std::uint8_t> raw;
};

class McuFrameDecoder {
 public:
  static constexpr std::size_t kMaxFloats = 64;

  std::vector<McuFrame> feed(const std::uint8_t* data, std::size_t size);
  void reset() { buffer_.clear(); }
  bool hasPartialFrame() const { return !buffer_.empty(); }

 private:
  std::vector<std::uint8_t> buffer_;
};

std::array<std::uint8_t, 6> encodeKeyFrame(std::uint8_t sequence, bool started, bool blue);

}  // namespace ball_lora_dashboard
