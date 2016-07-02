#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int t, n; std::cin >> t;
    while(t-- > 0) {
        std::cin >> n;
        std::vector<int> line(n);
        for (auto& p : line) std::cin >> p;

        bool chaotic = false;
        int count = 0;
        for (int i = line.size() - 1; i >= 0; i--) {
            if (line[i] - (i+1) > 2) {
                std::cout << "Too chaotic" << std::endl;
                chaotic = true;
                break;
            }
            for (int j = line[i] - 2 > 0 ? line[i] - 2 : 0; j < i; j++) {
                if (line[j] > line[i]) {
                    count++;
                }
            }
        }
        if (!chaotic)
            std::cout << count << std::endl;
    }
    return 0;
}
