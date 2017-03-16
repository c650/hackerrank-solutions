#include <cmath>
#include <vector>
#include <iostream>

int main() {
    size_t n;
    std::cin >> n;
    
    std::vector<size_t> p(n), p_sub(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> p[i];
        p_sub[--p[i]] = i;
    }
    
    for (size_t i = 0; i < n; ++i) {
        std::cout << (p_sub[p_sub[i]]+1) << '\n';
    }
    
    
    return 0;
}

