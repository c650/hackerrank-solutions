#include <cmath>
#include <limits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (auto& e : arr)
        std::cin >> e;
    
    std::sort(arr.begin(), arr.end());
    
    int diff = std::numeric_limits<int>::max();
    for (int i = 1; i < arr.size(); ++i) {
        diff = std::min(diff, std::abs(arr[i] - arr[i-1]));
    }
    
    std::cout << diff << '\n';
    
    return 0;
}

