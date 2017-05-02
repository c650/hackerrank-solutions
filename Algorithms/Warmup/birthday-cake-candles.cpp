#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for(auto& v : vec)
        std::cin >> v;
    
    int max = 0, cnt = 0;
    for (auto& v : vec) {
        if (v > max) {
            max = v;
            cnt = 1;
        } else if (v == max) {
            ++cnt;
        }
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}

