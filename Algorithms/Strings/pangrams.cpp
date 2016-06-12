#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string input;
    getline(cin, input); // gets entire line
        
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end()); // remove all the spaces
    transform(input.begin(), input.end(), input.begin(), ::tolower); // lowercase the whole thing
    
    if (input.length() < 26) {
        cout << "not pangram" << endl;
        return 1;
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0, n = alphabet.length(); i < n; i++) {
        if (input.find(alphabet[i]) == string::npos) {
            cout << "not pangram" << endl;
            return 2;
        }
    }
    
    cout << "pangram" << endl;
    return 0;
}
