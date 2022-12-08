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
#include "days/day6.hpp"
#include "days/day7.hpp"
#include "days/day8.hpp"

const std::string INPUT_PATH{"res/"};
uint64_t day_count{0};

template<typename T, typename R, typename F>
std::tuple<R, double> Executor(F func, const T& data) {
    auto start = std::chrono::high_resolution_clock::now();
    R result = func(data);
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return std::make_tuple(result, elapsed);
}

template<typename T, typename R, typename F1, typename F2>
void Execute(F1 f1, F2 f2, const T& data) {
  	auto [result1, elapsed1] = Executor<T, R>(f1, data);
	auto [result2, elapsed2] = Executor<T, R>(f2, data);
    fmt::print("Day {} results:\n" , ++day_count);
	    fmt::print(fmt::emphasis::bold,
        "\tPart 1: {} finished after {}us\n", result1, elapsed1
    );
    fmt::print(fmt::emphasis::bold,
        "\tPart 2: {} finished after {}us\n", result2, elapsed2
    );  
}

int main() {
    //Execute<std::vector<std::int64_t>, std::int64_t>(aoc::Day1::Part1, aoc::Day1::Part2, Input::GetIntData(INPUT_PATH + "day1.txt"));
    //Execute<std::vector<std::string>, std::int64_t>(aoc::Day2::Part1, aoc::Day2::Part2, Input::GetStringData(INPUT_PATH + "day2.txt"));
    //Execute<std::vector<std::string>, std::int64_t>(aoc::Day3::Part1, aoc::Day3::Part2, Input::GetStringData(INPUT_PATH + "day3.txt"));
    //Execute<std::vector<std::string>, std::int64_t>(aoc::Day4::Part1, aoc::Day4::Part2, Input::GetStringData(INPUT_PATH + "day4.txt"));
    //Execute<std::vector<std::string>, std::string>(aoc::Day5::Part1, aoc::Day5::Part2, Input::GetStringData(INPUT_PATH + "day5.txt"));
    //Execute<std::string, std::uint64_t>(aoc::Day6::Part1, aoc::Day6::Part2, Input::GetString(INPUT_PATH + "day6.txt"));
    //Execute<std::vector<std::string>, std::int64_t>(aoc::Day7::Part1, aoc::Day7::Part2, Input::GetStringData(INPUT_PATH + "day7.txt"));
    Execute<std::vector<std::vector<int>>, std::uint64_t>(aoc::Day8::Part1, aoc::Day8::Part2, Input::GetGrid(INPUT_PATH + "day8.txt"));
}
