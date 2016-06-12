#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n,p; cin >> n >> p;
        vector<int> a(n),b(n);
        
        for (int j = 0; j < n; j++) cin >> a[j];
        for (int j = 0; j < n; j++) cin >> b[j];
        
        sort(a.begin(),a.end(), greater<int>());
        sort(b.begin(),b.end());
        
        for (int j = 0; j < n; j++) {
            if (a[j] + b[j] < p) {
                cout << "NO" << endl;
                break;
            } else if (j + 1 == n && a[j] + b[j] >= p) {
                cout << "YES" << endl;
                break;
            }
        }   
    }
    return 0;
}
