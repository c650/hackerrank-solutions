#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;

    while (t-->0) {
        int n, s, tmp; std::cin >> n;
        s = 0;
        while (n-->0) {
            std::cin >> tmp;
            s ^= tmp;
        }


        std::cout << (s != 0 ? "First" : "Second") << std::endl; 
    }
    return 0;
}
