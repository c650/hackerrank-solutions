#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool lookfor(const vector<string>& g, const vector<string>& p) {
    int g_height = g.size(),
      g_width = g[0].size(),
      p_height = p.size(),
      p_width = p[0].size();
    
    int r_height = g_height - p_height + 1,
      r_width = g_width - p_width + 1;
    
    int i, j, k, l;
    // O(n^2) lol no thanks
    for(i = 0; i < r_height; i++) { // iterate down g
        for (j = 0; j < r_width; j++) { // iterate accross g
            
            for (k = 0; k < p_height; k++) { // iterate down p
                for (l = 0; l < p_width; l++) {
                    // lel bcs g[i][j] doesn't work but [i+k]... does bcs relative pos
                    // you played yourself, chalie
                    if (g[i+k][j+l] == p[k][l]) {
                        if (k + 1 == p_height && l + 1 == p_width)
                            return true;
                    } else {
                        k = p_height; break;
                    }
                }
            }
        }
    }
    
    return false;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        
        cout << (lookfor(G,P) ? "YES" : "NO") << endl;
    }
    return 0;
}
