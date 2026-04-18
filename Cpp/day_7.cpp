#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

void print_vector(const std::vector<std::vector<char>>& v){
    for (const auto& row : v) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

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

int main() {
    std::string file = "../inputs/day_7.txt";
    std::vector<std::vector<char>> homework = get_input(file);
    int split_count = 0;

    for(int i = 0; i < homework.size() - 1; i++) {
        for (int j = 0; j < homework[i].size(); j++) {

            if(homework[i][j] == 'S') {
                if ( homework[i+1][j] == '^') {
                    split_count += 1;
                    homework[i+1][j-1] = 'S';
                    homework[i+1][j+1] = 'S';
                }
                else {
                    homework[i+1][j] = 'S';
                }}

        }
    }
    // print_vector(homework); //note this only looks reasonable on bite sized inputs. IE the test
    std::cout << split_count;

}