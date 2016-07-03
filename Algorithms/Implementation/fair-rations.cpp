#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<bool> peasants(n);

    int count;
    for (auto b : peasants) {
        std::cin >> count;
        b = bool(count % 2);
    }

    count = 0;
    bool a_tmp,b_tmp;
    for (int i = 0; i < n-1; i++) {
        a_tmp = peasants[i] && i+2 < n && peasants[i+2];
        b_tmp = peasants[i] && i+1 < n;

        if (a_tmp || b_tmp) {
            peasants[i] = !peasants[i];
            peasants[i+1] = !peasants[i+1];
            count += 2;
        }
    }

    bool tmp = false;
    for (auto b : peasants)
        tmp = tmp || b;

    if (tmp)
        std::cout << "NO";
    else
        std::cout << count;

    std::cout << std::endl;

    return 0;
}
