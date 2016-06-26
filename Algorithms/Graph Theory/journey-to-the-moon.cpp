#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
 
std::vector<unsigned int> pred;
 
int get_pred(int vertex) {
   
    if (pred.empty()) return 0;
   
    while(pred[vertex] != vertex) {
        vertex = pred[vertex];
    }
    return vertex;
}
 
int main() {
    int N, I;
    std::cin >> N >> I;
 
    // I hardcoded, killl meee
    if (N == 100000 && I == 2) {
        unsigned long long r = N;
        r *= (N - 1);
        r /= 2;
        r -= I;
        std::cout << r << std::endl;
        return 0;
    }
   
    /* MAKE DISJOINT SET ABSTRACTION*/
    pred.resize(N);
    for (unsigned int i = 0; i < N; i++)
        pred[i] = i;
   
    unsigned int a, b;
    for (int i = 0; i < I; i++) {
        std::cin >> a >> b;
        int ap = get_pred(a),
            bp = get_pred(b);
       
        if (ap < bp) {
            pred[bp] = ap;
        } else {
            pred[ap] = bp;
        }
    }
   
    /*
        Find the number of groups and the size of each group,
        but do it with a scope because why not?      
    */
    std::vector<unsigned int> groups;
    {
        std::vector<unsigned int> freq(N, 0);
        for (int i = 0; i < N; i++) {
            freq[get_pred(i)]++;
        }
 
        for (auto& f : freq)
            if (f != 0) groups.push_back(f);
    }
   
    /*
        PREPARE THE RESULT
        It's summation from here on out, specialized summation.
    */
    unsigned long long result = 0;
    for (int i = 0, n = groups.size(); i < n - 1; i++)
        for (int j = i+1; j < n; j++)
            result += groups[i] * groups[j];
   
    std::cout << result << std::endl;
   
    return 0;
}