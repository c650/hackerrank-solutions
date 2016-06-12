#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;
    int stones;
    while(t-->0) {
        std::cin >> stones;
        std::cout << (stones % 7 > 1 ? "First" : "Second") << std::endl;
    }
    return 0;
}
