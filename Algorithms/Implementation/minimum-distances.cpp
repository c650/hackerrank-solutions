#include <vector>
#include <iostream>
#include <limits.h>

int main(){
    int n; std::cin >> n;
    std::vector<int> vec(n);
    for (auto& a : vec) std::cin >> a;
    
    int min_dist = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n && j-i < min_dist ; j++) {
            if (vec[i] == vec[j] && j - i < min_dist) {
                min_dist = j - i;
            }
        }
    }
    
    std::cout << (min_dist == INT_MAX ? -1 : min_dist) << std::endl;
    return 0;
}