#include <vector>
#include <iostream>
#include <algorithm>

static std::vector<int> coins;

static long long do_counts(const int& target) {
	std::vector<std::vector<long long>> T(coins.size(), std::vector<long long>(target + 1, 1));
		    
	for (int j = 1; j < T[0].size(); ++j) {
		if (j % coins[0])
			T[0][j] = 0;
	}
			    
	for (int i = 1, j; i < T.size(); ++i) {
		for (j = 0; j < T[i].size(); ++j) {
			if (j >= coins[i])
				T[i][j] = T[i-1][j] + T[i][j - coins[i]];
			else
			    T[i][j] = T[i-1][j];
		}
	return T[coins.size()-1][target];
}

int main() {
	int n,m;
	std::cin >> n >> m;
	coins.resize(m);
	for (auto& c : coins)
		std::cin >> c;
					    
	std::sort(coins.begin(), coins.end());    
	std::cout << do_counts(n) << '\n';
							    
	return 0;
}

