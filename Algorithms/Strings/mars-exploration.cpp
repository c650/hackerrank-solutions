#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    uint altered = 0;
    for (int i = 0, n = s.length(); i < n; i += 3) {
        if (s[i] != 'S')
            altered++;

        if (s[i+1] != 'O')
            altered++;

        if (s[i+2] != 'S')
            altered++;
    }

    std::cout << altered << std::endl;
    return 0;
}
