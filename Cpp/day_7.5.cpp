#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::vector<char>> get_input(const std::string& s) {
    std::ifstream file(s);
    std::string line;

    std::vector<std::vector<char>> v;

    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(),line.end());
        v.push_back(row);
    }
    return v;
}

long long recursive_solution(int row, int col, const std::vector<std::vector<char>> &homework, std::vector<std::vector<long long>> &memo) {
    //base case
    if (row >= homework.size()) {
        return 1;
    }

    //edge case
    if (col < 0 || col >= homework[row].size()) {
        return 0;
    }

    //Memoization
    if (memo[row][col] != -1) {
        return memo[row][col];  // Already calculated
    }

    //split case
    if (homework[row][col] == '^'){
        memo[row][col] = recursive_solution(row + 1, col - 1, homework, memo) + recursive_solution( row + 1, col + 1, homework, memo);
        return memo[row][col];
    }
    // move down case
    memo[row][col] = recursive_solution(row + 1, col, homework,memo);
    return memo[row][col];
}

int main() {
    std::string file = "../inputs/day_7.txt";
    //std::string file = "../tests/day_7_test.txt";
    std::vector<std::vector<char>> homework = get_input(file);

    int start_row;
    int start_col;

    for(int i = 0 ; i < homework.size(); i++){
        for(int j = 0; j < homework[i].size(); j++){
            if (homework[i][j] == 'S') {
                start_row = i;
                start_col = j;
            }
        }
    }
    std::vector<std::vector<long long>> memo(homework.size(), std::vector<long long>(homework[0].size(), -1));
    std::cout << recursive_solution(start_row, start_col, homework, memo);

}