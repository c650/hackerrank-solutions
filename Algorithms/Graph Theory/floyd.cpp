#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>

#define _INT_MAX std::numeric_limits<int>::max()

int main() {
    int n,m; std::cin >> n >> m;
    std::vector< std::vector<int> > matrix(n, std::vector<int>(n, _INT_MAX));
    
    int a,b,w;
    while(m-- > 0) {
        std::cin >> a >> b >> w;
        matrix[a-1][b-1] = w;
    }
    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j] && matrix[i][k] + matrix[k][j] >= 0)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
    
    int q; std::cin >> q;
    while (q-- > 0) {
        std::cin >> a >> b;
        std::cout << (matrix[a-1][b-1] == _INT_MAX ? -1 : matrix[a-1][b-1]) << std::endl;
    }
    
    return 0;
}
