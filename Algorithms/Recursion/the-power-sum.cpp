#include <vector>
#include <cmath>
#include <iostream>

static void blerg(const int& target, const int& start, const int& pow, int& count);

int main(void) {

    int target;
    std::cin >> target;

    int pow;
    std::cin >> pow;

    int count = 0;

    blerg(target, 1, pow, count);

    std::cout << count << '\n';

    return 0;
}

static void blerg(const int& target, const int& start, const int& pow, int& count) {
    if (target == 0) {
        ++count;
        return;
    }

    for (int i = start; std::pow(i, pow) <= target; ++i) {
        blerg(target - std::pow(i, pow), i + 1, pow, count);
    }
}
