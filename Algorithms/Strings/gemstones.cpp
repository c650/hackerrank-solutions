#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    vector<string> vec(t);
    for (auto& a : vec)
        cin >> a;
    
    int min_len = 101;
    for (auto& a : vec) {
        sort(a.begin(),a.end());
        a.resize( distance( a.begin(),unique( a.begin(),a.end() ) ) );
        if (a.length() < min_len)
            min_len = a.length();
    }
    
    int sum = 0; bool common = false;
    for (int i = 0; i < min_len; i++) {
        for (auto& a : vec) {
            if (vec[0][i] == a[i])
                common = true;
            else {
                common = false;
                break;
            }
        }
        if (common) sum++;
        common = false;
    }  
    cout << sum << endl;
    return 0;
}
