#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <chrono>
#include <tuple>
#include <functional>

#include <fmt/core.h>
#include <fmt/color.h>

#include "Input.hpp"

#include "days/day1.hpp"
#include "days/day2.hpp"
#include "days/day3.hpp"
#include "days/day4.hpp"
#include "days/day5.hpp"

const std::string INPUT_PATH{"res/"};
uint64_t day_count{0};

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
    std::uint64_t result = func(input);
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return std::make_tuple(result, elapsed);
}

template<typename T, typename F1, typename F2>
void DayRunner(F1 f1, F2 f2, const std::vector<T>& data) {
	auto [result1, elapsed1] = Runner(f1, data);
	auto [result2, elapsed2] = Runner(f2, data);
    fmt::print("Day {} results:\n" , ++day_count);
	print(result1, elapsed1, result2, elapsed2);
}

void Day5_Runner(const std::vector<std::string>& data) {
    auto sprint = [](const std::string solution, double elapsed, int part){
        fmt::print(fmt::emphasis::bold,
            "\tPart {}: {} finished after {}us\n", part, solution, elapsed
        );
    };

    fmt::print("Day {} results:\n" , ++day_count);

    auto start1 = std::chrono::high_resolution_clock::now();
    std::string result1 = aoc::Day5::Part1(data);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto start2 = std::chrono::high_resolution_clock::now();
    std::string result2 = aoc::Day5::Part2(data);
    auto end2 = std::chrono::high_resolution_clock::now();
    double elapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();
    double elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();
    sprint(result1, elapsed1, 1);
    sprint(result2, elapsed2, 2);
}

int main() {
    DayRunner<std::int64_t>(aoc::Day1::Part1, aoc::Day1::Part2, Input::GetIntData(INPUT_PATH + "day1.txt"));
    DayRunner<std::string>(aoc::Day2::Part1, aoc::Day2::Part2, Input::GetStringData(INPUT_PATH + "day2.txt"));
    DayRunner<std::string>(aoc::Day3::Part1, aoc::Day3::Part2, Input::GetStringData(INPUT_PATH + "day3.txt"));
    DayRunner<std::string>(aoc::Day4::Part1, aoc::Day4::Part2, Input::GetStringData(INPUT_PATH + "day4.txt"));
    Day5_Runner(Input::GetStringData(INPUT_PATH + "day5.txt"));
}
