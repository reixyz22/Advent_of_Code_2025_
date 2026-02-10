#include <iostream>
#include <fstream>
#include <string>
#include <deque>

std::string findLargestWithKDigits(const std::string& line, int k) {
    int n = line.length();
    int to_remove = n - k;  // How many digits we need to remove

    if (to_remove <= 0) return line;  // Keep all digits

    std::deque<char> stack;

    for (char digit : line) {
        // Remove smaller digits from the end while we can
        while (!stack.empty() && to_remove > 0 && stack.back() < digit) {
            stack.pop_back();
            to_remove--;
        }
        stack.push_back(digit);
    }

    // Remove remaining digits from the end if needed
    while (to_remove > 0) {
        stack.pop_back();
        to_remove--;
    }

    // Convert deque to string (take first k digits)
    std::string result;
    for (int i = 0; i < k && i < stack.size(); i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    std::ifstream file("../inputs/day_3.txt");
    std::string line;
    long long total = 0;
    const int BATTERIES_ON = 12; // feel free to adjust this as needed including downgrading to '2' to solve part 1

    while (std::getline(file, line)) {
        std::string largest = findLargestWithKDigits(line, BATTERIES_ON);
        long long value = std::stoll(largest);
        total += value;
        std::cout << largest << std::endl;
    }
    
    std::cout << "Total: " << total << std::endl;
    return 0;
}