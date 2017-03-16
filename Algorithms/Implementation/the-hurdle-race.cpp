#include <cmath>
#include <iostream>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    
    size_t tmp, max = 0;
    while (n --> 0) {
        std::cin >> tmp;
        max = std::max(max, tmp);
    }

    std::cout << (max <= k ? 0 : max - k) << '\n';
    return 0;
}

