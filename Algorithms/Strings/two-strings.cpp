#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(const string& _a, const string& _b) {
    // O(n*m) lol no thanks
    // more like O(n+m+52)
    bool arr[52] = {false};
    for(auto& a : _a)
        arr[a - 'a'] = true;
    for(auto& b : _b)
        arr[b - 'a' + 26] = true;
    
    for(int i = 0; i < 26; i++)
        if (arr[i] && arr[i+26])
            return true;
        
    return false;
}

int main() {
    int t; cin >> t;
  
    string a, b;
    while (t-- > 0) {
        cin >> a >> b;
        cout << (check(a,b) ? "YES" : "NO") << endl;
    }

    return 0;
}