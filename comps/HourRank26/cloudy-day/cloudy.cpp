/*
	HourRank 26 upsolve
	Cloudy Day.
	02/03/2018
*/
#include <bits/stdc++.h>

typedef long long ll;

struct city {
    ll pop;
    ll loc;

    ll id;

    city() : city(0,0,-1) {}

    city(const ll& p, const ll& l, const ll& _id) {
        pop = p;
        loc = l;
        id = _id;
    }

    bool operator<(const city& o) const {
        return loc < o.loc || loc == o.loc && pop < o.pop;
    }
};

struct cloud {
    ll loc, range;
    ll id;
};

int main() {
    std::set<city> cities;

    ll n;
    std::scanf("%lld", &n);

    ll deff=0;
    std::vector<ll> pops(n);
    for (auto& e : pops) {
        std::scanf("%lld", &e);
        deff += e;
    }

    for (ll i = 0, location; i < n; ++i) {
        std::scanf("%lld", &location);
        cities.insert(city(pops[i], location, i));
    }

    ll m;
    std::scanf("%lld", &m);

    std::vector<cloud> clouds(m);
    ll bleh = 0;
    for (auto& e : clouds) {
        std::scanf("%lld", &e.loc);
        e.id = bleh++;
    }
    for (auto& e : clouds) {
        std::scanf("%lld", &e.range);
    }

    std::vector<ll> covers(n,-1);
    std::vector<ll> cnts(m);

    city tmp;
    std::vector<std::set<city>::iterator> rem;
    for (const auto& c : clouds) {
        tmp.loc = c.loc - c.range;
        ll end = c.loc + c.range;
        std::set<city>::iterator it = cities.lower_bound(tmp);
        for (; it != cities.end() && it->loc <= end; ++it) {
            if (covers[it->id] == -1) {
                deff -= it->pop;
                cnts[c.id] += it->pop;
                covers[it->id] = c.id;
            } else {
                cnts[covers[it->id]] -= it->pop;
				covers[it->id] = m;
                rem.push_back(it);
            }
        }
        while(!rem.empty())
            cities.erase(rem.back()), rem.pop_back();
    }

	if (cities.size() == 0) {
		std::printf("0\n");
	} else {
		std::printf("%lld\n", deff + *std::max_element(cnts.begin(),cnts.end()));
	}

    return 0;
}
