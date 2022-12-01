#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>

namespace aoc {
namespace Day1 {
std::uint64_t Part1([[maybe_unused]] const std::vector<std::int64_t>& data) {
	std::uint64_t max{0};
	std::uint64_t sum{0};
	for (const auto& s : data) {
		if (s != 0) {
			sum += s;
		} else {
			if (sum > max) {
				max = sum;
			}
			sum = 0;
		}
	}
	return max;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::int64_t>& data) {
	std::vector<int64_t> sums;
	std::uint64_t sum{0};
	for (const auto& s : data) {
		if (s != 0) {
			sum += s;
		} else {
			sums.push_back(sum);
			sum = 0;
		}
	}
	sums.push_back(sum);
	std::sort(sums.rbegin(), sums.rend());
	return std::accumulate(sums.begin(), sums.begin() + 3, 0);
}
}
}