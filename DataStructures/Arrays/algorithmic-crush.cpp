// not yet working... 2/19/17
#include <vector>
#include <iostream>
#include <algorithm>

struct query {
    size_t a,b,k;  
};

int main() {
    std::size_t n, m;
    std::cin >> n >> m;
        
    unsigned long long int max = 0;
    
    std::vector<long long int> difference(n-1,0), sum(n+1,0);
    
    query q;
    while (m --> 0) {
        std::cin >> q.a >> q.b >> q.k;
    }    
    
    std::cout << max << '\n';
    
    return 0;
}

// http://wcipeg.com/wiki/Prefix_sum_array_and_difference_array

