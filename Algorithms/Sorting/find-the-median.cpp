#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void quickselect(vector<int> &v, int begin, int end, int median_idx) {
	if (end - begin <= 1)
		return;

	int a, b;
	int pivot = v[end - 1];

	a = begin;
	b = end - 1;

	while (b > a) {
		if (v[b - 1] > pivot) {
			v[b] = v[b - 1];
			b--;
		} else {
			int tmp = v[b - 1];
			v[b - 1] = v[a];
			v[a] = tmp;
			a++;
		}
	}

	v[b] = pivot;

	if (begin <= median_idx && b >= median_idx) {
		quickselect(v, begin, b, median_idx);
	} else if (b + 1 <= median_idx && end >= median_idx) {
		quickselect(v, b + 1, end, median_idx);
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> input(n);
	for (auto &a : input)
		std::cin >> a;

	quickselect(input, 0, input.size(), input.size() / 2);

	std::cout << input[input.size() / 2] << std::endl;

	return 0;
}
