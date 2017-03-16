/*
	almost-sorted.cpp
	finally working...
*/
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

struct action {
    bool is_r;
    size_t start, end;
};

static bool swappable(const std::vector<size_t>& elements, size_t i, size_t j);
static void do_swap_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n, const std::vector<size_t>& sorted_elements);

static void do_reverse_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n, const std::vector<size_t>& sorted_elements);

static bool make_sure(std::vector<size_t>& elements , const std::vector<size_t>& sorted_elements, action a);

int main(void) {

    size_t n;
    std::cin >> n;

    std::vector<size_t> elements(n);

	bool sorted = true; size_t last = 0;
    for (auto& _e : elements) {
        std::cin >> _e;
		sorted = sorted && _e >= last;
		last = _e;
	}

	if (sorted) {
		std::cout << "yes\n";
		return 0;
	}

    std::vector<action> actions;

	std::vector<size_t> sorted_elements(elements);
	std::sort(sorted_elements.begin(),sorted_elements.end());

	do_reverse_check(elements, actions, n, sorted_elements);
	if (actions.empty())
		do_swap_check(elements, actions, n, sorted_elements);

    if (actions.size() == 1 && make_sure(elements, sorted_elements, actions.front())) {

		std::cout << "yes\n";

        if (actions.size() == 1) {
            action a = actions.front();
            std::cout << (a.is_r ? "reverse" : "swap") << " " << a.start+1 << " " << a.end+1 << '\n';
        }
    } else {
        std::cout << "no\n";
    }

    return 0;
}

static bool swappable(const std::vector<size_t>& elements, size_t i, size_t j) {
	if (i > j)
		std::swap(i,j);
	if (i >= elements.size() || j >= elements.size())
		return false;

	bool res = i < elements.size()-1 && elements[i] > elements[i+1]
	           && (j > 0 && elements[j] < elements[j-1]);

	if (!res) return res;

	res = res && elements[i] > elements[j]
	          && (j == elements.size()-1 || elements[i] < elements[j+1])
			  && elements[i] >= elements[j-1]
	          && (i == 0 || elements[j] > elements[i-1])
			  && elements[j] <= elements[i+1];

	return res;
}

static void do_swap_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n, const std::vector<size_t>& sorted_elements) {

	for ( size_t i = 0,j, m = n-1 ; i < m ; ++i ) {
		if (elements[i] != sorted_elements[i]) {
			for ( j = i+1; j < n ; ++j)
				if (swappable(elements,i,j))
					actions.push_back({false,i,j});
		}
	}
}

static void do_reverse_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n, const std::vector<size_t>& sorted_elements) {
	static auto get_end_of_decline = [&elements, &n](size_t i){
		for (; i < n-1 && elements[i] > elements[i+1]; ++i);
		return i;
	};

	for (size_t i = 0, j; i < n && actions.empty(); ++i) {
		j = get_end_of_decline(i);
		if (j > i+1) {
			actions.push_back({true, i, j});
			i = j;
		}
	}
}

static bool make_sure(std::vector<size_t>& elements , const std::vector<size_t>& sorted_elements, action a) {
	if (a.is_r) {
		std::reverse(elements.begin() + a.start, elements.begin() + a.end + 1);
	} else {
		std::swap(elements[a.start], elements[a.end]);
	}
	for (size_t i = 0; i < elements.size(); ++i)
		if (sorted_elements[i] != elements[i])
			return false;
	return true;
}
