#include <cmath>
#include <cstdio>
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
    
    int cnt = 0;
    for (const auto& e : arr)
        if (k > e) {
            k -= e;
            ++cnt;
        }
    
    std::cout << cnt << "\n";
    
    return 0;
}

