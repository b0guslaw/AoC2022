#pragma once

#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <string_view>
#include <memory>
#include <iostream>
#include <unordered_map>

namespace aoc {
namespace Day7 {

struct File {
    File(const std::string&& n, std::shared_ptr<File> p) : name{std::move(n)}, parent{p} {}
    std::string name;
    std::shared_ptr<File> parent;
    std::vector<std::shared_ptr<File>> subdir;
    std::uint64_t size{0};
};

std::shared_ptr<File> init_fs(const std::vector<std::string>& data) {
    const auto root = std::make_shared<File>("/", nullptr);
    auto current = root;

    for (size_t i{1}; i < data.size(); i++) {
        const std::string& line(data[i]);
        if (line[0] == '$') {
            if (line[2] == 'c') {
                const std::string& new_dir{data[i].substr(5, data[i].size() - 1)};
                if (new_dir[0] == '/') {
                    current = root;
                } else if (new_dir[0] == '.') {
                    current = current->parent;
                } else {
                    auto dir = std::make_shared<File>(data[i].substr(4, data[i].size() - 1), current);
                    current->subdir.push_back(dir);
                    current = dir;
                }
            }
        }
        else if (data[i][0] == 'd') {
            current->subdir.push_back(std::make_shared<File>(data[i].substr(4, data[i].size() - 1), current));
        } else {
            std::uint64_t sz{std::stoull(data[i])};
            auto space = data[i].find_last_of(' ');
            std::string name{data[i].substr(space, data[i].length() - space)};
            auto file = std::make_shared<File>(std::move(name), current);
            file->size = sz;
            current->subdir.push_back(std::move(file));
        }
    }
    return root;
}


std::uint64_t get_sizep1(const std::shared_ptr<File>& file, std::uint64_t& sump1) {
    if (file->subdir.empty()) {
        return file->size;
    }
    std::uint64_t sum{0};
    for (const auto& f : file->subdir) {
        sum += get_sizep1(f, sump1);
    }
    if (sum <= 100000) {
        sump1 += sum;
    }
    return sum;
}

std::uint64_t get_sizep2(const std::shared_ptr<File>& file, std::unordered_map<std::string, std::uint64_t>& sump2) {
    if (file->subdir.empty()) {
        return file->size;
    }
    std::uint64_t sum{0};
    for (const auto& f : file->subdir) {
        sum += get_sizep2(f, sump2);
    }
    sump2[file->name] = sum;
    return sum;
}

std::uint64_t Part1([[maybe_unused]] const std::vector<std::string>& data) {    
    std::uint64_t sum{0};
    auto root = init_fs(data);
    get_sizep1(root, sum);
    return sum;
}

std::uint64_t Part2([[maybe_unused]] const std::vector<std::string>& data) {
    auto root = init_fs(data);
    std::unordered_map<std::string, std::uint64_t> sizes;
    std::uint64_t unused = 70000000 - get_sizep2(root, sizes);
    const std::uint64_t target{30000000};
    std::uint64_t min{70000000};
    for (const auto& [name, value] : sizes) {
        std::uint64_t space = unused + value;
        if (space >= target && value < min) {
            min = value;
        }
    }
    return min;
}
}
}