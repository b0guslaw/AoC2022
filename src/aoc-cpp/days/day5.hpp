#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

#include <fmt/core.h>

namespace aoc {
namespace Day5 {

std::string Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::vector<std::stack<char>> slots{9};
	std::string result{};
	auto instruction_start = data.begin();
	auto ground = data.begin();

	for (auto it = data.begin(); !it->empty(); it++) {
		instruction_start = it;
		ground = it;
	}
	instruction_start += 2;
	ground--;

	while (true) {
		size_t idx{0};
		for (size_t i{1}; i < ground->size(); i += 4) {
			char value = ground->at(i);
			if (value != ' ') {
				slots[idx].push(value);
			}
			idx++;
		}
		if (ground == data.begin()) {
			break;
		}
		--ground;
	}

	for (auto it = instruction_start; it != data.end(); it++) {
        if (it->empty()) {
            break;
        }
		std::istringstream iss{*it};
		std::string buffer;
		int pos{0};

		size_t amount{0};
		int from{0};
		int to{0};
		while (iss >> buffer) {
			if (pos == 1) {
				amount = std::stoi(buffer);
			}
			if (pos == 3) {
				from = std::stoi(buffer);
			}
			if (pos == 5) {
				to = std::stoi(buffer);
			}
			++pos;
		}
		
		for (size_t i{0}; i < amount; i++) {
			auto crate = slots[from - 1].top();
			slots[from - 1].pop();
			slots[to - 1].push(crate);
		}
	}

	for (auto& v : slots) {
		if (!v.empty()) {
			result += v.top();
		}
	}
	return result;
}

std::string Part2([[maybe_unused]] const std::vector<std::string>& data) {
	std::vector<std::stack<char>> slots{9};
	std::string result{};
	auto instruction_start = data.begin();
	auto ground = data.begin();

	for (auto it = data.begin(); !it->empty(); it++) {
		instruction_start = it;
		ground = it;
	}
	instruction_start += 2;
	ground--;

	while (true) {
		size_t idx{0};
		for (size_t i{1}; i < ground->size(); i += 4) {
			char value = ground->at(i);
			if (value != ' ') {
				slots[idx].push(value);
			}
			idx++;
		}
		if (ground == data.begin()) {
			break;
		}
		--ground;
	}

	for (auto it = instruction_start; it != data.end(); it++) {
        if (it->empty()) {
            break;
        }
		std::istringstream iss{*it};
		std::string buffer;
		int pos{0};

		size_t amount{0};
		int from{0};
		int to{0};
		while (iss >> buffer) {
			if (pos == 1) {
				amount = std::stoi(buffer);
			}
			if (pos == 3) {
				from = std::stoi(buffer);
			}
			if (pos == 5) {
				to = std::stoi(buffer);
			}
			++pos;
		}
		
		std::stack<char> temp;
		for (size_t i{0}; i < amount; i++) {
			auto crate = slots[from - 1].top();
			slots[from - 1].pop();
			temp.push(crate);
		}
		while(!temp.empty()) {
			auto crate = temp.top();
			temp.pop();
			slots[to - 1].push(crate);
		}
	}

	for (auto& v : slots) {
		if (!v.empty()) {
			result += v.top();
		}
	}
	return result;
}
}
}