#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    while (t-- > 0) {
        int n,k; cin >> n >> k;
        
        int here = 0, tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp <= 0) here++;
        }
        cout << (here < k ? "YES" : "NO") << endl;
    }
    return 0;
}