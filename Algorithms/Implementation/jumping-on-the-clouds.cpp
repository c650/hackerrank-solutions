#include <vector>
#include <iostream>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    std::vector<bool> clouds(n);
    unsigned int tmp;
    for (auto c : clouds) {
        std::cin >> tmp;
        c = tmp == 1;
    }
    
    int jumps = 0;
    for (int i = 0; i < n; i++) {
        if (i+2 < n && !clouds[i+2]) {
            jumps++;
            i++;
        } else if (i+1 < n && !clouds[i+1]) {
            jumps++;
        }
    }
    
    std::cout << jumps << std::endl;
    
    return 0;
}
