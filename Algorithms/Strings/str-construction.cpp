#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

int uniq(const std::string& s) {
    int uniq_chars = 0;
    std::vector<bool> seen(26, false);

    int i;
    for (auto& c : s) {
        i = c-'a';
        if (!seen[i]) {
            seen[i] = true;
            uniq_chars++;
        }
    }
    return uniq_chars;
}

int main() {
    int t;
    std::cin >> t;

    std::string s;
    while (t-- > 0) {
        std::cin >> s;

        std::cout << uniq(s) << std::endl;
    }
    return 0;
}
