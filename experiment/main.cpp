#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#include "../include/CellType.h"
#include "../include/GameBoard.h"
#include "../include/Display.h"

int main(){

	//GameBoard board(7,7);
	Display display("input.txt", "output.txt");
	vector<vector<CellT> > grid;

	grid = display.read_game_state();
	GameBoardT board(7,7, grid);

	grid = board.get_gameBoard();
	display.display_game_state(board.get_gameBoard());
	board.iteration(1);
	cout<<endl;
	display.display_game_state(board.get_gameBoard());
	board.iteration(1);

	return 0;
}