#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    
    vector<unsigned int> cases(t);
    int i;
    
    for (i = 0; i < t; i++) {
        cin >> cases[i];
    }
    
    for (i = 0; i < t; i++) {
        cout << ~(cases[i]) << endl;
    }
    return 0;
}
