#include <cmath>
#include <iostream>

int main() {
    size_t n, tmp_grade;
    
    std::cin >> n;
    while(n-->0) {
        std::cin >> tmp_grade;
        if (tmp_grade >= 38 && tmp_grade % 5 > 2)
            tmp_grade += 5 - (tmp_grade % 5);
        std::cout << tmp_grade << '\n';
    }
    
    return 0;
}

