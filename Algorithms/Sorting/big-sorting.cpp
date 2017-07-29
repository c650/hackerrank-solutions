#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> vec(n);
    for (auto& s : vec)
        std::cin >> s;
    
    std::sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b){
        return a.length() < b.length() || a.length() == b.length() && a < b; 
    });
    
    for (auto& s : vec)
        std::cout << s << '\n';
    
    return 0;
}

