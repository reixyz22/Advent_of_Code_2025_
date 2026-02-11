#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::ifstream file("../tests/day_4_test.txt");
    std::string line;
    std::vector<std::string> grid;
    while (std::getline(file, line)) {
        grid.push_back(line);
    }

    long long total = 0;

    //2d array loop
    for(int i = 0; i < grid.size();i++) {
        for(int j = 0;j < grid[i].size();j++) {
            if (grid[i][j] =='@'){
                int neighboring_paper = 0;

                //offset loop -- looks funky but these loops are O(1) -1, 0, 1 X 2 = 9 iterations
                for(int mod_i = -1; mod_i <= 1; mod_i++) {
                    for(int mod_j = -1; mod_j <= 1; mod_j++) {

                        if(mod_i == 0 && mod_j == 0) continue;

                        //sanity check that we are in bounds, around the edges-- if not do nothing IE nothing below this check
                        if(i+mod_i >= 0 && i+mod_i < grid.size() &&
                           j+mod_j >= 0 && j+mod_j < grid[i].size() ) {
                                neighboring_paper += (grid[i+mod_i][j+mod_j] =='@');
                           }
                    }
                }

                if (neighboring_paper < 4){
                    total += 1;
                }std::cout << neighboring_paper;
            }else std::cout << ".";
        }std::cout << "\n";
    }

    std::cout << total;
    return 0;
}