#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

static int count_nodes(const int& start, const std::vector<std::vector<int>>& adj_mat, std::vector<int>& visited);

int main() {
    int n,m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> adj_mat(n, std::vector<int>(n, false));
    std::vector<std::pair<int,int>> edges(m);
    for (int i = 0, a,b; i < m; ++i) {
        std::cin >> a >> b;
        --a; --b;
        adj_mat[a][b] = adj_mat[b][a] = true;
        edges[i] = std::make_pair(a, b);
    }
    
    int count = 0;
    std::vector<int> visited(n);
    for (auto& e : edges) {
        // test if removing edge keeps the tree ok
        adj_mat[e.first][e.second] = adj_mat[e.second][e.first] = false;
        
        if (count_nodes(e.first, adj_mat, visited) % 2 || count_nodes(e.second, adj_mat, visited) % 2)
            adj_mat[e.first][e.second] = adj_mat[e.second][e.first] = true;
        else
            ++count;
    }
    
    std::cout << count << "\n";
    
    return 0;
}

static int count_nodes(const int& start, const std::vector<std::vector<int>>& adj_mat, std::vector<int>& visited) {
    visited[start] = true;
    
    int count = 1;
    for (int i = 0; i < adj_mat[start].size(); ++i) {
        if (!adj_mat[start][i]) continue;
        
        if (!visited[i]) {
            count += count_nodes(i, adj_mat, visited);
        }
    }
    
    visited[start] = false;

    return count;
}
