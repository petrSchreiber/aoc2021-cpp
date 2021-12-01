#include "day01.hpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>


static auto get_ints_from_file(const std::string& fileName) {
    std::ifstream input{ fileName };

    if (!input) {
        throw std::string("Could not open file ") + fileName;
    }

    return std::vector<int>(std::istream_iterator<int>{input},  // reads ints ignoring whitespaces (can be configured)
        std::istream_iterator<int>{});
}

int solve_part_1(const std::vector<int>& values) {
    int result = 0;
    const auto itemCount = values.size();

    if (itemCount < 2) {
        return 0;
    }

    for (int i = 1; i < itemCount; ++i) {
        if (values[i] > values[i - 1]) {
            result++;
        }
    }

    return result;
}

int solve_part_2(const std::vector<int>& values) {
    int result = 0;
    const auto itemCount = values.size();

    if (itemCount < 4) {
        throw std::string("Input for part 2 does not contain enough data, at least 4 numbers are needed");
    }
    auto start = values.begin();
    for (int i = 0; i < itemCount-3; ++i) {
        auto first = std::accumulate(start, start + 3, 0);
        auto second = std::accumulate(start+1, start + 4, 0);
        start++;

        if (first < second) {
            result++;
        }        
    }

    return result;
}

int day01::solve(const std::string& fileName) {
    std::cout << "-= Day 01 =-\n";
    std::string day01_input{ fileName };

    std::vector<int> values = get_ints_from_file(fileName);
    
    try {
        std::cout << "Part A:" << std::endl << solve_part_1(values) << std::endl;
        std::cout << "Part B:" << std::endl << solve_part_2(values) << std::endl;

        return 0;

    }
    catch (std::string errorDescription) {
        std::cerr << errorDescription;

        return 1;
    }
}