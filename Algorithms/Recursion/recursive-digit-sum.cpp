#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

static unsigned long long sum_digits(const unsigned long long& p);
static unsigned long long superdigit(const unsigned long long& p);

static unsigned long long sum_digits(const std::string& p);

int main() {
    std::string n;
    unsigned long long k;
    std::cin >> n >> k;
    
    std::cout << superdigit(k * sum_digits(n));
    
    return 0;
}

static unsigned long long superdigit(const unsigned long long& p) {
    if (p < 10) return p;
    return superdigit(sum_digits(p));
}

static unsigned long long sum_digits(const unsigned long long& p) {
    if (p < 10) return p;
    return sum_digits(p/10) + p % 10;
}

static unsigned long long sum_digits(const std::string& p) {
    unsigned long long s = 0;
    for (const auto& c : p)
        s += (c - '0');
    return s;
}
