#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    unsigned int ranges[t][2], i;
    
    // get all inputs first
    for (i = 0; i < t; i++)
        cin >> ranges[i][0] >> ranges[i][1];
    
    // do calculations later
    unsigned int j, count; double rt;
    for (i = 0; i < t; i++, count = 0) {
        for (j = ranges[i][0]; j <= ranges[i][1]; j++) {
            rt = sqrt(j);
            if (ceil(rt) == floor(rt)) {
                count++;
                j = pow(rt+1, 2) - 1; // move it to next square and then check range
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
