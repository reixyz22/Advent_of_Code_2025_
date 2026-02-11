#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("../inputs/day_5.txt");
    std::string line;
    std::vector<std::pair<long long, long long>> ranges;

    while (std::getline(file, line)) {
        if (line.empty()) break;

        size_t dash_pos = line.find('-');  // find position of '-'
        long long start = std::stoll(line.substr(0, dash_pos));
        long long end   = std::stoll(line.substr(dash_pos + 1));

        ranges.emplace_back(start, end);

    }

    int total = 0;
    while (std::getline(file, line)) {
        for(auto [start,end] : ranges) {
            if (std::stoll(line) >= start && std::stoll(line) <= end) {
                total +=1;
                break; // we have to break out of the loop so we don't duplicate-- previous method in test didn't need this
            }
        }
    }

    std::cout << total;

}