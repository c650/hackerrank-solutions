#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector<int>& a) {
    
    map<int, int> counts;
    
    // basically `for ... in` loop
    for (auto x : a) {
        if (counts[x] != NULL ) {
            counts[x]++;
        } else {
            counts[x]++;
        }
    }
    
    for (auto x: counts) {
        if (x.second == 1) {
            return x.first;
        }
    }
    return 0;
}
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}