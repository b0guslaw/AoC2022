#pragma once

#include <cstdint>
#include <numeric>
#include <string_view>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <iostream>
#include <map>
#include <ranges>
#include <set>

namespace aoc {
namespace Day3 {

inline int get_priority(char c) {
   if (c >= 'a') {
      return c - 96;
   }
    return c - 38;
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};
	for (const auto& rucksack : data) {
		const std::string_view& first_comp{rucksack.begin(), rucksack.begin() + (rucksack.size() / 2)};
		const std::string_view& second_comp{rucksack.begin() + (rucksack.size() / 2), rucksack.end()};

		std::set<char> common;
		for (const auto& item : first_comp) {
			if (second_comp.find(item) != std::string_view::npos) {
				common.insert(item);
			}
		}
		
		for (const auto& c : common) {
			sum += get_priority(c);
		}

	}
	return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};
	for (size_t i{0}; i < data.size(); i += 3) {
		const auto& first_rucksack = data[i];
		const auto& second_rucksack = data[i + 1];
		const auto& third_rucksack = data[i + 2];

		std::set<char> common;
		for (const auto& item : first_rucksack) {
			if (second_rucksack.find(item) != std::string::npos &&
				third_rucksack.find(item) != std::string::npos) {
				common.insert(item);
			}
		}

		for (const auto& c : common) {
			sum += get_priority(c);
		}
	}
	
	return sum;
}
}
}