#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    int sum; string s;
    while(t-- > 0) {
        cin >> s; sum = 0;
        for (int i = 0, n = s.length(); i < n/2; i++)
            sum += abs( s[i] - s[n-1-i] );
        cout << sum << endl;
    }
    return 0;
}
