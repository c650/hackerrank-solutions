#include <iostream>
#include <string>
#include <vector>

int main(void) {
    
    std::string str;
    std::cin >> str;
    
    std::vector<int> freq(26, 0);
    
    for (auto& c : str)
        ++freq[c - 'a'];
    
    int cnt_odds = 0;
    for (auto& f : freq) {
        cnt_odds += f % 2;
    }
    
    std::cout << (cnt_odds <= 1 ? "YES" : "NO") << '\n';
    
    return 0;
}

