#include <iostream>
#include <vector>

using namespace std;

/*
	Declare global constants. The only current one needed is
	the size of the board:
*/
	const int boardsize = 5;

/*
	Declare a class Location to handle coordinates more easily.
*/
class Location {
  public:
	int x,y;
};

void nextMove(int posr, int posc, vector<string> board) {

/*
	Initialize an instance of Location to save the coordinates
	of the bot. 
*/
	Location b;
	b.x = posc; b.y = posr;

/*
	Locate the first dirt spot.
*/
	Location d;
	string dirt = "d"; // initialize this to make string comp easier

	int i, j;
	for (i = 0; i < boardsize; i++) {

		for (j = 0; j < boardsize; j++) {

			if (dirt[0] == board[i][j]) {

				d.x = j; d.y = i;

				i = j = boardsize; // end the loop
			}
		}
	}

/*
	Determine the next move to make for the bot. 

	Options are: UP, DOWN, LEFT, RIGHT, CLEAN.

	We will try to CLEAN first by checking to see
	if the bot is currently on a dirtspot.

	If we don't clean something, we'll move closer
	to the first dirt spot in the vector of dirt spots.
*/
	
	bool didntClean = true;
	
	if ( (b.x == d.x) && (b.y == d.y) ) {
		
		cout << "CLEAN" << endl;
			
		didntClean = false; // avoid making two moves at once
	}

	if (didntClean) {
		// check the vertical first
		if (d.y < b.y) {

			cout << "UP" << endl;

		} else if (d.y > b.y) {

			cout << "DOWN" << endl;

		} else {
			if (d.x < b.x) {

				cout << "LEFT" << endl;

			} else if (d.x > b.x) {

				cout << "RIGHT" << endl;

			}
		}
	}
}

int main(void) {
	int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}