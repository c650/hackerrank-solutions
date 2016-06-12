#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int v, n;
    cin >> v >> n;
    
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            cout << i << endl;
            return 0;
        } else {
            continue;
        }
    }
    
    return 0;
}