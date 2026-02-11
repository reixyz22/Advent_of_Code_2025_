#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>

int main() {
    std::ifstream file("../tests/day_5_test.txt");
    std::string line;
    std::unordered_set<long long> s;

    while (std::getline(file, line)) {
        if (line.empty()) break;

        size_t dash_pos = line.find('-');  // find position of '-'
        long long start = std::stoll(line.substr(0, dash_pos));
        long long end   = std::stoll(line.substr(dash_pos + 1));

        for(long long i = start; i <= end; i++) {
            s.insert(i);
        }
    }

    std::cout << "{ ";
    for (long long x : &s) {
        std::cout << x << " ";
    }std::cout << "}" << std::endl;

    int total = 0;
    while (std::getline(file, line)) {
        std::cout << line << " ";
        if (s.count(std::stoll(line))) {
            total +=1;
        }
    }

    std::cout << "total " << total;

}