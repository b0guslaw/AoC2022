#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <vector>

namespace Input
{
	/**
	 * @brief Opens a file and reads the contents based on the delimiter to an std::vector
	 * @tparam T 
	 * @param path 
	 * @param delim 
	 * @return std::vector<T> 
	 */
	template<typename T>
	std::vector<T> GetData(const std::string& path, char delim = ' ') {
		std::vector<T> data;
		try {
			std::ifstream infile(path);
			std::string line;
			while(std::getline(infile, line, delim)) {
				T element;
				std::stringstream input(line);
				while(input >> element)
					data.push_back(element);
			}
		} catch (...) {
			std::cout << "An error occured!\n";
		}
		return data;
	}

	/**
	 * @brief Opens a file and reads the contents based on the delimiter to an std::vector
	 * @tparam T 
	 * @param path 
	 * @param delim 
	 * @return std::vector<T> 
	 */
	std::vector<std::vector<int>> GetGrid(const std::string& path) {
		std::vector<std::vector<int>> data;
		try {
			std::ifstream infile(path);
			std::string line;
			while(std::getline(infile, line)) {
				std::vector<int> temp;
				for (size_t j{0}; j < line.length(); j++) {
					temp.push_back(line[j] - '0');
				}
				data.push_back(temp);
			}
		} catch (...) {
			std::cout << "An error occured!\n";
		}
		return data;
	}

	/**
	 * @brief Special case of GetStringData which considers the input to have empty lines.
	 * The input file will be treated as strings, where each line is stored as element
	 * in an std::vector
	 * @param path 
	 * @return std::vector<std::string> 
	 */
	std::vector<std::string> GetEmptyNewLineData(const std::string& path) {
		std::ifstream infile(path);
		std::string temp;
		std::vector<std::string> data;
		for (std::string line; std::getline(infile, line); ) {
			if (line.empty()) {
				data.push_back(temp);
				temp.clear();
			}
			if (infile.eof()) {
				temp += line;
				data.push_back(temp);
			}
			temp += line;
			temp += " ";
		}
		return data;
	}

	/**
	 * @brief Reads each line of an input file into an std::vector
	 * @param path 
	 * @return std::vector<std::string> 
	 */
	std::vector<std::string> GetStringData(const std::string& path){
		std::vector<std::string> data;
		try {
			std::ifstream infile(path);
			for(std::string line; std::getline(infile, line); ) {
				data.push_back(line);
			}
		} catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}
		return data;
	}

	/**
	 * @brief Reads the entire file into a string
	 * @param path 
	 * @return std::string
	 */
	std::string GetString(const std::string& path){
		std::ifstream ifs(path);
		std::string data((std::istreambuf_iterator<char>(ifs)),
                 std::istreambuf_iterator<char>());
		return data;
	}

	/**
	 * @brief Reads each line of an input file into an std::vector<int64_t>
	 * @param path 
	 * @return std::vector<std::int64_t> 
	 */
	std::vector<std::int64_t> GetIntData(const std::string& path){
		std::vector<std::int64_t> data;
		try {
			std::ifstream infile(path);
			for(std::string line; std::getline(infile, line); ) {
				if (line.empty()) {
					data.push_back(0);
				} else {
					data.push_back(std::stoll(line));
				}
			}
		} catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}
		return data;
	}
};