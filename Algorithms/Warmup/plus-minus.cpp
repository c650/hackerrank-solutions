#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    double positive;
    double negative;
    double zero;
    for(int i = 0; i < n; i++) {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }
    cout << positive / n << endl;
    cout << negative / n << endl;
    cout << zero / n << endl;
    return 0;
}
