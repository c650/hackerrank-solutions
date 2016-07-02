#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,k; std::cin >> n >> k;

    std::vector<int> k_counts(k, 0);
    for (int i = 0,tmp; i < n; i++) {
        std::cin >> tmp;
        k_counts[tmp % k]++;
    }
    
    int count = (k_counts[0] != 0 ? 1 : 0);
    int term = (k % 2 == 0 ? k/2 : k/2 + 1);
    for (int i = 1; i < term; i++) {
        count += (k_counts[i] > k_counts[k-i] ? k_counts[i] : k_counts[k-i]);
    }
    
    if (k % 2 == 0 && k_counts[k/2] != 0)
        count++;
    
    std::cout << count << std::endl;
    
    return 0;
}