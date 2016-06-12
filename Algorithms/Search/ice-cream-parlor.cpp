#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int m; cin >> m;
        int n; cin >> n;
        
        vector<int> ice_creams(n);
        for (int j = 0; j < n; j++)
            cin >> ice_creams[j];
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) k++;
                
                if (ice_creams[j] + ice_creams[k] == m) {
                    cout << j + 1 << " " <<  k + 1 << endl;
                    j = k = n;
                    break;
                }
            }
            
        }
    }
    return 0;
}
