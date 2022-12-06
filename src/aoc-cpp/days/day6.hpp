#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <bit>

namespace aoc {
namespace Day6 {

template<std::int32_t N>
std::uint64_t find_marker(const std::string& s) {
    constexpr auto a = static_cast<int32_t>('a');

    for (size_t i = N; i < s.length() - N; i++) {
        std::uint32_t mask{0};
        for (auto j{i - N}; j < i; j++) {
            mask |= 1 << (s[j] - a);
        }
        if (std::popcount(mask) == N) {
            return i;
        }
    }
    return 0;
}

std::uint64_t Part1([[maybe_unused]] const std::string& data) {    
    return find_marker<4>(data);
}

std::uint64_t Part2([[maybe_unused]] const std::string& data) {
    return find_marker<14>(data);
}
}
}