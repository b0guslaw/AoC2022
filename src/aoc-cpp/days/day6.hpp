#pragma once

#include <atomic>
#include <bit>
#include <bits/ranges_algo.h>
#include <bits/ranges_util.h>
#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <bit>

namespace aoc {
namespace Day6 {

std::uint64_t find_marker(const std::string& s, size_t window) {
    
    for (size_t i = window; i < s.size() - window; i++) {
        std::uint32_t mask{0};
        for (auto j{i - window}; j < i; j++) {
            mask |= 1 << (s[j] - 'a');
        }
        if (std::popcount(mask) == static_cast<int32_t>(window)) {
            return i;
        }
    }
    return 0;
}

std::uint64_t Part1([[maybe_unused]] const std::string& data) {    
    return find_marker(data, 4);
}

std::uint64_t Part2([[maybe_unused]] const std::string& data) {
    return find_marker(data, 14);
}
}
}