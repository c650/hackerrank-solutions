#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;

    int tot, last_rnd;
    tot = last_rnd = 2;
    for (int i = 1 ; i < n; i++) {
        last_rnd = (last_rnd * 3) / 2;
        tot += last_rnd;
    }

    std::cout << tot;

    return 0;
}
