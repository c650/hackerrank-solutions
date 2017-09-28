#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int,int>> ord(n);
    for (auto& e : ord) {
        std::cin >> e.first >> e.second;
        e.second += e.first;            
    }
    
    std::vector<int> list(n);
    for (int i = 0; i < n; ++i)
        list[i] = i;
    
    std::sort(list.begin(), list.end(), [&ord](int a, int b){
        return ord[a].second < ord[b].second || ord[a].second == ord[b].second && a < b; 
    });
    
    for (const auto& e : list)
        std::cout << (e+1) << " ";
    std::cout << "\n";
    
    return 0;
}

