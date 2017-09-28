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
    
    std::sort(arr.begin(), arr.end(), [](const int& a, const int& b){return b < a;});
    
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += (1 + i / k) * arr[i];
    }
    std::cout << cost << "\n";
    
    return 0;
}

