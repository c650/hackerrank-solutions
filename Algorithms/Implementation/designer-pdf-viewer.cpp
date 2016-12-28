#include <vector>
#include <iostream>
#include <algorithm>

std::vector<unsigned short> heights(26);

static unsigned int max_h(const std::string& s);

int main(void) {
    
    for (auto& h : heights)
        std::cin >> h;
    
    std::string s;
    std::cin >> s;
    
    std::cout << s.length() * max_h(s) << '\n';
    
    return 0;
}

static unsigned int max_h(const std::string& s) {
    unsigned int max = 1;
    for (auto& c : s) {
        if (heights[c-'a'] > max)
            max = heights[c-'a'];
    }
    return max;
}

