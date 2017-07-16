#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

static size_t count_isoc(const std::string& polygon);

int main() {
    int t; std::cin >> t;
    std::string tmp;
    for (int i = 1; i <= t; ++i) {
        std::cin >> tmp;
        std::cout << "Case " << i << ": " << count_isoc(tmp) << '\n';
    }
    return 0;
}

static size_t count_isoc(const std::string& polygon) {
	static std::vector<std::vector<std::vector<bool>>> incidence_cube;
	incidence_cube.resize(polygon.length());
	for (auto& matrix : incidence_cube) {
		matrix.resize(polygon.length());
		for (auto& vector : matrix) {
			vector.assign(polygon.length(), false);
		}
	}

	auto mark = [&](const size_t& i, const size_t& j, const size_t& k) {
		incidence_cube[i][j][k] =
		incidence_cube[i][k][j] =
		incidence_cube[j][i][k] =
		incidence_cube[j][k][i] =
		incidence_cube[k][i][j] =
		incidence_cube[k][j][i] =
		true;
	};

    size_t total = 0;

	auto check = [&](const size_t& i, const size_t& j, const size_t& k) {
		if (polygon[i] == polygon[k] && !incidence_cube[i][j][k]) {
			++total;
			mark(i,j,k);
			std::cout << "\t" << i << " " << j << " " << k << "\n";
		}
	};

	for (size_t i = 0, j; i < polygon.length(); ++i) {
		for (j = i+1; j < polygon.length(); ++j) {
			if (polygon[i] != polygon[j]) { // must be same color.
				continue;
			}

			size_t remain = polygon.length() - (j - i);
			if ((i + j) % 2 == 0) { // check if even # edges between vertices i,j.
				check(i, j, (i + j) / 2);
				if (remain >= 2)
					check(i, j, (j + remain / 2) % polygon.length());
			} else if (polygon.length() % 2 && j - i > 3) {
				check(i, j, (i + j + 1) / 2);
			}
		}
	}

    return total;
}
