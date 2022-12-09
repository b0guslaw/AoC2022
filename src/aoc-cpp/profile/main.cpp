#include "../days/day1.hpp"
#include "../days/day2.hpp"
#include "../days/day3.hpp"
#include "../days/day4.hpp"
#include "../days/day5.hpp"
#include "../days/day6.hpp"
#include "../days/day7.hpp"
#include "../days/day8.hpp"
#include "../days/day9.hpp"

#include "../Input.hpp"

#include <benchmark/benchmark.h>

const std::string INPUT_PATH{"../res/"};

static void BM_Day1(benchmark::State& state) {
    auto input = Input::GetIntData(INPUT_PATH + "day1.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day1::Part1(input));
        benchmark::DoNotOptimize(aoc::Day1::Part2(input));
    }
}

static void BM_Day2(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day2.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day2::Part1(input));
        benchmark::DoNotOptimize(aoc::Day2::Part2(input));
    }
}

static void BM_Day3(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day3.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day3::Part1(input));
        benchmark::DoNotOptimize(aoc::Day3::Part2(input));
    }
}

static void BM_Day4(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day4.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day4::Part1(input));
        benchmark::DoNotOptimize(aoc::Day4::Part2(input));
    }
}

static void BM_Day5(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day5.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day5::Part1(input));
        benchmark::DoNotOptimize(aoc::Day5::Part2(input));
    }
}

static void BM_Day6(benchmark::State& state) {
    auto input = Input::GetString(INPUT_PATH + "day6.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day6::Part1(input));
        benchmark::DoNotOptimize(aoc::Day6::Part2(input));
    }
}

static void BM_Day7(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day7.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day7::Part1(input));
        benchmark::DoNotOptimize(aoc::Day7::Part2(input));
    }
}

static void BM_Day8(benchmark::State& state) {
    auto input = Input::GetGrid(INPUT_PATH + "day8.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day8::Part1(input));
        benchmark::DoNotOptimize(aoc::Day8::Part2(input));
    }
}

BENCHMARK(BM_Day1);
BENCHMARK(BM_Day2);
BENCHMARK(BM_Day3);
BENCHMARK(BM_Day4);
BENCHMARK(BM_Day5);
BENCHMARK(BM_Day6);
BENCHMARK(BM_Day7);
BENCHMARK(BM_Day8);

BENCHMARK_MAIN();