#include <iostream>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    
    int tmp,min,max,min_delta,max_delta;
    min = std::numeric_limits<int>::max();
    max = std::numeric_limits<int>::min();
    min_delta = max_delta = 0;
    
    std::cin >> tmp;
    min = max = tmp;
    
    while(0 <-- n) {
        std::cin >> tmp;
        if (tmp < min) {
            ++min_delta;
            min = tmp;
        }
        if (tmp > max) {
            ++max_delta;
            max = tmp;
        }
    }
    
    std::cout << max_delta << ' ' << min_delta;
    return 0;
}

