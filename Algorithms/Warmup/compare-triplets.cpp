#include <iostream>
#include <vector>

int main(){
    std::vector<int> arr(6);
    for (auto& _arr : arr)
        std::cin >> _arr;
    
    int a,b;
    a = b = 0;
    
    for (int i = 0; i < 3; i++) {
        if (arr[i] > arr[i+3])
            a++;
        else if (arr[i+3] > arr[i])
            b++;
    }
    
    std::cout << a << " " << b << std::endl;
}
