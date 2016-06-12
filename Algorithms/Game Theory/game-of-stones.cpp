#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;
    
    int n,m;
    while(t-- > 0) {
        std::cin >> n >> m;
        std::cout << (m == 1 || n % 2 == 0 ? 2 : 1) << std::endl;
    }
    return 0;
}
