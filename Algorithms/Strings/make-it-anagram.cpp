#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    
    int freq[52] = {0};
    for (auto& _a : a)
        freq[_a - 'a']++;
    for (auto& _b : b)
        freq[_b - 'a' + 26]++;
    
    int sum;
    for (int i = 0; i < 26; i++)
        sum += abs( freq[i] - freq[i + 26] );
    
    cout << sum << endl;
    return 0;
}
