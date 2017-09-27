#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,k;
    std::cin >> n >> k;
    
    std::vector<int> vec;
    
    int max_luck = 0;
    
    std::pair<int,int> tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp.first >> tmp.second;
        if (!tmp.second)
            max_luck += tmp.first;
        else
            vec.push_back(tmp.first);
    }
    
    std::sort(vec.begin(), vec.end(), [](int a,int b){return a > b;});
    
    int i;
    for (i = 0; i < k && i <vec.size(); ++i) 
        max_luck += vec[i];
    for (; i < vec.size(); ++i)
        max_luck -= vec[i];
    
    
    std::cout << max_luck << '\n';
    
    return 0;
}

