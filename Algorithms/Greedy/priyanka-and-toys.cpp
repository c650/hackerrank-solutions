#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >>n;
    vector<int> weights(n);
    
    for (auto& a : weights) cin >> a;
    sort(weights.begin(), weights.end());
    
    int curr_w = weights[0], total_p = 1;
    for (int i = 1, j; i < n; i++){
        if (weights[i] - curr_w > 4) {
            total_p++;
            curr_w = weights[i];
        }
    }
    
    cout << total_p << endl;
    return 0;
}
