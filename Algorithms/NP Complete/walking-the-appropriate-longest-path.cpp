#include <vector>
#include <iostream>
#include <algorithm>

// getting 38.50 pts

typedef std::vector<std::vector<int>> adj_mat;

static bool inner(const int& v, const adj_mat& adj, std::vector<bool>& visited, const int& count, std::vector<int>& order);

int main() {
    
    int n,m;
    std::cin >> n >> m;
    
    adj_mat adj(n);
    for (int i = 0, a,b; i < m; ++i) {
        std::cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (auto& v : adj) {
        std::sort(v.begin(), v.end(), [&adj](const int& a, const int& b){
            return adj[a].size() < adj[b].size();
        });
    }
    
    std::vector<bool> visited(adj.size(), false);
    std::vector<int> order;
    
    for (int i = 0; i < adj.size(); ++i) {
        visited[i] = true;
        
        if (inner(i, adj, visited, 1, order)) {
            std::cout << n << '\n' << (i+1) << ' ';
            for (int i = order.size() - 1; i >= 0; --i)
                std::cout << order[i] << ' ';
            std::cout << '\n';
            break;
        }
        
        visited[i] = false;
    }
    
    return 0;
}

static bool inner(const int& v, const adj_mat& adj, std::vector<bool>& visited, const int& count, std::vector<int>& order) {
    if (count == adj.size()) {
        return true;
    }
    for (auto& nei : adj[v]) {
        if (!visited[nei]) {
            visited[nei] = true;
            if (inner(nei, adj, visited, count + 1, order)) {
                order.push_back(nei + 1);
                return true;
            }
            visited[nei] = false;
        }
    }
    return false;
}

