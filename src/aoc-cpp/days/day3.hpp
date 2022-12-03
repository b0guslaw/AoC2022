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

inline int get_priority(char c)
{
   if (c >= 'a' && c <= 'z') {
      return 1 + c - 'a';
   }
   else if (c >= 'A' && c <= 'Z') {
      return 27 + c - 'A';
   }
   return - 1;
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};
	for (const auto& rucksack : data) {
		std::string_view first_comp{rucksack.begin(), rucksack.begin() + (rucksack.size() / 2)};
		std::string_view second_comp{rucksack.begin() + (rucksack.size() / 2), rucksack.end()};

		std::map<char, int> first;
		std::map<char, int> second;

		for (const auto& item : first_comp) {
			first[item]++;
		}

		for (const auto& item : second_comp) {
			second[item]++;
		}

		std::vector<char> common;
		for (const auto& [key, value] : first) {
			if (second.contains(key)) {
				common.push_back(key);
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
		std::string first_rucksack = data[i];
		std::string second_rucksack = data[i + 1];
		std::string third_rucksack = data[i + 2];

		std::map<char, int> first;
		std::map<char, int> second;
		std::map<char, int> third;

		for (const auto& item : first_rucksack) {
			first[item]++;
		}

		for (const auto& item : second_rucksack) {
			second[item]++;
		}

		for (const auto& item : third_rucksack) {
			third[item]++;
		}

		std::vector<char> common;
		for (const auto& [key, value] : first) {
			if (second.contains(key) && third.contains(key)) {
				common.push_back(key);
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