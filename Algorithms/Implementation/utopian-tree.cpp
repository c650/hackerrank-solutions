#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    int arr[t];
    for(int a0 = 0; a0 < t; a0++){
        int height = 1;
        
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                height *= 2;
            } else {
                height++;
            }
        }
        arr[a0] = height;
    }
    
    for (int i = 0; i < t; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
