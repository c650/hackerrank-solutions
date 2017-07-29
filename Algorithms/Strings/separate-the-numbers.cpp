#include <string>
#include <iostream>

static unsigned long long analyze(const std::string& str);

int main(void) {
    
    int n;
    std::cin >> n;
    
    std::string str;
    unsigned long long ans;
    while (n --> 0) {
        std::cin >> str;
        ans = analyze(str);
        if (ans > 0) {
            std::cout << "YES " << ans;
        } else {
            std::cout << "NO";
        }
        std::cout << '\n';
    }
    
    return 0;
}

static unsigned long long analyze(const std::string& str) {
    size_t count = 1, i, j;
    
    unsigned long long num;
    std::string tmp;
    while (count < str.length()) {
        try {
            num = std::stoull(str.substr(0, count));
        } catch (...) {
            return 0;
        }
        
        i = 1;
        j = count;
        bool yes = true;
        while (j < str.length() && yes) {
            tmp = std::to_string(num + i++);
            yes = yes && str.substr(j, tmp.length()) == tmp;
            j += tmp.length();
        }
        if (yes)
            return num;
        
        ++count;
    }
    
    return 0;
}
