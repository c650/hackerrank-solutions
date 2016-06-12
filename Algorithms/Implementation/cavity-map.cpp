#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector< vector<char> > grid(n, vector<char>(n));
    for (auto& a : grid)
        for (auto& b : a)
            cin >> b;
    
    // check for caves here
    for (int i = 1, n = grid.size() - 1; i < n; i++) {
        for (int j = 1, m = grid[i].size() - 1; j < m; j++) {
            if (grid[i][j] > grid[i][j+1] && grid[i][j] > grid[i][j-1]
               && grid[i][j] > grid[i+1][j] && grid[i][j] > grid[i-1][j])
                grid[i][j] = 'X';
        }
    }
    
        
    for(auto& a : grid) {
        for (auto& b : a) {
            cout << b;
        }
        cout << endl;
    }
    return 0;
}
