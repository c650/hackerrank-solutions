#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

static bool between(int s, int t, int x) {
    return x >= s && x <= t;
}

int main() {
    int s,t,a,b,m,n;
    std::cin >> s >> t
             >> a >> b
             >> m >> n;

    int acnt, ocnt, tmp;
    acnt = ocnt = 0;

    while(m-- > 0) {
        std::cin >> tmp;
        acnt += between(s,t,tmp+a);
    }
    while(n-- > 0) {
        std::cin >> tmp;
        ocnt += between(s,t,tmp+b);
    }

    std::cout << acnt << "\n" << ocnt << "\n";


    return 0;
}
