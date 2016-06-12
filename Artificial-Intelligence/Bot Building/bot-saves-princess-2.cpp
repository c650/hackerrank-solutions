#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

struct Location {
	int x,y;
};

void nextMove(int n, int r, int c, vector<string> grid){
/*
	Initialize two instances of Location to more easily handle
	the coordinates for mario and the princess (respectively):
*/	Location m, p; 

	// set the location for mario
	m.x = c; m.y = r;

/*
	Find the princess:
*/
	int i,j;
	string princess = "p"; // this is for easier string comparison.

	for (i = 0; i < n; i++) {
		for (j= 0; j < n; j++) {
			if (princess[0] == grid[i][j]) {
				p.x = j; p.y = i;
				i = j = n; // end the loops
			}
		}
	}

/*
	Determine the first move to make:
*/
	// check the vertical first
	if (p.y < m.y) {
		cout << "UP" << endl;
	} else if (p.y > m.y) {
		cout << "DOWN" << endl;
	} else {
	/*
		Nesting the horizontal will give prefence to the vertical.
		This is desired. The `else` block shall only run if the locations
		of mario and the princess are vertically equivilent. 	
	*/
		if (p.x < m.x) {
			cout << "LEFT" << endl;
		} else if (p.x > m.x) {
			cout << "RIGHT" << endl;
		}
	}
}
int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
