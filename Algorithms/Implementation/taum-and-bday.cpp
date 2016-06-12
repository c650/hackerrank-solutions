#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

int main(){
    int t; std::cin >> t;
    while (t-- > 0) {
        unsigned long long b,w,x,y,z;
        std::cin >> b >> w 
            >> x >> y >> z;
        
        if (x+z < y) {
            std::cout << x*b + (x+z)*w << std::endl;
        } else if (y+z < x) {
            std::cout << (y+z)*b + y*w << std::endl;
        } else {
            std::cout << x*b + y*w << std::endl;
        }
    }
    return 0;
}
