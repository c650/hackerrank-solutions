#include <iostream>

int main() {
    int t; std::cin >> t;
    
    while (t --> 0) {
        int x,y,z;
        std::cin >> x >> y >> z;
        if (std::abs(x-z) < std::abs(y-z)) {
            std::cout << "Cat A\n";
        } else if (std::abs(x-z) > std::abs(y-z)) {
            std::cout << "Cat B\n";
        } else {
            std::cout << "Mouse C\n";
        }
    }
    return 0;
}

