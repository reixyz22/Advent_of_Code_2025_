#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("../inputs/day_3.txt");
    std::string line;
    int total = 0;
    
    while (std::getline(file, line)) {
        if (line.length() == 1 || line.length() == 2) {
            total += std::stoi(line);
            continue;
        }
        
        int first_digit = line[0] - '0';  // char to int
        int second_digit = 0;
        
        // Process middle digits
        for (size_t i = 1; i < line.length() - 1; i++) {
            int digit = line[i] - '0';
            if (digit > first_digit) {
                first_digit = digit;
                second_digit = 0;
            } else if (digit > second_digit) {
                second_digit = digit;
            }
        }
        
        // Check last digit
        int last_digit = line[line.length() - 1] - '0';
        if (last_digit > second_digit) {
            second_digit = last_digit;
        }
        
        int combined = first_digit * 10 + second_digit;
        total += combined;
        std::cout << combined << std::endl;
    }
    
    std::cout << total << std::endl;
    return 0;
}