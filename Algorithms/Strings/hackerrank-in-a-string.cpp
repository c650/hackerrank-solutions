#include <string>
#include <vector>
#include <iostream>

static bool within(const std::string& str, const std::string& sub);

int main(void) {
    
    const std::string HR = "hackerrank";
    
    int q;
    std::cin >> q;
    
    std::string tmp;
    
    while (q --> 0) {
        std::cin >> tmp;
        std::cout << (within(tmp, HR) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

static bool within(const std::string& str, const std::string& sub) {
    size_t i, j;
    
    std::vector<bool> found(sub.length(), false);
    
    for (i = j = 0; i < str.length() && j < sub.length(); ++i) {
        if (found[j] = str[i] == sub[j])
            ++j;
    }
    return found.back();
}
