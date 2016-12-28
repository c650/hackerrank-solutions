#include <vector>
#include <iostream>
#include <algorithm>

static void read_vec(std::vector<int>& vec) {
    for (auto& a : vec)
        std::cin >> a;
}

static short validate(const int& num, const std::vector<int>& a , const std::vector<int>& b) {
    for (auto& _a : a) {
        if (num % _a)
            return 0;
    }
    for (auto& _b : b) {
        if (_b % num)
            return 0;
    }
    return 1;
}

int main(void) {

    int n,m;
    std::cin >> n >> m;
    
    std::vector<int> a(n),b(m);
    read_vec(a); read_vec(b);
    
    int start = a.back();
    int end = b.front(); // [start,end]
    
    int tmp = start;
    int count = 0;
    
    while(tmp <= end) {
        count += validate(tmp,a,b);
        tmp++;
    }
    
    std::cout << count << '\n';
    
    return 0;
}

