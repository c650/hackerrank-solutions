#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector < int > a,int k) {
    int ans = 0;
    sort(a.begin(),a.end());
    
    for (int i = 0, n = a.size(); i < n; i++) {
        if (find(a.begin()+i,a.end(),abs(a[i] + k)) != a.end()) ans++;
    }
    
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}