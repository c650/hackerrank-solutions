#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
    int t; std::cin >> t;
    
    while (t --> 0) {
        unsigned long long f;
        std::cin >> f;
        
        auto quadratic = [](unsigned long long f) {
            return (std::sqrt(1 + 8 * f) - 1) / 2;
        };
        
        double ans = quadratic(f);
        
        if (std::floor(ans) == ans) {
            std::cout << "Go On Bob " << (int)ans << '\n';
        } else {
            std::cout << "Better Luck Next Time\n";
        }
    }

    return 0;
}

