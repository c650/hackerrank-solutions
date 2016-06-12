#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void partition(vector<int> arr) {
    
    int length = arr.size() - 1; // store length modded to be without p in next steps
    int p = arr.front(); // declare pivot
    arr.erase(arr.begin()); // erases pivot from array
    
    vector<int> left;
    vector<int> right;
    
    int i, n;
    
    for (i = 0; i < length; i++) {  
        (arr[i] > p) ? right.push_back(arr[i]) : left.push_back(arr[i]); 
    }
    
    for (i = 0, n = left.size(); i < n; i++)
        cout << left[i] << " ";
    
    cout << p << " ";
    
    for (i = 0, n = right.size(); i < n; i++)
        cout << right[i] << " ";
    cout << "\n";
    
}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}