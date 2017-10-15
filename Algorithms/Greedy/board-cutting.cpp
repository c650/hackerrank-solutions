/* not done yet! */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

static void do_thing(void);
static void read_vec(std::vector<int>& v);

int main() {
    int q;
    std::cin >> q;
    while(q --> 0)
        do_thing();
    return 0;
}

static void do_thing(void) {
    int m,n;
    std::cin >> m >> n;
    
    std::vector<int> ys(m), xs(n);
    read_vec(ys);
    read_vec(xs);
    
        
}

static void read_vec(std::vector<int>& v) {
    for (auto& e : v)
        std::cin >> e;
    std::sort(v.begin(), v.end(), [](int a, int b){
        return b < a; 
    });
}

