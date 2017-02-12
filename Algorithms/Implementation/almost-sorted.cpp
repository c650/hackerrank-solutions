// Not yet working.
#include <vector>
#include <queue>
#include <iostream>

struct action {
    bool is_r;
    size_t start, end;
};

static bool swappable(const std::vector<size_t>& elements, size_t i, size_t j);
static void do_swap_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n);

// static bool descending(const std::vector<size_t>& elements, size_t i) {
//
// }

static void do_reverse_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n);

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

    std::vector<action> actions;

	do_reverse_check(elements, actions, n);

	if (actions.empty())
		do_swap_check(elements, actions, n);

    if (sorted || actions.size() == 1) {

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

static void do_swap_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n) {
	for (size_t i = 0, m = n-1, j; i < m; ++i)
		for (j = i+1; j < n; ++j)
			if (swappable(elements, i, j))
				actions.push_back({false, i, j});
}

static void do_reverse_check(const std::vector<size_t>& elements, std::vector<action>& actions, size_t n) {
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
