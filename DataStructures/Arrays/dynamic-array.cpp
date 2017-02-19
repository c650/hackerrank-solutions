#include <vector>
#include <iostream>

struct query {
    int type, x,y;  
};

int main() {
    size_t n;
    std::cin >> n;
    
    std::vector<std::vector<int>> seq(n, std::vector<int>());
    
    int lastAns = 0, queries;
    std::cin >> queries;
    
    query q;
    while (queries --> 0) {
        std::cin >> q.type >> q.x >> q.y;
        switch (q.type) {
            case 1:
                seq[(q.x ^ lastAns) % n].push_back(q.y);
                break;
            case 2:
                lastAns = seq[(q.x ^ lastAns) % n][q.y % seq[(q.x ^ lastAns) % n].size()];
                std::cout << lastAns << '\n';
        }
    }
    
    return 0;
}

