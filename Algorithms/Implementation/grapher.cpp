// for queen problem

#include <iostream>
#include <vector>

int main() {
	int n,k;
	std::cin >> n >> k;

	std::vector<std::vector<char>> grid(n, std::vector<char>(n, '-'));

	int x,y;
	std::cin >> x >> y;
	grid[n - y][x-1] = 'Q';

	while (k-->0) {
		std::cin >> x >> y;
		grid[n - y][x - 1] = 'X';
	}

	for (auto& r : grid) {
		for (auto& e : r)
			std::cout << e << ' ';
		std::cout << '\n';
	}
	return 0;
}
