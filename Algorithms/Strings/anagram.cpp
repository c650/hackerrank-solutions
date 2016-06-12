#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t; cin >> t;
    string s; int len, changes, i;
    while(t-- > 0) {
        cin >> s;
        len = s.length();
        
        if (len % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        int left[26] = {0}, right[26] = {0};
        
        for(i = 0; i < len/2; i++)
            left[ s[i] - 'a' ]++;
        for(; i < len; i++)
            right [ s[i] - 'a']++;
        
        changes = 0;
        for(i = 0; i < 26; i++)
            changes += abs( right[i] - left[i] );
        
        cout << changes/2 << endl;
    }
    return 0;
}
