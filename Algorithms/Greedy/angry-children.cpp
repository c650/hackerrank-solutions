#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,k;
    std::cin >> n >> k;
    
    std::vector<int> arr(n);
    for (auto& e : arr)
        std::cin >> e;
    
    std::sort(arr.begin(), arr.end());
    
    int min = std::numeric_limits<int>::max();
    for (int i = k-1; i < n; ++i) {
        min = std::min(min, std::abs(arr[i] - arr[i - k + 1]));
    }
    
    std::cout << min << '\n';
    
    
    return 0;
}

