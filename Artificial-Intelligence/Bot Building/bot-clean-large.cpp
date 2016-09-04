#include <iostream>
#include <vector>
#include <algorithm>

struct Location {
    unsigned int x,y;
};

struct Dirt {
    Location loc;
    double distance;
};

void next_move(const int& posr, const int& posc, std::vector<std::vector<char>>& board) {

	Location b = {posc, posr};

	std::vector<Dirt> dirts;
	for (int i = 0, j, height = board.size(), width = board.front().size(); i < height; i++) {
		for (j = 0; j < width; j++) {

			if ('d' == board[i][j]) {
                dirts.push_back({{j, i}, 0.0});
                dirts.back().distance = sqrt( (j-b.x) * (j-b.x) + (i - b.y) * (i - b.y) );
            }

		}
	}

    Dirt best = *std::min_element(dirts.begin(), dirts.end(), [&](Dirt l, Dirt r){return l.distance < r.distance;});

    if (best.loc.x == b.x && best.loc.y == b.y) {
        std::cout << "CLEAN\n";
    } else {
        if (best.loc.y < b.y) {
            std::cout << "UP\n";
        } else if (best.loc.y > b.y) {
            std::cout << "DOWN\n";
        } else if (best.loc.x < b.x) {
            std::cout << "LEFT\n";
        } else {
            std::cout << "RIGHT\n";
        }
    }

}
int main(void) {
    int posr, posc, height, width;
    std::cin >> posr >> posc
             >> height >> width;

    std::vector<std::vector<char>> board(height, std::vector<char>(width));

    for (auto& row : board)
        for (auto& cell : row)
            std::cin >> cell;

    next_move(posr, posc, board);
    return 0;
}
