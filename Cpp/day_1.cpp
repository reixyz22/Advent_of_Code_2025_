#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = R"(..\inputs\day_1.txt)";

    int dial = 50;
    int zeros = 0;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        char direction = line[0];
        int value = std::stoi(line.substr(1));

        if (direction == 'R') {
            dial += value;
        } else {
            dial -= value;
        }

        while (dial > 99) {
            dial -= 100;
        }

        while (dial < 0) {
            dial += 100;
        }


        if (dial == 0) {
            zeros++;
        }
    }

    file.close();
    std::cout << zeros << std::endl;

    return 0;
}