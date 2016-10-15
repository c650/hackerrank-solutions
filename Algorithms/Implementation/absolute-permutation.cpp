#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t,n,k;
    std::cin >> t;

    std::vector<bool> used;
    while (t-- > 0) {
        std::cin >> n >> k;

        used = std::vector<bool>(n, false);

		if (k == 0){
			for (int i = 1; i <= n; i++)
				std::cout << i << " ";
			std::cout << std::endl;
			continue; /* moves on to next test case! */
		} else if (n % (2*k) != 0) {
			std::cout << -1 << std::endl;
			continue;
		}

        for (int i = 1,j; i <= n; i += 2*k) {
			for (j = i; j < i+k; j++)
				std::cout << j+k << " ";
			for (j = i+k; j < i+2*k; j++)
				std::cout << j-k << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
