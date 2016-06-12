#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void insertionSort(vector<int>& arr); // sorting prototype
void printVec(vector<int>& arr); // printVec prototype

int main(void) {
    int n; cin >> n; // get the length of the vector
    
    vector<int> arr(n); // declare vector
    
    for (int i = 0; i < n; i++) // populate vector
        cin >> arr[i];

    insertionSort(arr); // outsource to func; see below
   
    return 0;
}

void insertionSort(vector<int>& arr) {
    
    int vecSize = arr.size(); // hold vector size for ease of access
    int valToInsert = arr.back(); // put last element as temp variable
    bool notInserted = true;
    // iterate thru vec in reverse, skipping last element
    for (int i = vecSize - 2; i >= 0; i--) {
        if (arr[i] > valToInsert) {
            arr[i + 1] = arr[i]; // assign value to next element; shift up
            printVec(arr); // print the vector
        } else {
            // put our valToInsert next to the elem smaller than/ equal to it
            arr[i + 1] = valToInsert;
            printVec(arr);
            notInserted = false;
            break;
        }
    }
    if (notInserted) {
        arr[0] = valToInsert;
        printVec(arr);
    }
}

void printVec(vector<int>& arr) {
    for (int i = 0, n = arr.size(); i < n; i++) // iterate thru each element
        cout << arr[i] << " ";
    
    cout << "\n";
}