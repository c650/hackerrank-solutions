#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        string query; cin >> query;
        
        int c = count(arr.begin(),arr.end(), query);
        
        cout << c << endl;
    }
    
    return 0;
}

