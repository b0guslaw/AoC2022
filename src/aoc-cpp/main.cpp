#include <cstdint>
#include <iostream>
#include <string>
#include <chrono>
#include <tuple>

#include <fmt/core.h>
#include <fmt/color.h>

#include "Input.hpp"

#include "days/day1.hpp"

const std::string INPUT_PATH{"res/"};

auto print = [](const uint64_t part1, double elapsed1, const uint64_t part2, double elapsed2){
    fmt::print(fmt::emphasis::bold,
        "\tPart 1: {} finished after {}us\n", part1, elapsed1
    );
    fmt::print(fmt::emphasis::bold,
        "\tPart 2: {} finished after {}us\n", part2, elapsed2
    );
};

template<typename F, typename I>
std::tuple<uint64_t, double> Runner(F func, const std::vector<I> input) {
		auto start = std::chrono::high_resolution_clock::now();
		uint64_t result = func(input);
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		return std::make_tuple(result, elapsed);
}

template<typename T, typename F1, typename F2>
void DayRunner(F1 f1, F2 f2, const std::vector<T>& data) {
	auto [result1, elapsed1] = Runner(f1, data);
	auto [result2, elapsed2] = Runner(f2, data);
    static uint64_t day_count{0};
    fmt::print("Day {} results:\n" , ++day_count);
	print(result1, elapsed1, result2, elapsed2);
}

int main() {
    DayRunner<std::string>(aoc::Day1::Part1, aoc::Day1::Part2, Input::GetStringData(INPUT_PATH + "day1.txt"));
}
