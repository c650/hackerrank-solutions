#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n; cin >> t;
    while( t-- > 0 ) {
        cin >> n;
        vector< string > grid(n);
        for (auto& a : grid) {
            cin >> a;
            sort(a.begin(),a.end());
        }
        bool yes = true;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n-1; row++){
                if (grid[row][col] > grid[row+1][col]) {
                    yes = false; break;
                }
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}
