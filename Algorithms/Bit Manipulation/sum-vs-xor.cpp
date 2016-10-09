#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    unsigned long long n; std::cin >> n;

    unsigned long long bin_zeros = 0;
    for (unsigned long long i = 1; i > 0 && i < n; i = i << 1)
        bin_zeros += !(n & i);

    std::cout << (1L << bin_zeros) << std::endl;
    return 0;
}
