#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void quickSort(vector<int>& arr) {
    if (arr.size() <= 1) return;

    int pivot_point = 0;
	int pivot_char = arr[0];

	vector<int> left, right;

	for (int i = 0, n = arr.size(); i < n; i++) {
		if (i == pivot_point) continue;

		if (arr[i] < pivot_char) {
			left.push_back(arr[i]);
		} else {
			right.push_back(arr[i]);
		}
	}

	quickSort(left);
	quickSort(right);

	arr = left;
	arr.push_back(pivot_char);
	arr.insert(arr.end(), right.begin(), right.end());
    
    for (auto& i : arr)
        cout << i << " ";
    
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}