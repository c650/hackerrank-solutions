// Not yet working.
#include <vector>
#include <queue>
#include <iostream>

struct action {
    bool is_r;
    unsigned int start, end;
};

int main(void) {
    
    unsigned int n;
    std::cin >> n;
    
    std::vector<unsigned int> elements(n);
    
    for (auto& _e : elements)
        std::cin >> _e;
    
    std::vector<bool> descending_to( n , false ), out_of_place(n, false);
    
    for (unsigned int i = 0; i < n-1; ++i) {
        descending_to[ i ] = elements[ i ] > elements[ i + 1 ];
        out_of_place [ i ] = descending_to[i] || i > 0 && elements[i-1] > elements[i];
    }
    
    bool reverse_necessary = false;    
    unsigned int count_instances_of_decreasing = 0;
    
    std::vector<action> actions;
    
    for (unsigned int i = 0, j; i < n-1; ++i) {
        
        if (!descending_to[i])
            continue;
        
        //std::cout << "i = " << i;
        ++count_instances_of_decreasing;
        
        for (j = i+1; j < n && descending_to[j]; ++j);
        
        reverse_necessary = reverse_necessary || (j - i) > 1;
        
        if (j < n-1 && elements[i] > elements[j+1]) // checks if swap/reverse would still leave the list unsorted.
            ++count_instances_of_decreasing;
        
        actions.push_back({reverse_necessary, i, j});
        
        i = j;
    }
    
    for (unsigned int i = 0, j; i < n; ++i) {
        if (!descending_to[i]) continue;
        for (j = n-1; j > i && out_of_place[j]; --j);
        if (j > i+1 && j != n) {
            actions.push_back({false, i, j});
            ++count_instances_of_decreasing;
        }
    }

    for (auto& a : actions)
        std::cout << (a.is_r ? "reverse" : "swap") << " " << a.start+1 << " " << a.end+1 << '\n';
    
    if (count_instances_of_decreasing <= 1) {
        std::cout << "yes\n";

        if (count_instances_of_decreasing == 1) {
            action a = actions.front();
            std::cout << (a.is_r ? "reverse" : "swap") << " " << a.start+1 << " " << a.end+1 << '\n';
        }
    } else {
        std::cout << "no\n";
    }
    
    return 0;
}
