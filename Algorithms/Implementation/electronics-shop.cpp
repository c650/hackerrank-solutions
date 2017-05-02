#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int s,n,m;
    std::cin >> s >> n >> m;
    
    std::vector<int> k(n),u(m);
    for (auto& e : k)
        std::cin >> e;
    for (auto& e : u)
        std::cin >> e;
    
    int max_spent = -1;
    for (int i = 0,j,t; i < k.size(); ++i) {
        for (j = 0; j < u.size(); ++j) {
            t = k[i] + u[j];
            if (t > max_spent && t <= s) {
                max_spent = t;
            }
        }
    }
    std::cout << max_spent << '\n';
    return 0;
}

