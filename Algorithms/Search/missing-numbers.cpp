#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    std::vector<int> count(201,0);
    
    int n; std::cin >> n;
    
    int pivot; // PIVOT WILL BE FIRST ELEMENT
    std::cin >> pivot; // GET VALUE OF PIVOT
    count[100]++; // 100 will be index of pivot
    
    int tmp;
    // n-1 bcs we already took in an element
    for (int i = 0; i < n - 1; i++) {
        std::cin >> tmp;
        count[tmp - pivot + 100]++;
    }
    
    int m; std::cin >> m; // get m, now we do B
    for (int i = 0; i < m; i++) {
        std::cin >> tmp;
        count[tmp - pivot + 100]--;
    }
    
    for (int i = 0; i < 202; i++) {
        if (count[i] != 0) {
            std::cout << (i - 100) + pivot << " ";
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}
