#include <iostream>

#include <vector>
#include <queue>

#include <limits>

void do_one(void);

int main(void) {
    
    int q;
    std::cin >> q;
    
    while(q --> 0)
        do_one();
    
    return 0;
}

void do_one(void) {
    int n,m;
    std::cin >> n >> m;
    
    bool adj_mat[n][n];
    for (int i = 0; i < n * n; ++i) {
        adj_mat[i / n][i % n] = false;
    }
    
    int u,v;
    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v;
        --u; --v;

        adj_mat[u][v] = true;
        adj_mat[v][u] = true;
    }
    
    int s;
    std::cin >> s;
    --s;
    
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    dist[s] = 0;
    
    std::vector<bool> visited(n, false);
    
    std::queue<int> togo;
    togo.push(s);
    
    int curr;
    while (!togo.empty()) {
        curr = togo.front();
        togo.pop();
        
        for (int i = 0; i < n; ++i) {
            if (!adj_mat[curr][i] || visited[i]) continue;
            togo.push(i);
            dist[i] = std::min(dist[i], dist[curr] + 1);
        }
        visited[curr] = true;
    }
    
    for (const auto& node : dist) {
        if (!node) continue;
        if (node != std::numeric_limits<int>::max())
            std::cout << (6 * node) << " ";
        else
            std::cout << "-1 ";
    }
    std::cout << "\n";
}

