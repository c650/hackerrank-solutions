#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<string> inputs(t);
    
    for (int i = 0; i < t; i++)
        cin >> inputs[i];
    
    for (int i = 0; i < t; i++) {
        int charsToDel = 0;
        for (int j = 0, n = inputs[i].size() - 1; j < n; j++) {
            if (inputs[i][j] == inputs[i][j + 1]) {
                charsToDel++;
            }
        }
        cout << charsToDel << endl;
    }
    return 0;
}
