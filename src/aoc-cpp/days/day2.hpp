#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

namespace aoc {
namespace Day2 {

const std::uint8_t ROCK = 1;
const std::uint8_t PAPER = 2;
const std::uint8_t SCISSOR = 3;

const std::map<char, int> shape = {
	{'X', ROCK},
	{'Y', PAPER},
	{'Z', SCISSOR}
};

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};

	for (const auto& s : data) {
		sum += shape.at(s[2]);
		switch (s[0]) {
			case 'A':
				if (s[2] == 'Y') {
					sum += 6;
				} else if (s[2] == 'X') {
					sum += 3;
				}
				break;
			case 'B':
				if (s[2] == 'Z') {
					sum += 6;
				} else if (s[2] == 'Y') {
					sum += 3;
				}
				break;
			case 'C':
				if (s[2] == 'X') {
					sum += 6;
				} else if (s[2] == 'Z') {
					sum += 3;
				}
				break;
		}
	}
	return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::uint64_t sum{0};

	for (const auto& s : data) {
		
		switch (s[0]) {
			case 'A':
				switch (s[2]) {
					case 'X':
						sum += 0;
						sum += shape.at('Z');
						break;
					case 'Y':
						sum += 3;
						sum += shape.at('X');
						break;
					case 'Z':
						sum += 6;
						sum += shape.at('Y');
						break;
				}
				break;
			case 'B':
				switch (s[2]) {
					case 'X':
						sum += 0;
						sum += shape.at('X');
						break;
					case 'Y':
						sum += 3;
						sum += shape.at('Y');
						break;
					case 'Z':
						sum += 6;
						sum += shape.at('Z');
						break;
				}
				break;
			case 'C':
				switch (s[2]) {
					case 'X':
						sum += 0;
						sum += shape.at('Y');
						break;
					case 'Y':
						sum += 3;
						sum += shape.at('Z');
						break;
					case 'Z':
						sum += 6;
						sum += shape.at('X');
						break;
				}
				break;
		}
	}
	return sum;
}
}
}