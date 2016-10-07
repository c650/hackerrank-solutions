#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> sock_freq(100, 0);
    int n, tmp; std::cin >> n;
    while( n-- > 0 ) {
        std::cin >> tmp;
        sock_freq[tmp-1]++;
    }

    tmp = 0;
    for (auto& sock : sock_freq)
        tmp += sock / 2;

    std::cout << tmp << std::endl;

    return 0;
}
