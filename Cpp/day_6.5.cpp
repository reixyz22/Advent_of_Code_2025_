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
    //std::ifstream file("../tests/day_6_test.txt");
    std::string line;

    std::vector<std::vector<char>> homework;

    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(),line.end());
        homework.push_back(row);
    }

    //Debugging input
    // for (const auto& row : homework) {
    //     for (char c : row) {
    //         std::cout << c;
    //     }
    // }
    // alternate style that i learned in school for syntax referance / study
    // for ( int i : homework.size())
    //     for (char c : homework[i]) {
    //         std::cout << c;
    // }

    long long total = 0;

    std:: vector<int> cols;
    bool m = true;

    for(int i = 0; i < homework[0].size(); i++) {
        std::string col_string;
        for (int j = 0; j < homework.size(); j++) {
            if (homework[j][i] == '*') { //needs to be j i since we are doing col row iteration.
                m = true;
            }
            else if (homework[j][i] == '+') {
                m = false;
            }
            else if (homework[j][i] != ' ') {
                col_string += homework[j][i];
            }

            if ( j == homework.size() -1 and !col_string.empty()) { // end of col and if the col isn't empty load it in
                cols.push_back(std::stoi(col_string));
            }

            // without buffer the last entry col becomes a nasty edge case FIXED*
            if (j == homework.size() -1 and col_string.empty() or
                j == homework.size() -1  and i == homework[0].size() - 1) {
                if (m) {
                    total += multiply(cols);
                }
                else {
                    total += addition(cols);
                }
                cols = {};
            }

        }
    }
    std::cout << total;
}
