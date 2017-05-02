#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,m;
    std::cin >> n;
    std::vector<int> lb(n);
    for (auto& e : lb) std::cin >> e;
    
    std::vector<int> ranks(n);
    ranks[0] = 1;
    for (size_t i = 1; i < n; ++i) {
        if (lb[i] == lb[i-1]) {
            ranks[i] = ranks[i-1];
            continue;
        }
        ranks[i] = ranks[i-1]+1;
    }
    ranks.push_back(ranks[n-1]+1);
    
    std::cin >> m;
    std::vector<int> alice(m);
    
    int curr = ranks[n], ci = n-1;
    for (auto& e : alice) {
        std::cin >> e;
        while(ci >= 0 && e > lb[ci]) {
            --ci;
        }
        if (lb[ci] == e)
            std::cout << ranks[ci];
        else if (lb[ci] > e)
            std::cout << ranks[ci]+1;
        else
            std::cout << 1;
        std::cout << '\n';
    }
    
    return 0;
}

