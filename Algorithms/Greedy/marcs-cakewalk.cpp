#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    
    std::vector<unsigned long long> arr(n);
    for (auto& e : arr)
        std::cin >> e;
    
    std::sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});
    
    unsigned long long ans = 0, i;
    for (i = 0; i < n; ++i) {
        ans += arr[i] << i;
    }
    
    std::cout << ans << '\n';  
    
    
    return 0;
}

