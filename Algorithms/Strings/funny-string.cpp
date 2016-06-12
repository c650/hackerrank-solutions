#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	vector<string> forwards(t);
	vector<string> reverseds(t);

	for (int a0 = 0; a0 < t; a0++) {
	
		string forward;
		cin >> forward;

		string reversed = forward;
		reverse(reversed.begin(), reversed.end());

		forwards[a0] = forward;
		reverseds[a0] = reversed;
	}

	for (int a0 = 0; a0 < t; a0++) {	
		bool funny = true;

		for (int i = 0, n = forwards[a0].length(); i < (n - 1); i++) {
			if (abs(forwards[a0][i] - forwards[a0][i + 1]) != abs(reverseds[a0][i] - reverseds[a0][i + 1])) {
				funny = false;
				break;
			}
		}
		
		if (funny) {
			cout << "Funny" << endl;
		} else {
			cout << "Not Funny" << endl;
		}
	}
    return 0;
}