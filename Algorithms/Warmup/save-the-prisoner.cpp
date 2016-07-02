#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t,n,m,s,p;
    std::cin >> t;
    while (t-->0) {
        std::cin >> n >> m >> s;
        p = m + s-1;
        if (p > n) {
            p %= n;
            if (p == 0)
                p = n;
        }
        std::cout << p << std::endl;
    }
    return 0;
}