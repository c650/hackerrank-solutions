#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> vec(5,0);
    
    int tmp;
    while ( n --> 0 ) {
        std::cin >> tmp;
        ++vec[tmp-1];
    }
    
    tmp = 0;
    for (int i = 1; i < 5; ++i) {
        if (vec[i] > vec[tmp])
            tmp = i;
    }
    
    std::cout << tmp+1 << '\n';
    
    return 0;
}

