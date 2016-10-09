#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n; /* useless to us, but whatever... */
    std::string s; std::cin >> s;

    std::vector<int> freq(26,0);
    for (const char& c : s) freq[c-'a']++;

    int max = 0;
    char last;
    bool valid;

    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == 0) continue;

        for (int j = i+1; j < freq.size(); j++) {

            if (freq[j] == 0) continue;

            last = -1;
            valid = true;
            for (const char& c : s) {
                if (c == char(i+'a') || c == char(j+'a')) {
                    if (last == c) {
                        valid = false;
                        break;
                    }
                    last = c;
                }
            }

            if (valid && std::abs(freq[i] - freq[j]) <= 1)
                max = std::max(max, freq[i] + freq[j]);
        }
    }
    std::cout << max << std::endl;

    return 0;
}
