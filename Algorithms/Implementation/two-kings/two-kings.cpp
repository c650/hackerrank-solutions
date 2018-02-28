#include <bits/stdc++.h>

typedef std::pair<int,int> ipair;

const int BOARD_LEN = 8;

std::vector<ipair> best;

std::vector<ipair> curr; // for `go`
std::vector<std::vector<char>> board(BOARD_LEN);

std::vector<ipair> pos; // all possible positions.

static inline bool valid_point(const ipair& p) {
    return p.first >= 0 && p.first < BOARD_LEN && p.second >= 0 && p.second < BOARD_LEN;
}


static inline bool valid(const ipair& p) {
    return valid_point(p) && board[p.first][p.second] == '*';
}

/*
    checks to see if kings are in checkmate,
    assumes `curr` is being checked.
*/
static bool check(const ipair& king, const ipair& other) {
    static std::vector<std::vector<char>> can_move;
    can_move.assign(BOARD_LEN, std::vector<char>(BOARD_LEN, true));

	board[other.first][other.second] = 'k';
	can_move[other.first][other.second] = false; /* cant sit on the other king */

	for (const auto& queen : curr)
		board[queen.first][queen.second] = 'q';

    // fill out queen strike zones
    for (const auto& queen : curr) {

        // down
        for (int i = queen.first+1; i < BOARD_LEN; ++i) {
            can_move[i][queen.second] = false;
            if (board[i][queen.second] != '*')
                break;
        }

        // up
        for (int i = queen.first-1; i >= 0; --i) {
            can_move[i][queen.second] = false;
            if (board[i][queen.second] != '*')
                break;
        }

        // right
        for (int j = queen.second+1; j < BOARD_LEN; ++j) {
            can_move[queen.first][j] = false;
            if (board[queen.first][j] != '*')
                break;
        }

        // left
        for (int j = queen.second-1; j >= 0; --j) {
            can_move[queen.first][j] = false;
            if (board[queen.first][j] != '*')
                break;
        }

        // down and right
        for (int i = 1; i+queen.first < BOARD_LEN && i+queen.second < BOARD_LEN; ++i) {
            can_move[queen.first+i][queen.second+i] = false;
            if (board[queen.first+i][queen.second+i] != '*')
                break;
        }

        // up and right
        for (int i = 1; queen.first - i >= 0 && i+queen.second < BOARD_LEN; ++i) {
            can_move[queen.first-i][queen.second+i] = false;
            if (board[queen.first-i][queen.second+i] != '*')
                break;
        }

        // down and left
        for (int i = 1; queen.first - i >= 0 && i-queen.second >= 0; ++i) {
            can_move[queen.first-i][queen.second-i] = false;
            if (board[queen.first-i][queen.second-i] != '*')
                break;
        }

        // up and left
        for (int i = 1; queen.first + i < BOARD_LEN && i-queen.second >= 0; ++i) {
            can_move[queen.first+i][queen.second-i] = false;
            if (board[queen.first+i][queen.second-i] != '*')
                break;
        }
    }

    bool good = true;

	for (int i = -1; i <= 1 && good; ++i) {
		for (int j = -1; j <= 1 && good; ++j) {
			if (valid_point({king.first+i,king.second+j})) {
				good = good && !can_move[king.first+i][king.second+j];
			}
		}
	}

	board[other.first][other.second] = '*';
	for (const auto& queen : curr)
		board[queen.first][queen.second] = '*';

    return good;
}

static void one_case(const int& case_num) {
    std::vector<ipair> kings(2);
    for (auto& k : kings) {
        std::scanf("%d %d",&k.first,&k.second);
    }

    best.resize(10);

	curr.resize(2);
	for (int i = 0; i < pos.size(); ++i) {

		curr[0] = pos[i];
		if (!valid(curr[0]) || curr[0] == kings.front() || curr[0] == kings.back()) continue;

		for (int j = i+1; j < pos.size(); ++j) {

			curr[1] = pos[j];
			if (!valid(curr[1]) || curr[1] == kings.front() || curr[1] == kings.back()) continue;

			if (check(kings.front(),kings.back()) && check(kings.back(),kings.front()) && curr.size() < best.size()) {
				best = curr;
			}

			curr.push_back({0,0});
			for (int k = j+1; k < pos.size(); ++k) {

				curr[2] = pos[k];
				if (!valid(curr[2]) || curr[2] == kings.front() || curr[2] == kings.back()) continue;

				if (check(kings.front(),kings.back()) && check(kings.back(),kings.front()) && curr.size() < best.size()) {
					best = curr;
				}
			}
			curr.pop_back();
		}
	}

	// std::printf("tc #%d: %d %d %d %d\n", case_num, kings.front().first,kings.front().second,kings.back().first,kings.back().second);
	std::printf("%d\n", static_cast<int>(best.size()));
	for (const auto& q : best) {
		std::printf("Q %d %d\n", q.first,q.second);
		board[q.first][q.second] = 'q';
	}

	// for (const auto& k : kings) {
    //     board[k.first][k.second] = 'k';
    // }

	// for (const auto& r : board) {
	// 	for (const auto& c : r) {
	// 		std::putchar(c);
	// 	}
	// 	std::putchar('\n');
	// }

    for (const auto& k : kings) {
        board[k.first][k.second] = '*';
    }
}

int main(void) {
    board.assign(BOARD_LEN, std::vector<char>(BOARD_LEN, '*'));

	for (int i = 0; i < BOARD_LEN; ++i) {
		for (int j = 0; j < BOARD_LEN; ++j) {
			pos.push_back({i,j});
		}
	}

    int n;
    std::scanf("%d",&n);
    for (int i = 1; i <= n; ++i) one_case(i);
    return 0;
}
