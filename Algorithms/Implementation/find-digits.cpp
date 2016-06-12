#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    int counts[t] = {0};
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        string str = to_string(n);
        
        for (int i = 0, x = str.size(); i < x; i++) {
            if (str[i] != '0' && n % (str[i] - '0') == 0) {
                counts[a0]++;
            }
        }
    }
    for(int i = 0; i < t; i++)
        cout << counts[i] << endl;
    return 0;
}