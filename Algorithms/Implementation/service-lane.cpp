#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int my_min(const vector<int>& v, int i, int j) {
    int the_min = v[i];
    
    for (int o = i+1; o <= j;o++)
        if (v[o] < the_min)
            the_min = v[o];
        
    return the_min;
}
int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        
        cout << my_min(width,i,j) << endl;
    }
    return 0;
}
