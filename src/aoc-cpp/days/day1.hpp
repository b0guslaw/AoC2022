#pragma once

#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

namespace aoc {
namespace Day1 {
uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t max{0};
	std::uint64_t sum{0};
	for (const auto& s : data) {
		if (s.empty()) {
			if (sum > max) {
				max = sum;
			}
			sum = 0;
		} else {
			sum += std::stoi(s);
		}
	}
	return max;
}

uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::vector<int> sums;
	std::uint64_t sum{0};
	for (const auto& s : data) {
		if (s.empty()) {
			sums.push_back(sum);
			sum = 0;
		} else {
			sum += std::stoi(s);
		}
	}

	std::sort(sums.rbegin(), sums.rend());
	return sums.at(0) + sums.at(1) + sums.at(2);
}
}
}