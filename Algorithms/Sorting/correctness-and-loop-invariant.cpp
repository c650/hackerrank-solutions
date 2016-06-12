#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
// 4 1 2 3 5 6
void insertionSort(int N, int arr[]) {
    int i,j,value;
    for(i=1;i<N;i++) // first value @ i = 0 is always technically sorted
    {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        // it's j+1 because j is decremented on last run of while loop
        arr[j+1]=value;
    }
    for(i=0;i<N;i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(void) {

    int N;
    cin >> N;
    int arr[N], i;
    for(i = 0; i < N; i++) {
        cin >> arr[i];
    }

    insertionSort(N, arr);

    return 0;
}