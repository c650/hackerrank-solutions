#include <bits/stdc++.h>

typedef std::pair<int,int> ipair;

const int BOARD_LEN = 8;

std::vector<ipair> best;
std::vector<ipair> offset = {
    {-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
};

std::vector<ipair> curr; // for `go`
std::vector<std::vector<char>> board(BOARD_LEN);

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

    /*std::printf("Trying this board\n");
    for (const auto& r : board) {
        for (const auto& c : r)
            std::putchar(c);
        std::putchar('\n');
    }*/

    bool good = true;

	for (int i = -1; i <= 1 && good; ++i) {
		for (int j = -1; j <= 1 && good; ++j) {
			if (valid_point({king.first+i,king.second+j})) {
				good = good && !can_move[king.first+i][king.second+j];
				if (can_move[king.first+i][king.second+j]) {
					//std::printf("King (%d,%d) can move to (%d,%d)\n",king.first,king.second,king.first+i, king.second+j);
				}
			}
			//&& (board[king.first+i][king.second+i] != 'k' || i == 0 && j == 0);
		}
	}

	board[other.first][other.second] = '*';

    return good;
}

static void go(const int& k, const std::vector<ipair>& kings) {
    if (curr.size() > 4) return;

    if (k >= offset.size() * 2) {
        if (check(kings.front(),kings.back()) && check(kings.back(),kings.front())) {
            if (best.size() > curr.size())
                best = curr;
        }
        return;
    }

    // skip
    go(k+1, kings);

    // do
    ipair init = kings[k/offset.size()];
    init.first += offset[k % offset.size()].first;
    init.second += offset[k % offset.size()].second;

    if (valid(init) && init != kings.front() && init != kings.back()) {
        curr.push_back(init);
        board[init.first][init.second] = 'q';

        go(k+1, kings);

        curr.pop_back();
        board[init.first][init.second] = '*';
    }
}

static void one_case(const bool& new_line) {
    std::vector<ipair> kings(2);
    for (auto& k : kings) {
        std::scanf("%d %d",&k.first,&k.second);
        // board[k.first][k.second] = 'k';
    }

    best.assign(10, {0,0});
    go(0, kings);

    if (best.size() == 10) {
        throw std::runtime_error("this shouldnt happen lol");
    }

	// std::printf("\nTest case: %d %d %d %d\n", kings.front().first,kings.front().second, kings.back().first,kings.back().second);

    std::printf("%d%s",static_cast<int>(best.size()), new_line ? "\n":"");
    for (const auto& q : best) {
        std::printf("Q %d %d\n",q.first,q.second);
    }

    /*curr = best;
    check(kings);
    for (const auto& r : board) {
        for (const auto& c : r)
            std::putchar(c);
        std::putchar('\n');
    }*/

    for (const auto& k : kings) {
        board[k.first][k.second] = '*';
    }
}

int main(void) {
    board.assign(BOARD_LEN, std::vector<char>(BOARD_LEN, '*'));

    int n;
    std::scanf("%d",&n);
    while(n--) one_case(true);
    return 0;
}
