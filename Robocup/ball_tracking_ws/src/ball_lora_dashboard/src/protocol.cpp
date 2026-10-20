#include "ball_lora_dashboard/protocol.hpp"

#include <algorithm>
#include <cstring>

namespace ball_lora_dashboard {

std::vector<McuFrame> McuFrameDecoder::feed(const std::uint8_t* data, std::size_t size) {
  buffer_.insert(buffer_.end(), data, data + size);
  std::vector<McuFrame> frames;
  while (!buffer_.empty()) {
    const auto header = std::find(buffer_.begin(), buffer_.end(), 0xAA);
    if (header == buffer_.end()) {
      reset();
      break;
    }
    buffer_.erase(buffer_.begin(), header);
    if (buffer_.size() < 2) break;

    const std::size_t count = buffer_[1];
    if (count < 1 || count > kMaxFloats) {
      buffer_.erase(buffer_.begin());
      continue;
    }
    const std::size_t frame_size = 3 + 4 * count;
    if (buffer_.size() < frame_size) break;
    if (buffer_[frame_size - 1] != 0x55) {
      buffer_.erase(buffer_.begin());
      continue;
    }

    McuFrame frame;
    frame.raw.assign(buffer_.begin(), buffer_.begin() + frame_size);
    frame.values.reserve(count);
    for (std::size_t i = 0; i < count; ++i) {
      const std::size_t offset = 2 + 4 * i;
      const std::uint32_t bits =
          static_cast<std::uint32_t>(buffer_[offset]) |
          (static_cast<std::uint32_t>(buffer_[offset + 1]) << 8) |
          (static_cast<std::uint32_t>(buffer_[offset + 2]) << 16) |
          (static_cast<std::uint32_t>(buffer_[offset + 3]) << 24);
      float value;
      static_assert(sizeof(value) == sizeof(bits), "float32 is required");
      std::memcpy(&value, &bits, sizeof(value));
      frame.values.push_back(value);
    }
    frames.push_back(std::move(frame));
    buffer_.erase(buffer_.begin(), buffer_.begin() + frame_size);
  }
  return frames;
}

std::array<std::uint8_t, 6> encodeKeyFrame(std::uint8_t sequence, bool started, bool blue) {
  const std::uint8_t flags = static_cast<std::uint8_t>((started ? 0x01 : 0x00) |
                                                       (blue ? 0x02 : 0x00));
  std::array<std::uint8_t, 6> frame{0xA5, 0x5A, 0x01, sequence, flags, 0};
  for (std::size_t i = 0; i < 5; ++i) frame[5] ^= frame[i];
  return frame;
}

}  // namespace ball_lora_dashboard
