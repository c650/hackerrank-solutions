#include <vector>
#include <iostream>

int main() {
    int n,d,m;
    
    std::cin >> n;
    std::vector<int> p(n);
    for(auto& _p : p) std::cin >> _p;
    
    std::cin >> d >> m;
    
    int cnt = 0;
    for (int i = 0, e = n - m + 1, s; i < e; ++i) {
        s = 0;
        for (int j = 0; j < m; ++j) {
            s += p[i+j];
        }
        if (s == d) ++cnt;
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}

