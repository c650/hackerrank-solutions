#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::string input;
    std::cin >> input;

    int words = 1;
    for (int i = 0, n = input.length(); i < n; i++) {
        if (isupper(input[i])) words++;
    }

    std::cout << words << std::endl;

    return 0;
}
