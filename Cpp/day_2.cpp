#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

bool symmetry_checker(const std::string& s) {
    int half = s.length() / 2;
    if (half > 0 && s.substr(0, half) == s.substr(half)) {
        return true;
    }
    return false;
}

int main() {
    //get the first line (this input is only one line)
    std::ifstream file("../inputs/day_2.txt");
    std::string line;
    std::getline(file, line);

    // Split by comma and append to a vector
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> id_ranges;
    while (std::getline(ss, token, ',')) {
        id_ranges.push_back(token);
    }

    long long total = 0;

    for (const auto& id_range : id_ranges) {
        // split start and end
        size_t dash_pos = id_range.find('-');  // find position of '-'
        std::string start = id_range.substr(0, dash_pos);           // subtring prior to the dash
        std::string end = id_range.substr(dash_pos + 1);            // subtring after the dash
        //we dynamically swap types from int to string and back for iterability & function use
        //we could've also had the function take an int and convert within the function so this is a design choice.
        for(long long i = std::stoll(start); i <= std::stoll(end);i++ ) {
            if(symmetry_checker(std::to_string(i))) {
                total += i;
            }
        }
    }


    std::cout << total << std::endl;
    return 0;
}