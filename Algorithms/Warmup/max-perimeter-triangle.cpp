#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

typedef unsigned int uint;
/*
    returns perimeter of triangle or
    -1 if triangle is degenerate
*/
int triangle_perim(uint a, uint b, uint c) {
    if (a + b <= c || abs(a - b) >= c )
        return -1;
    return a + b + c;
}

int main() {
    int n; std::cin >> n;
    std::vector<unsigned int> sticks(n);
    for (auto& stick : sticks)
        std::cin >> stick;

    /* descending-sort the values to start with the biggest contenders */
    std::sort(sticks.begin(), sticks.end(), [](int a, int b){return a > b;});
    int i,j,k;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            for (k = j+1; k < n; k++) {
                if (triangle_perim(sticks[k], sticks[j], sticks[i]) != -1) {
                    printf("%u %u %u ", sticks[k], sticks[j], sticks[i]);
                    return 0;
                }
            }
        }
    }
    std::cout << -1;
    return 0;
}
