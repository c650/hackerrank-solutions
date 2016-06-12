#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    
    for (int i = 0; i <= n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') { // if phrase is lowercase char
			s[i] = ((s[i] - 'a' + k) % 26) + 'a'; // add key to it and wrap it in range
			// this guarantees wrap-around, explicitly ensure phrase[i] is a char
		} else if (s[i] >= 'A' && s[i] <= 'Z') { // same as if, but uppercase
			s[i] = ((s[i] - 'A' + k) % 26) + 'A';
		}
    }
    cout << s << endl;
    return 0;
}