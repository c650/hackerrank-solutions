#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int year;
    std::cin >> year;
    if (year == 1918) { // transition
        std::cout << "26.09.1918\n";
    } else { // gregorian and/or julian
        if ((year < 1918 && year % 4 == 0) || (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            std::cout << "12.09." << year << '\n';
        } else {
            std::cout << "13.09." << year << '\n';
        }
    }

    return 0;
}

