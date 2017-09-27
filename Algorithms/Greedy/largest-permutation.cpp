#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,k;
    std::cin >> n >> k;
    
    std::vector<int> arr(n), idx(n+1);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        idx[arr[i]] = i;
    }
    
    /* start by finding index of largest number */
    for (int i = n; i > 0 && k > 0; --i) {
        if (idx[i] != n - i) {
            std::swap(arr[n-i], arr[idx[i]]);
            std::swap(idx[arr[idx[i]]], idx[i]);
            --k;
        }
    }
    
    for (auto& e : arr)
        std::cout << e << " ";
    std::cout << "\n";
    
    return 0;
}

