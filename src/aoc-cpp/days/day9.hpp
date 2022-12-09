#pragma once

#include <cstdint>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <array>
#include <cmath>

namespace aoc {
namespace Day9 {

using Position = std::pair<int, int>;

inline bool adjacent(const Position& A, const Position& B) {
	return std::abs( A.first - B.first) <= 1 &&
			std::abs(A.second - B.second) <= 1;
}

// https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
template <typename T>
inline int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

const Position get_move(char move) {
	static const std::unordered_map<char, Position> moves {
		{'R', {1, 0}},
		{'L', {-1, 0}},
		{'U', {0, 1}},
		{'D', {0, -1}},
	};

	return moves.at(move);
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {

	Position head{0, 0};
	Position tail{0, 0};

	std::set<Position> visited;
	visited.insert(tail);

	for (const auto& line : data) {
		auto steps = std::stoi(line.substr(line.find(' '), line.size() - line.find(' ')));

		for (int i{0}; i < steps; i++) {
			auto delta = get_move(line[0]);
			auto head_d = std::make_pair<int, int>(head.first + delta.first, head.second + delta.second);
			if (!adjacent(tail, head_d)) {
				tail = head;
				visited.insert(tail);
			}

			head = head_d;
		}
	}
	return visited.size();
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::array<Position, 10> knots;
	std::fill(knots.begin(), knots.end(), std::make_pair<int, int>(0,0));
	std::set<Position> visited;
	
	const auto move_knots = [&] {
		for (size_t i{1}; i < knots.size(); i++) {
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
			visited.insert(knots.back());
		}
	};

	for (const auto& line : data) {
		auto delta = get_move(line[0]);	
		auto steps = std::stoi(line.substr(line.find(' '), line.size() - line.find(' ')));
		for (int i{0}; i < steps; i++) {
			knots[0].first += delta.first;
			knots[0].second += delta.second;
			for(size_t j{0}; j < knots.size() - 1; ++j) {
				move_knots();
			}
		}
	}
	return visited.size();
}
}
}