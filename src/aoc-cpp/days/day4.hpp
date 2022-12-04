#pragma once

#include <cstdint>
#include <numeric>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <iostream>
#include <charconv>

namespace aoc {
namespace Day4 {

inline bool overlaps(int left_first, int left_last, int right_first, int right_last) {
    if (left_first >= right_first) {
        return right_last >= left_first;
    }
    if (left_first <= right_first) {
        return left_last >= right_first;
    }
    return false;
}

inline bool contains(int left_first, int left_last, int right_first, int right_last) {
    if ((left_first >= right_first && left_last <= right_last)
    || (left_first <= right_first && left_last >= right_last)) return true;
    return false;
}

inline void get_ranges(const std::string& line,
                        int& l_first, int& l_last,
                        int& r_first, int& r_last)
{
        std::from_chars(line.data(), line.data() + line.find("-"), l_first);
        std::from_chars(line.data() + line.find_first_of("-") + 1, line.data() + line.find(","), l_last);
        std::from_chars(line.data() + line.find(",") + 1, line.data() + line.find_last_of("-"), r_first);
        std::from_chars(line.data() + line.find_last_of("-") + 1, line.data() + line.size() - (line.find_last_of("-") + 1), r_last);
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
    std::uint64_t sum{0};
    for (auto& line : data) {
        int l_first{}, l_last{}, r_first{}, r_last{};
        get_ranges(line, l_first, l_last, r_first, r_last);
        if (contains(l_first, l_last, r_first, r_last)) {
            sum++;
        }
    }
    return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
    std::uint64_t sum{0};
    for (auto& line : data) {
        int l_first{}, l_last{}, r_first{}, r_last{};
        get_ranges(line, l_first, l_last, r_first, r_last);
        if (overlaps(l_first, l_last, r_first, r_last)) {
            sum++;
        }
    }
    
    return sum;
}
}
}