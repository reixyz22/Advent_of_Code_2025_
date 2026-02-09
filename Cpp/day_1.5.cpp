#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("../inputs/day_1.txt");
    std::string line;

    int dial = 50;
    int clicks = 0;

    while (std::getline(file, line)) {
        char direction = line[0];           // 'L' or 'R'
        int value = std::stoi(line.substr(1));  // number part

        if (direction == 'R') {
            dial += value;
            clicks += dial / 100;  // integer division (like // in Python)
            dial = dial % 100;
        } else {  // 'L'
            if (dial == 0) {
                clicks -= 1;
            }
            dial -= value;
            while (dial < 0) {
                dial += 100;
                clicks += 1;
            }
            if (dial == 0) {
                clicks += 1;
            }
        }
    }

    std::cout << clicks << std::endl;
    return 0;
}