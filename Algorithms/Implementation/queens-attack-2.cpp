// not yet passing bigger TCs

#include <cmath>
#include <vector>
#include <iostream>
#include <utility>

struct Point {
	int x,y;
};

static void print(const Point& p) {
	std::cout << "( " << p.x << " , " << p.y << " )\n";
}

int main() {
    int n,k;
    std::cin >> n >> k;

	Point queen;
	std::cin >> queen.x >> queen.y;

	Point upper{queen.x, n},
	      lower{queen.x, 1},
	      left{1, queen.y},
	      right{n, queen.y},
	      upper_right{n - std::max(0, queen.y - queen.x), n - std::max(0, queen.x - queen.y)},
	      upper_left{1 + std::max(0, queen.x - queen.y), n - std::max(0, queen.y - queen.x)},
	      lower_right{n - std::max(0, queen.y - queen.x), 1 + std::max(0, queen.x - queen.y)},
	      lower_left{1 + std::max(0, queen.x - queen.y), 1 + std::max(0, queen.y - queen.x)};

	Point tmp;
	int diff_x, diff_y;
	while (k --> 0) {
		std::cin >> tmp.x >> tmp.y;
		diff_x = std::abs(tmp.x - queen.x);
		diff_y = std::abs(tmp.y - queen.y);

		if (!diff_x) {           /* mutual-exclusion w/ next `else if` guaranteed in problem statement */
			if (queen.y < tmp.y && tmp.y < upper.y) { /* is above and closer than prev best upper... */
				--tmp.y;
				upper = tmp;
			} else if (tmp.y > lower.y) { /* is below and closer than prev best lower */
				++tmp.y;
				lower = tmp;
			}
		} else if (!diff_y) {
			if (queen.x < tmp.x && tmp.x < right.x) {/* is to the right and closer than prev best right*/
				--tmp.x;
				right = tmp;
			} else if (tmp.x > left.x) { /* is to the left and closer than prev best left.*/
				++tmp.x;
				left = tmp;
			}
		} else if (diff_x == diff_y) {
			if (queen.y < tmp.y) { /* the tmp point is above the queen.*/
				if (queen.x < tmp.x && tmp.y <= upper_right.y) { /* tmp is to the right and above the queen, and better than prev upper_right. */
					--tmp.x; --tmp.y;
					upper_right = tmp;
				} else if (tmp.y <= upper_left.y) { /* tmp is left, above, and better than prev upper_left */
					++tmp.x; --tmp.y;
					upper_left = tmp;
				}
			} else { /* below the queen */
				if (queen.x < tmp.x && tmp.y >= lower_right.y) { /* tmp is right and below queen, better than prev lower_right*/
					--tmp.x; ++tmp.y;
					lower_right = tmp;
				} else if (tmp.y >= lower_left.y) { /* left, below, better than prev lower_left */
					++tmp.x; ++tmp.y;
					lower_left = tmp;
				}
			}
		}
	}

	/* handle corner cases */
	if (queen.x == 1) {
		lower_left = left = upper_left = queen;
	} else if (queen.x == n) {
		lower_right = right = upper_right = queen;
	} else if (queen.y == 1) {
		lower_left = lower = lower_right = queen;
	} else if (queen.y == n) {
		upper_left = upper = upper_right = queen;
	}

	print(upper);
	print(lower);
	print(right);
	print(left);
	print(upper_right);
	print(lower_right);
	print(upper_left);
	print(lower_left);

	int count = 0;
	count += upper.y - queen.y + queen.y - lower.y;
	std::cout << count << '\n';

	count += queen.x - left.x + right.x - queen.x;
	std::cout << count << '\n';

	count += upper_left.y + upper_right.y - 2*queen.y;
	std::cout << count << '\n';

	count += 2*queen.y - lower_left.y - lower_right.y;

	std::cout << count << '\n';

    return 0;
}
