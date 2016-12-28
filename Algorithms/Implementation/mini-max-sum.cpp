#include <vector>
#include <algorithm>
#include <iostream>

int main(void) {
    
    std::vector<unsigned long long> vec(5);
    
    for (auto& a : vec)
        std::cin >> a;
    std::sort(vec.begin(),vec.end());

    /*for (auto& a : vec)
        std::cout << a << ' ';
    std::cout << '\n';*/
    
    unsigned long long sum = 0;
    
    for (size_t i = 0; i < 4; ++i)
        sum += vec.at(i);
    
    std::cout << sum << ' ';
    
    sum += vec.at(4);
    sum -= vec.at(0);
    
    std::cout << sum << '\n';
    

    
    return 0;
}

