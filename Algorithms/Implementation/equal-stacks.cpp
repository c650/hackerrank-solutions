#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

int main(){
    int n[3];
    for (int i = 0; i < 3; i++)
        std::cin >> n[i];
    
    std::vector< std::vector<int> > outer(3);
    
    int tmp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            std::cin >> tmp;
            outer[i].push_back(tmp);
        }
    }
    
    std::vector< std::vector<int> > heights(3);
    
    for (int i = 0; i < 3; i++) {
        
        heights[i] = std::vector<int>(n[i]);
        
        for (int j = n[i] - 1; j >= 0; j--) {
            if (j == n[i] - 1) {
                heights[i][ j ] = outer[i][ j ];
            } else {
                heights[i][ j ] = heights[i][ j + 1 ] + outer[i][j];
            }
        }
    }
    
    // and the hardcoding begins
    bool yes = false;
    int k;
    for (int i = 0; i < n[0] && !yes; i++) {
        for (int j = 0; j < n[1] && !yes; j++) {
            if (heights[0][i] == heights[1][j]) {
                for (k = 0; k < n[2] && !yes; k++) {
                    if (heights[0][i] == heights[2][k]) {
                        yes = true;
                        break;
                    } else if (heights[0][i] > heights[2][k]) {
                        break;
                        j = n[1];
                    }
                }
            } else if (heights[0][i] > heights[1][j]) {
                break;
            }
        }
    }
    
    std::cout << (yes ? heights[2][k] : 0 ) << std::endl;
    
    return 0;
}