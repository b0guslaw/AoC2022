#pragma once

#include <charconv>
#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>

namespace aoc {
namespace Day10 {

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {	
	std::int64_t cycle{0};
	std::int64_t reg{1};
	std::int64_t sum{0};

	auto store = [&](){
		if (cycle % 40 == 20) {
			sum += cycle * reg;
		}
	};
	for (const auto& line : data) {
		if (line == "noop") {
			cycle++;
			store();
			continue;
		} else {
			cycle++;
			store();
			cycle++;
			store();
			reg += std::stoi(line.substr(5));
		}
	}
	return sum;
}

std::string Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::int64_t cycle{1};
	std::int64_t reg{1};
	std::string screen{""};

	auto process = [&]() {
		auto crt = cycle - 1;
		if (std::abs(crt % 40 - reg) < 2) {
			screen += '#';
		} else {
			screen += '.';
		}
		if (cycle++ % 40 == 1) {
			screen += '\n';
		}
	};

	for (const auto& line : data) {
		process();
		if (line != "noop") {
			process();
			reg += std::stoi(line.substr(5));
		}
	}
	return screen;
}
}
}