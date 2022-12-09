#pragma once

#include <charconv>
#include <cstdint>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <array>
#include <cmath>
#include <charconv>

namespace aoc {
namespace Day9 {

using Position = std::pair<int, int>;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

Position move(char c) {
		switch (c) {
		case 'R': return {1, 0	}; break;
		case 'L': return {-1, 0	}; break;
		case 'U': return {0, 1	}; break;
		case 'D': return {0, -1	}; break;
	}
	return {0, 0};
}

// https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
inline int sgn(int val) {
    return (0 < val) - (val < 0);
}

template<size_t N>
void move_knots(std::array<Position, N>& knots, std::unordered_set<Position, pair_hash>& visited) {
	for (size_t i{1}; i < knots.size(); i++) {
		const auto tail_pos = knots[9];
		const auto& head = knots[i - 1];
		auto& tail = knots[i];

		auto delta = std::make_pair<int, int>(
			head.first - tail.first,
			head.second - tail.second
		);

		if (std::abs(delta.second) == 2) {
			tail.first += sgn(delta.first);
			tail.second += sgn(delta.second);
		} else if(std::abs(delta.first) == 2) {
			tail.first += sgn(delta.first);
			tail.second += sgn(delta.second);
		}

		if (tail_pos != knots.back()) {
			visited.insert(knots.back());
		}	
	}
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::array<Position, 2> knots;
	std::fill(knots.begin(), knots.end(), std::make_pair<int, int>(0,0));
	std::unordered_set<Position, pair_hash> visited;
	visited.insert(knots.back());

	for (const auto& line : data) {
		Position delta = move(line[0]);
		int steps;
		std::from_chars(line.data() + 2, line.data() + line.size(), steps);
		for (int i{0}; i < steps; i++) {
			knots[0].first += delta.first;
			knots[0].second += delta.second;
			for(size_t j{0}; j < knots.size() - 1; ++j) {
				move_knots(knots, visited);
			}
		}
	}
	return visited.size();
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::array<Position, 10> knots;
	std::fill(knots.begin(), knots.end(), std::make_pair<int, int>(0,0));
	std::unordered_set<Position, pair_hash> visited;
	visited.insert(knots.back());


	for (const auto& line : data) {
		Position delta = move(line[0]);
		int steps;
		std::from_chars(line.data() + 2, line.data() + line.size(), steps);
		for (int i{0}; i < steps; i++) {
			knots[0].first += delta.first;
			knots[0].second += delta.second;
			for(size_t j{0}; j < knots.size() - 1; ++j) {
				move_knots(knots, visited);
			}
		}
	}
	return visited.size();
}
}
}