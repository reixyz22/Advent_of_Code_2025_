#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("../inputs/day_5.txt");
    std::string line;
    std::vector<std::pair<long long, long long>> ranges;

    while (std::getline(file, line)) {
        if (line.empty()) break; // this means we are ignoring the second part of the data--- as per the spec

        size_t dash_pos = line.find('-');  // find position of '-'
        long long start = std::stoll(line.substr(0, dash_pos));
        long long end   = std::stoll(line.substr(dash_pos + 1));

        ranges.emplace_back(start, end);

    }
    //sort lexigraphically, start of range in ascending order-- if tied, end of range.
    std::sort(ranges.begin(), ranges.end());

    //we need to construct a copy as changing in place while iterating is not safe behavior
    std::vector<std::pair<long long,long long>> merged;
    merged.emplace_back(ranges[0]);

    for (size_t i = 1; i < ranges.size(); ++i) {
        auto& last = merged.back();
        auto& current = ranges[i];

        // If overlapping or adjacent
        if (current.first <= last.second) {
            last.second = std::max(last.second, current.second); // merge
        } else {
            merged.push_back(current);
        }
    }

    long long total = 0;
    for(auto [start, end]: merged) {
        // count the numbers in the range through math rather than iterating through manually
        total += (end - (start - 1) ); // make sure to count the starting number 1-10 is 10 numbers not 9
    }

    std::cout << total;

}