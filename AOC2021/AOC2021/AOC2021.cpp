#include "day01.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Advent of Code 2021\n\n";

    if (argc != 2) {
        std::cerr << "Exactly one argument expected:\nmain <inputFile>.";

        return EXIT_FAILURE;
    }

    day01::solve(argv[1]);
}
