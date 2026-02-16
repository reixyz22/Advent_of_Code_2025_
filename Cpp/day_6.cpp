#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<std::string>> transpose(const std::vector<std::vector<std::string>>& matrix) {
    std::vector<std::vector<std::string>> result;

    int rows = matrix.size();
    int cols = matrix[0].size();

    // create transposed matrix with swapped dimensions
    result.resize(cols, std::vector<std::string>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}



int main() {
    std::ifstream file("../inputs/day_6.txt");
    std::string line;

    std::vector<std::vector<std::string>> homework;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> row;
        std::string token;

        while (iss >> token) { // extracts numbers separated by spaces
            row.push_back(token);
        }

        homework.push_back(row);
    }

    // this confirmed the line lenghts and helped me finaly understand the messy looking input
    // for (const auto& row : homework) {
    //     std::cout << " "<< row.size() <<" ";
    // }

    //rotate the matrix
    std::vector<std::vector<std::string>> transposed = transpose(homework);
    long long grand_total = 0;

    for (auto &row : transposed) { // per every transposed row
        long long total = 0;
        bool multiply;
        if ( row[row.size()-1] == "*") {
            multiply = true;
            total = 1;
        }else {
            multiply = false; // add
        }
        row.pop_back(); // just remove the operator after we noted it, avoids type issues later on.

        for (const std::string& val : row) {
            if (multiply){
                total *= std::stoi(val);
            }else {
                total += std::stoi(val);
            }
        }

        grand_total += total;
    }

    std::cout << grand_total;
}
