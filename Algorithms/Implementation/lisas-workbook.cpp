#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Page {
    int chapter, num_probs, first_prob;
};

int main() {
    int n,k; cin >> n >> k;
    
    vector<Page> book;
    int ch_probs;
    for (int i = 0; i < n; i++) {
        cin >> ch_probs;
        for (int j = 1; j <= ch_probs; j += k) {
            book.push_back( {.chapter = i, .num_probs = k, .first_prob = j});
            if (j+k > ch_probs)
                book.back().num_probs = ch_probs - j + 1;
        }
    }
    
    unsigned int special_pages = 0;
    for (int i = 0, n = book.size(); i < n; i++) {
        if (i+1 >= book[i].first_prob && i+1 <= book[i].first_prob + book[i].num_probs - 1)
            special_pages++;
    }
    
    cout << special_pages << endl;
    
    return 0;
}