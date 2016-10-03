#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t; std::cin >> t;
    
    while (t-->0) {
        int n, s, tmp; std::cin >> n;
        bool non_one_n = false, is_one = true;
        s = 0;
        while (n-->0) {
            std::cin >> tmp;
            s ^= tmp;
            if (tmp > 1) non_one_n = true;
            is_one = is_one && tmp <= 1;
        }
        std::cout << (non_one_n && s == 0 || is_one && s == 1 ? "Second" : "First") << std::endl;
    }
    return 0;
}
/* tremendously helpful:
  http://mathoverflow.net/questions/71802/analysis-of-misere-nim?newreg=d3bad1cf22544e06bcbc89dce331a0ac
*/
