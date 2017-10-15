/* not done yet */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

static int eval(const std::vector<bool>& has_plant, const int& k);

int main() {
    int n,k;
    std::vector<bool> has_plant(n);
    for (auto& e : has_plant)
        std::cin >> e;
    
    std::cout << eval(has_plant, k) << '\n';
    
    return 0;
}

static int eval(const std::vector<bool>& has_plant, const int& k) {
    
}

