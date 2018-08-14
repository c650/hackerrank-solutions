#include <bits/stdc++.h>

#define FI first
#define SE second

typedef long long ll;

static inline void setio(void);

ll a[100003];
ll ob[100003];

int main(void) {
    setio();

    ll t; std::cin >> t;
    while (t--) {
        ll n, k; std::cin >> n >> k;
        for (ll i = 0; i < n; ++i)
            std::cin >> a[i];
        a[n] = -1;
        
        memset(ob, 0, sizeof(ob));
        
        ll last = -1, s = 0;
        for (ll i = 0; i <= n; ++i) {
            for (; i <= n && a[i] == 1; ++i);
            ob[s] = i - last - 1;
            a[s] = a[i];
            ++s;
            last = i;
        }
        
        ll prod = 1, ans = 0;
        if (k == 1) {
            for (ll i = 0; i < s; ++i) {
                ans += ((ob[i]+1) * ob[i]) / 2;
            }
            std::cout << ans << "\n";
            continue;
        }
        
        
        for (ll i = 0, j = 0; j < s; ++j) {
            if (a[j] < 0) break;
            prod *= a[j];
            if (prod == k) {
                ans += (ob[i] + 1LL) * (ob[j+1] + 1LL);
            }
            while (prod >= k && i <= j) {
                prod /= a[i++];
                if (prod == k && i <= j) {
                    ans += (ob[i] + 1LL) * (ob[j+1] + 1LL);
                }
            }
        }
        
        std::cout << ans << "\n";
    }

    return 0;
}

static inline void setio(void) {
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
    std::cout.precision(10); std::cout << std::fixed;
}
