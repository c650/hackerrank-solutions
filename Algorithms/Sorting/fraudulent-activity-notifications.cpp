#include <vector>
#include <iostream>
#include <algorithm>

/*
	This solution uses counting sort
	because the range of values is [0,200]
	and is thus easy to store within a freq
	array.

	We can easily find the median by looking
	for the index of it within freq (after
	the freqs have been addedd across the
	freq array to reflect the index at which
	`i` is no longer present [in a sorted array]).

	Do a little arithmetic, and account for the
	case of d mod 2 == 0.
*/

int main(void) {
    int n,d;
    std::cin >> n >> d;
    
    std::vector<int> days(n);
    for (auto& e : days)
        std::cin >> e;
    
    std::vector<size_t> freq(201);
    size_t i = 0;
    for (; i < d; ++i)
        ++freq[days[i]];
    for (size_t j = 1; j < freq.size(); ++j)
        freq[j] += freq[j-1];

    size_t cnt = 0;
    double tmp;
    
    size_t j;
    while(i < n) {
        for (j = 0; j < freq.size() && freq[j] < d/2; ++j);
        
        //  freq[j] >= d/2
        if (freq[j] == d/2) {
            tmp = j+1;
            if (d % 2 == 0) {
                tmp += j;
                tmp /= 2;
            }
        } else {
            tmp = j;
            if (d % 2 == 0) {
                tmp += freq[j-1] + 1 == freq[j] ? j-1 : j;
                tmp /= 2;
            }
        }
        tmp *= 2;
        
        cnt += days[i] >= tmp;

        for (j = days[i-d]; j < freq.size(); ++j)
            --freq[j];
        for (j = days[i]; j < freq.size(); ++j)
            ++freq[j];
        
        ++i;
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}

