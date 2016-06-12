#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<int> counts(100,0);
    int max = 0;
    
    std::string str;
    for(int i = 0, tmp; i < n; i++) {
        std::cin >> tmp >> str;
        counts[tmp]++;
        if (max < tmp)
            max = tmp;
    }
    
    // count numbers from 0 to max
    for (int i = 0, sum = 0; i < max; i++) {
        sum += counts[i];
        std::cout << sum << " ";
    }
    for(int i = max; i < 100; i++) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
