#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<int> heights(n+2,0);
    std::string steps; std::cin >> steps;
    
    for (int i = 1; i < n+1; i++) {
        heights[i] = heights[i-1] + (steps[i-1] == 'U' ? 1 : -1);
    }
    
    int valley_count = 0;
    std::vector<int>::iterator a,b;
    for (a = std::find(heights.begin(),heights.end(), 0); a != heights.end(); a = b) {
        b = std::find(a+1,heights.end(), 0);
        for (; a != b; a++) {
            if (*a < 0) {
                valley_count++;
                break;
            }    
        }
    }
    
    std::cout << valley_count << std::endl;
    
    return 0;
}

