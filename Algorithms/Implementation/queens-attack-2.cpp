// not yet passing bigger TCs

#include <cmath>
#include <vector>
#include <iostream>
#include <utility>

int main() {
    size_t n,k;
    std::cin >> n >> k;

    std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, true));

    std::pair<size_t, size_t> queen, tmp;

    std::cin >> queen.first >> queen.second;
    --queen.first; --queen.second;

    while(k-->0) {
        std::cin >> tmp.first >> tmp.second;
        grid[tmp.first-1][tmp.second-1] = false;
    }

    int count = 0, i, j;

    // upper left
    for (i = queen.first-1, j = queen.second-1; i >= 0 && j >= 0 && grid[i][j]; --i, --j) {
		++count;
	}

    // upper right
    for (i = queen.first-1, j = queen.second+1; i >= 0 && j < n && grid[i][j]; --i, ++j) {
        ++count;
	}
    // lower left
    for (i = queen.first+1, j = queen.second-1; i < n && j >= 0 && grid[i][j]; ++i, --j) {
        ++count;
	}
    // lower right
    for (i = queen.first+1, j = queen.second+1; i < n && j < n && grid[i][j]; ++i, ++j) {
        ++count;
	}
    // up
    for (i = queen.first-1, j = queen.second; i >= 0 && grid[i][j]; --i) {
        ++count;
	}
    // down
    for (i = queen.first+1, j = queen.second; i < n && grid[i][j]; ++i) {
        ++count;
	}
    // left
    for (i = queen.first, j = queen.second-1; j >= 0 && grid[i][j]; --j) {
        ++count;
	}
    // right
    for (i = queen.first, j = queen.second+1; j < n && grid[i][j]; ++j) {
        ++count;
	}

    std::cout << count << '\n';

    return 0;
}
