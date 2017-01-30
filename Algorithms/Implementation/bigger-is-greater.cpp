#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    std::string s = "";
    while( t --> 0) {
        std::cin >> s;
        if (std::next_permutation(s.begin(),s.end())) {
            std::cout << s << '\n';
        } else {
            std::cout << "no answer\n";
        }
    }
    
    return 0;
}

