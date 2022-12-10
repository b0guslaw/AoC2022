#pragma once

#include <cstdint>
#include <limits>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>

namespace aoc {
namespace Day8 {

bool left_visible(const std::vector<int>& row, size_t pos, std::uint64_t& sum) {
    bool visible{true};
    for (size_t i{pos}; i > 0; i--) {
        sum++;
        if (row[i - 1] >= row[pos]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool right_visible(const std::vector<int>& row, size_t pos, std::uint64_t& sum) {
    bool visible{true};
    for (size_t i{pos}; i < row.size() - 1; i++) {
        sum++;
        if (row[i + 1] >= row[pos]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool top_visible(const std::vector<std::vector<int>>& grid, size_t row, size_t col, std::uint64_t& sum) {
    bool visible{true};
    for (size_t i{row}; i > 0; i--) {
        sum++;
        if (grid[i - 1][col] >= grid[row][col]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool bottom_visible(const std::vector<std::vector<int>>& grid, size_t row, size_t col, std::uint64_t& sum) {
    bool visible{true};
    for (size_t i{row}; i < grid.size() - 1; i++) {
        sum++;
        if (grid[i + 1][col] >= grid[row][col]) {
            visible = false;
            break;
        }
    }
    return visible;
}


std::uint64_t Part1([[maybe_unused]] const std::vector<std::vector<int>>& data) {    
    std::uint64_t sum{0};

    sum += (2 * data.size());
    sum += (2 * data[0].size());
    sum -= 4;

    std::uint64_t discard{0};

    for (size_t i{1}; i < data.size() - 1; i++) {
        for (size_t j{1}; j < data[i].size() - 1; j++) {
            if (left_visible(data[i], j, discard)  ||
                right_visible(data[i], j, discard) ||
                top_visible(data, i, j, discard)   ||
                bottom_visible(data, i, j, discard)) {
                    ++sum;
            }
        }
    }
    return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::vector<int>>& data) {
    std::uint64_t max{std::numeric_limits<std::uint64_t>::min()};
    for (size_t i{1}; i < data.size() - 1; i++) {
        for (size_t j{1}; j < data[i].size() - 1; j++) {
            std::uint64_t temp{0};
            std::uint64_t left{0}, right{0}, top{0}, bottom{0};
            left_visible(data[i], j, left);
            right_visible(data[i], j, right);
            top_visible(data, i, j, top);
            bottom_visible(data, i, j, bottom);

            //fmt::print("{} = {} * {} * {} * {}\n", temp, top, left, bottom, right);
            temp = left * right * top * bottom;
            if (max < temp) {
                max = temp;
            }
        }
    }
    return max;
}
}
}