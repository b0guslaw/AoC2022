#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

namespace aoc {
namespace Day5 {

std::vector<std::stack<char>> get_stacks(const std::vector<std::string>& data) {
	std::vector<std::stack<char>> slots{9};
	auto ground = data.begin();
	for (auto it = data.begin(); !it->empty(); it++) {
		ground = it;
	}
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
	return slots;
}

std::array<int, 3> get_command(const std::string& line) {
	std::istringstream iss{line};
	std::string buffer;
	int pos{0};

	int amount{0};
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

	return std::array<int, 3>{amount, from - 1, to - 1};
}

std::string Part1([[maybe_unused]] const std::vector<std::string>& data) {
	std::string result{};
	auto slots = get_stacks(data);

	auto instruction_start = data.begin();
	while (!instruction_start->empty()) {
		instruction_start++;
	}

	for (auto it = instruction_start + 1; it != data.end(); it++) {
        if (it->empty()) {
            break;
        }

		auto command = get_command(*it);
		for (int i{0}; i < command[0]; i++) {
			auto crate = slots[command[1]].top();
			slots[command[1]].pop();
			slots[command[2]].push(crate);
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
	std::string result{};
	auto slots = get_stacks(data);

	auto instruction_start = data.begin();
	while (!instruction_start->empty()) {
		instruction_start++;
	}

	for (auto it = instruction_start + 1; it != data.end(); it++) {
        if (it->empty()) {
            break;
        }
		auto command = get_command(*it);
		std::stack<char> temp;
		for (int i{0}; i < command[0]; i++) {
			auto crate = slots[command[1]].top();
			slots[command[1]].pop();
			temp.push(crate);
		}
		while(!temp.empty()) {
			auto crate = temp.top();
			temp.pop();
			slots[command[2]].push(crate);
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