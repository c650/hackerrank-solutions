#include <vector>
#include <iostream>

int main() {
    int n,d;
    std::cin >> n >> d;
    
    d %= n;
    
    std::vector<int> arr(n);
    for (auto& e : arr)
        std::cin >> e;
    
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[(i + d) % n] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}

