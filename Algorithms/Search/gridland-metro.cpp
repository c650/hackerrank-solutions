#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    unsigned long long n,m,k;
    std::cin >> n >> m >> k;

    std::unordered_map<int, std::vector<std::pair<int,int>>> tracks;
    bool nochange = true;
    for (int i = 0,a,b,c; i < k; i++) {
        std::cin >> a >> b >> c;
        a--;b--;c--;
        if (tracks.find(a) == tracks.end()) {
            tracks[a] = {std::make_pair(b,c)};
            continue;
        }
        /* let's see if we can mod a prev track */
        for (auto& rr : tracks[a]) {
            if (b < rr.first && c >= rr.first) {
                rr.first = b;
                rr.second = std::max(c, rr.second);
                nochange = false;
                break;
            } else if (b <= rr.second && c > rr.second) {
                rr.first = std::min(b, rr.first);
                rr.second = c;
                nochange = false;
                break;
            } else if (b >= rr.first && c <= rr.second) {
                nochange = false;
                break;
            }
        }
        if (nochange)
            tracks[a].push_back(std::make_pair(b,c));
        nochange = true;
    }

    unsigned long long tot_area = n*m;

    for (auto& row : tracks) {
        for (auto& rr : row.second) {
            tot_area -= (rr.second - rr.first + 1);
        }
    }

    std::cout << tot_area << std::endl;

    return 0;
}

