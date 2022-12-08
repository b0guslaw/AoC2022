#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

#include <fmt/core.h>
#include <fmt/color.h>

namespace aoc {
namespace Day8 {

bool left_visible(const std::vector<int>& row, size_t pos) {
    bool visible{true};
    for (size_t i{0}; i < pos; i++) {
        if (row[i] >= row[pos]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool right_visible(const std::vector<int>& row, size_t pos) {
    bool visible{true};
    for (size_t i{pos + 1}; i < row.size(); i++) {
        if (row[i] >= row[pos]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool top_visible(const std::vector<std::vector<int>>& grid, size_t row, size_t col) {
    bool visible{true};
    for (size_t i{0}; i < row; i++) {
        if (grid[i][col] >= grid[row][col]) {
            visible = false;
            break;
        }
    }
    return visible;
}

bool bottom_visible(const std::vector<std::vector<int>>& grid, size_t row, size_t col) {
    bool visible{true};
    for (size_t i{row + 1}; i < grid.size(); i++) {
        if (grid[i][col] >= grid[row][col]) {
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

    for (size_t i{1}; i < data.size() - 1; i++) {
        for (size_t j{1}; j < data[i].size() - 1; j++) {
            if (left_visible(data[i], j) ||
                right_visible(data[i], j)||
                top_visible(data, i, j)  ||
                bottom_visible(data, i, j)) {
                    ++sum;
                }
        }
    }

    return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::vector<int>>& data) {
    for (size_t i{1}; i < data.size() - 1; i++) {
        for (size_t j{1}; j < data[i].size() - 1; j++) {

        }
    }
    return 0;
}
}
}