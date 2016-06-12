#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    
    int n;
    while (t-- > 0) {
        cin >> n;
        vector<int> vec(n);
        for (auto& a : vec) cin >> a;
        
        // impl contig
        long long contig_max = 0, curr = vec[0];
        for (int i = 1; i < n; i++) {
            curr = curr + vec[i] > 0 ? curr + vec[i] : 0;
            contig_max = contig_max > curr ? contig_max : curr;
        }
        if (contig_max <= 0)
            contig_max = *max_element(vec.begin(),vec.end());
        
        // non-contig
        long long non_contig = 0;
        for (auto& a : vec)
            if (a > 0)
                non_contig += a;
            
        cout << contig_max << " " << (non_contig == 0 ? contig_max : non_contig) << endl;
    }
    return 0;
}