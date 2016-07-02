#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n, k; std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (auto& a_i : a) std::cin >> a_i;
    
    std::sort(a.begin(), a.end());
    
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            if ((a[i] + a[j]) % k == 0)
                count++;
        }
        
    std::cout << count << std::endl;
    return 0;
}