#include <vector>
#include <iostream>
#include <algorithm>

int main(void) {

    int g; std::cin >> g;
    
    std::string b;
    int n;
    
    while(g--) {
        
        std::cin >> n;
        std::cin >> b;
        
        int underscore_count = 0;
        for (auto& c : b)
            if (c == '_')
                underscore_count++;
        
        if (underscore_count == n) {
            std::cout << "YES\n";
            continue;
        }
        
        std::vector<int> color_counts(26, 0);
        for (auto& c : b) {
            if (c <= 'Z' && c >= 'A') {
                color_counts[c - 'A']++;
            }
        }
        
        bool yes = true;
        for (auto& c : color_counts)
            yes = yes && c != 1;
        
        for (size_t i = 1; underscore_count == 0 && i < n-1 && yes; i+=2)
            yes = yes && (b[i] == b[i+1] || b[i] == b[i-1]);
        
        std::cout << (yes ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

