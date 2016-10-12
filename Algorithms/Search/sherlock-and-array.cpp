#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;

    int n; std::vector<int> vec, lsum, rsum;
    while(t-->0) {
        std::cin >> n;
        vec.clear(); vec.resize(n);
        for (auto& a : vec) std::cin >> a;

        lsum.resize(n); rsum.resize(n);
        lsum[0] = rsum[n-1] = 0;
        for (int i = 1; i < n-1; i++) {
            lsum[i] = lsum[i-1] + vec[i-1];
            rsum[n-i-1] = rsum[n-i] + vec[n-i];
        }
        bool works = false;
        for (int i = 1; i < n-1; i++) {
            if (lsum[i] == rsum[i]) {
                works = true;
                break;
            }
        }
        std::cout << (works || n <= 1 ? "YES" : "NO") << std::endl;
    }
    return 0;
}
