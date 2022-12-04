#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

namespace aoc {
namespace Day2 {

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	const uint8_t score_table_p1[3][3] = {
			{4, 8, 3},
			{1, 5, 9},
			{7, 2, 6}
	};

	std::uint64_t sum{0};
	for (const auto& s : data) {
		sum += score_table_p1[s[0] - 'A'][s[2] - 'X'];
	}
	return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};
	const uint8_t score_table_p2[3][3] = {
		{3, 4, 8},
		{1, 5, 9},
		{2, 6, 7}
	};
	for (const auto& s : data) {
		sum += score_table_p2[s[0] - 'A'][s[2] - 'X'];
	}
	return sum;
}
}
}