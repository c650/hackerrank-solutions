#include <cmath>
#include <vector>
#include <iostream>
#include <utility>
#include <limits>

typedef std::vector<std::vector<int>> matrix;

static int calc_cost(const matrix& a, const matrix& b) {
    int tmp = 0;
    for (size_t i = 0, j; i < a.size(); ++i) {
        for (j = 0; j < a[i].size(); ++j) {
            tmp += std::abs(a[i][j] - b[i][j]);
        }
    }
    return tmp;
}

int main() {
    
    static const size_t size = 3;
        
    matrix grid(size, std::vector<int>(size));
    
    for (auto& r : grid) {
        for (auto& e : r) {
            std::cin >> e;
        }
    }
    
    int cost = std::numeric_limits<int>::max();
    
    std::vector<matrix> all = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    
    for (auto& m : all)
        cost = std::min(cost, calc_cost(grid, m));
    
    /* http://www.dr-mikes-math-games-for-kids.com/3x3-magic-square.html is a solid read. */

    std::cout << cost << '\n';
    
    
    return 0;
}

