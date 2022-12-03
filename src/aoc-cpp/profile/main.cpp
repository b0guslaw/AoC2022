#include "../days/day1.hpp"
#include "../days/day2.hpp"
#include "../days/day3.hpp"

#include "../Input.hpp"

#include <benchmark/benchmark.h>

const std::string INPUT_PATH{"../res/"};

static void BM_Day1_Part1(benchmark::State& state) {
    auto input = Input::GetIntData(INPUT_PATH + "day1.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day1::Part1(input));
    }
}

static void BM_Day1_Part2(benchmark::State& state) {
    auto input = Input::GetIntData(INPUT_PATH + "day1.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day1::Part2(input));
    }
}

static void BM_Day2_Part1(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day2.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day2::Part1(input));
    }
}

static void BM_Day2_Part2(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day2.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day2::Part2(input));
    }
}

static void BM_Day3_Part1(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day3.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day3::Part1(input));
    }
}

static void BM_Day3_Part2(benchmark::State& state) {
    auto input = Input::GetStringData(INPUT_PATH + "day3.txt");
    for (auto _: state) {
        benchmark::DoNotOptimize(aoc::Day3::Part2(input));
    }
}

BENCHMARK(BM_Day1_Part1);
BENCHMARK(BM_Day1_Part2);
BENCHMARK(BM_Day2_Part1);
BENCHMARK(BM_Day2_Part2);
BENCHMARK(BM_Day3_Part1);
BENCHMARK(BM_Day3_Part2);

BENCHMARK_MAIN();