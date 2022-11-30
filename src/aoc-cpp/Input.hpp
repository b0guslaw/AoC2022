#pragma once

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
		std::ifstream infile(path);
		for(std::string line; std::getline(infile, line); ) {
			data.push_back(line);
		}
		return data;
	}
};