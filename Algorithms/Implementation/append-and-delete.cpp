#include <iostream>
#include <algorithm>

int main(void) {
    
    std::string s,t;
    std::cin >> s >> t;
    
    int k;
    std::cin >> k;
    
    int i = 0;
    for ( ; i < std::min(s.length(),t.length()); ++i) {
        if (s[i] != t[i]) {
            break;
        }
    }
    
    int min_ops = (t.length()-i) + (s.length()-i);
    
    int more_ops = min_ops;
    while(more_ops < k) {
        if (i-- > 0)
            more_ops += 2;
        else
            more_ops++;
    }

    std::cout << (more_ops == k ? "Yes" : "No") << '\n';
    
    return 0;
}

