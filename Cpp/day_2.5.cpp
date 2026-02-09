#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

// Returns two vectors of factors (small and large pairs)
std::pair<std::vector<int>, std::vector<int>> factor(int n) {
    std::vector<int> factors_small, factors_large;
    
    for (int i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            factors_small.push_back(i);
            factors_large.push_back(n / i);
        }
    }
    
    return {factors_small, factors_large};
}

bool repeat_checker(const std::string& s, 
                   const std::vector<int>& factors_small,
                   const std::vector<int>& factors_large) {
    
    for (size_t i = 0; i < factors_small.size(); i++) {
        if (i == 0) {
            // Check if all same character
            if (s == std::string(s.length(), s[0])) {
                return true;
            }
        } else {
            int v = factors_small[i];
            int large = factors_large[i];
            
            // Check both pattern possibilities
            std::string pattern1 = s.substr(0, v);
            std::string pattern2 = s.substr(0, large);
            
            std::string repeated1 = "";
            std::string repeated2 = "";
            
            for (int j = 0; j < large; j++) repeated1 += pattern1;
            for (int j = 0; j < v; j++) repeated2 += pattern2;
            
            if (s == repeated1 || s == repeated2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ifstream file("../inputs/day_2.txt");
    std::string line;
    std::getline(file, line);
    
    // Split by comma
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> id_ranges;
    while (std::getline(ss, token, ',')) {
        id_ranges.push_back(token);
    }
    
    // Pre-compute factors for all lengths
    int biggest_length = 0;
    for (const auto& id_range : id_ranges) {
        size_t dash = id_range.find('-');
        std::string end_str = id_range.substr(dash + 1);
        if ((int)end_str.length() > biggest_length) {
            biggest_length = end_str.length();
        }
    }
    
    std::map<int, std::pair<std::vector<int>, std::vector<int>>> factored;
    for (int i = 1; i <= biggest_length; i++) {
        factored[i] = factor(i);
    }
    
    // Process ranges
    long long total = 0;
    
    for (const auto& id_range : id_ranges) {
        size_t dash = id_range.find('-');
        long long start = std::stoll(id_range.substr(0, dash));
        long long end = std::stoll(id_range.substr(dash + 1));
        
        for (long long num = start; num <= end; num++) {
            if (num > 10) {
                std::string num_str = std::to_string(num);
                auto [factors_small, factors_large] = factored[num_str.length()];
                
                if (repeat_checker(num_str, factors_small, factors_large)) {
                    total += num;
                }
            }
        }
    }
    
    std::cout << total << std::endl;
    return 0;
}