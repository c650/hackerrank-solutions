#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector< std::vector<std::string> > inputs(100);
    
    int tmp; std::string str;
    for (int i = 0; i < n/2; i++) {
        std::cin >> tmp >> str;
        inputs[tmp].push_back("-");
    }
    for (int i = n/2; i < n; i++) {
        std::cin >> tmp >> str;
        inputs[tmp].push_back(str);
    }
    
    for (auto& sub_vec : inputs) {
        if (sub_vec.empty()) continue;
        
        for (auto& elem : sub_vec) {
            std::cout << elem << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
