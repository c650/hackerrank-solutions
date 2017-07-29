#include <set>
#include <string>
#include <iostream>

static int weight(const char& c);

int main(){
    
    std::string str;
    std::cin >> str;
    
    std::set<int> values;
    for (size_t i = 0, j; i < str.length(); i = j) {
        char last = str[i];
        int last_w = 0;

        for (j = i; j < str.length() && str[j] == last; ++j) {
            last_w += weight(last);
            values.insert(last_w);
        }
    }
    
    
    int q, tmp;
    std::cin >> q;

    while (q --> 0) {
        std::cin >> tmp;
        std::cout << (values.find(tmp) == values.end() ? "No" : "Yes") << '\n';
    }
    
    return 0;
}

static int weight(const char& c) {
    return c - 'a' + 1;
}
