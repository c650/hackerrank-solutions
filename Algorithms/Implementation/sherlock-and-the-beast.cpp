#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        int fives = n;
        while (fives % 3 != 0 && fives > 0)
            fives -= 5;
        
        if (fives % 3 == 0 && fives >= 0) {
            for (int i = 0; i < fives; i++)
                cout << 5;
            for (int i = 0, x = n - fives; i < x; i++)
                cout << 3;
        } else {
            cout << -1;
        }
            
        cout << endl;
    }
    return 0;
}