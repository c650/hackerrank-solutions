#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<int> input(n), freq(100, 0);
    for(auto& ai : input) {
        std::cin >> ai;
        freq[ai-1]++;
    }
    std::cout << n - *std::max_element(freq.begin(), freq.end()) << std::endl;

    return 0;
}
