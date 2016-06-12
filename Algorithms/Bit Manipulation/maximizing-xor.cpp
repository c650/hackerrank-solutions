#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int max = 0;
    for (int i = l; i <= r; i++) {
        
        for (int j = i; j <= r; j++) {
            int xr = j ^ i;
            if (xr > max) max = xr;
        }
        
    }

    return max;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
