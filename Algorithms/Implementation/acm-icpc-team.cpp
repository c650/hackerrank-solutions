#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <utility>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> topic(n);
    std::vector<int> topicInt;
    
    for(int topic_i = 0; topic_i < n; topic_i++){
       std::cin >> topic[topic_i];
    }
    for (int i = 0; i < n; i++) {
        const char* c = topic[i].c_str();
        topicInt.push_back(strtol(c, NULL, 2));
    }
    
    int max = 0, max_cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if ((topicInt[i] | topicInt[j]) > max) {
                max = topicInt[i] | topicInt[j];
                max_cnt = 1;
            } else if ((topicInt[i] | topicInt[j]) == max)
                max_cnt++;
    
    std::cout << log2(max+1) << std::endl << max_cnt << std::endl;
    return 0;
}
