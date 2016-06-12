#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n,a,b; cin >> t;
    while (t-- > 0) {
        cin >> n >> a >> b; n--;
        if (a==b) {
            cout << n * a << endl;
            continue;
        } else if (a > b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        for (int i = n, j = 0; i >=0 && j <= n; i--,j++)
            cout << i*a + j*b << " ";
        cout << endl;
    }
    return 0;
}
