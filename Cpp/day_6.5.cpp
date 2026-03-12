//
// Created by pitts on 2/17/2026.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

long long multiply(const std::vector<int>& multiples) {
    long long total = 1;
    for (int x : multiples) {
        total *= x;
    }
    return total;
}

long long addition(const std::vector<int>& adders) {
    long long total = 0;
    for (int x : adders) {
        total += x;
    }
    return total;
}

int main() {
    std::ifstream file("../inputs/day_6.txt");
    std::string line;

    std::vector<std::vector<char>> homework;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<char> row(line.begin(),line.end());


        homework.push_back(row);
    }

    for (const auto& row : homework) {
        for (char c : row) {
            std::cout << c;
        }
    }
    // alternate style that i learned in school for syntax referance / study
    // for ( int i : homework.size())
    //     for (char c : homework[i]) {
    //         std::cout << c;
    // }
}
