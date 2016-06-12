#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    // forgot to initialize all values to 0, kept getting junk...
    int chocolates[t] = {0};
    
    for(int a0 = 0; a0 < t; a0++){
        int n, c, m;
        cin >> n >> c >> m;
        
        chocolates[a0] += (n / c);
        
        int wrappers = chocolates[a0];
        
        while (wrappers >= m) {
            
            int tmp = wrappers / m;
            
            chocolates[a0] += tmp;
            
            wrappers = wrappers - (tmp * m) + tmp;
            if (wrappers == 0) break;
        }
    }
    for (int a0 = 0; a0 < t; a0++)
        cout << chocolates[a0] << endl;
    return 0;
}
