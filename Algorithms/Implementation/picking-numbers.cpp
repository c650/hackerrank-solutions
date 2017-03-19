#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (auto& e : a)
        std::cin >> e;
    
    std::sort(a.begin(),a.end());
    
    std::vector<int> counts(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (std::abs(a[j] - a[i]) <= 1)
                ++counts[i];
            else
                break;
        }
    }
    
    std::cout << *std::max_element(counts.begin(),counts.end());
    
    return 0;
}

