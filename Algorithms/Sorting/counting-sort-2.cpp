#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define TOP_OF_RANGE 100

int main() {
    int n; std::cin >> n;
    std::vector<int> counts(TOP_OF_RANGE,0);
    
    for (int i = 0,tmp; i < n; i++) {
        std::cin >> tmp;
        counts[tmp]++;
    }
    
    for (int i = 0; i < TOP_OF_RANGE; i++) {
        for (int j = 0; j < counts[i]; j++)
            std::cout << i << " ";
    }
    
    return 0;
}