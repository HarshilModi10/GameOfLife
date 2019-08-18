/**
 * \file testGameBoard.cpp
 * \brief The class file for testing GameBoard
 * \date April 3rd, 2019
*/

#include "../include/CellType.h"
#include "../catch/catch.h"
#include "../include/GameBoard.h"
#include "../include/Display.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
Please note that for the display module, for file input and output, manual testing was preformed
This was done because catch does not have a screen or textfile tester.
*/

TEST_CASE("Test for GameBoard ", "[GameBoardT]"){


	SECTION("Test correct size with file input and output"){

		//basic initial processing for input
		//the trial file was used for testing throughout this module
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();
		REQUIRE(grid.size() == r);
		REQUIRE(grid[0].size() == c);
	}

		SECTION("Testing: set_cell_state()"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();
		REQUIRE(grid.size() == r);
		REQUIRE(grid[0].size() == c);
		//inital live and dead cells
		REQUIRE(board.get_total_cells(LIVE) == 4);
		REQUIRE(board.get_total_cells(DEAD) == 45);

		//turn a dead cell to live and test
		board.set_cell_state(3,5,LIVE);
		REQUIRE(board.get_total_cells(LIVE) == 5);
		REQUIRE(board.get_total_cells(DEAD) == 44);

		//turn a live cell to live and test
		board.set_cell_state(3,5,LIVE);
		REQUIRE(board.get_total_cells(LIVE) == 5);
		REQUIRE(board.get_total_cells(DEAD) == 44);

		//turn a live cell to dead and test
		board.set_cell_state(3,5,DEAD);
		REQUIRE(board.get_total_cells(LIVE) == 4);
		REQUIRE(board.get_total_cells(DEAD) == 45);

		//turn a dead cell to dead and test
		board.set_cell_state(3,5,DEAD);
		REQUIRE(board.get_total_cells(LIVE) == 4);
		REQUIRE(board.get_total_cells(DEAD) == 45);
	}

		SECTION("Testing: set_cell_state() exception"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//test all 3 invalid parameters with negative numbers/ invalid input and out of range
		REQUIRE_THROWS_AS(board.set_cell_state(-1,5,LIVE),invalid_argument);
		REQUIRE_THROWS_AS(board.set_cell_state(1,-5,LIVE),invalid_argument );
		REQUIRE_THROWS_AS(board.set_cell_state(7,5,LIVE),invalid_argument);
		REQUIRE_THROWS_AS(board.set_cell_state(1,7,LIVE),invalid_argument);

	}

		SECTION("Testing: get_cell_state()"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//test initial values and after changing state
		REQUIRE(board.get_cell_state(0,0) == DEAD);
		REQUIRE(board.get_cell_state(1,2) == DEAD);
		REQUIRE(board.get_cell_state(2,2) == LIVE);
		board.set_cell_state(0,0,LIVE);
		REQUIRE(board.get_cell_state(0,0) == LIVE);

		
	}
	SECTION("Testing: get_cell_state() exception"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//test out of range and negative input exception
		REQUIRE_THROWS_AS(board.get_cell_state(-1,5),invalid_argument);
		REQUIRE_THROWS_AS(board.get_cell_state(1,-5),invalid_argument);
		REQUIRE_THROWS_AS(board.get_cell_state(7,5),invalid_argument);
		REQUIRE_THROWS_AS(board.get_cell_state(1,7),invalid_argument);
		
	}
	SECTION("Test get_gameBoard())"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//test tha get_gameBoard() returns the whole grid with correct values
		REQUIRE(grid[2][2].s == LIVE);
		REQUIRE(grid[0][0].s == DEAD);
	}

	SECTION("Testing: get_total_state()"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//see if the intial configeration is correct
		REQUIRE(board.get_total_cells(LIVE) == 4);
		REQUIRE(board.get_total_cells(DEAD) == 45);

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				board.set_cell_state(i,j,DEAD);
			}
		}

		//test that the final configeration is correct after turning all live cells dead
		REQUIRE(board.get_total_cells(LIVE) == 0);
		REQUIRE(board.get_total_cells(DEAD) == 49);
	}

	SECTION("Testing: get_neighhour_states()"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//test to see if neighbours total is correct
		REQUIRE(board.get_total_cells(LIVE) == 4);
		REQUIRE(board.get_total_cells(DEAD) == 45);
		REQUIRE(board.get_neighbour_state(0,0,LIVE)==0);
		REQUIRE(board.get_neighbour_state(0,0,DEAD)==3);
		REQUIRE(board.get_neighbour_state(2,2,LIVE)==1);
		REQUIRE(board.get_neighbour_state(2,2,DEAD)==7);
		REQUIRE(board.get_neighbour_state(4,3,LIVE)==3);
		REQUIRE(board.get_neighbour_state(4,3,DEAD)==5);

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				board.set_cell_state(i,j,DEAD);				
			}
		}
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				REQUIRE(board.get_neighbour_state(i,j,LIVE)==0);			
			}
		}

		//test to see if neighbours total is correct after turning each cell off (for verification)
		REQUIRE(board.get_total_cells(LIVE) == 0);
		REQUIRE(board.get_total_cells(DEAD) == 49);
	}

	SECTION("Testing: iterate()"){
		Display display("trial.txt", "output.txt");
		vector<vector<CellT> > grid;
		grid = display.read_game_state();
		int r = grid.size();
		int c = grid[0].size();
		GameBoardT board(r,c, grid);
		grid = board.get_gameBoard();

		//inital live and dead cells
		REQUIRE(board.get_cell_state(2,2) == LIVE);
		REQUIRE(board.get_cell_state(3,2) == LIVE);
		REQUIRE(board.get_cell_state(4,2) == LIVE);
		REQUIRE(board.get_cell_state(5,2) == LIVE);

		//iterate over one generation
		board.iteration(1);

		//test configeration again
		REQUIRE(board.get_cell_state(3,1) == LIVE);
		REQUIRE(board.get_cell_state(3,3) == LIVE);
		REQUIRE(board.get_cell_state(4,1) == LIVE);
		REQUIRE(board.get_cell_state(4,3) == LIVE);
		REQUIRE(board.get_cell_state(2,2) == DEAD);
		REQUIRE(board.get_cell_state(3,2) == DEAD);
		REQUIRE(board.get_cell_state(4,2) == DEAD);
		REQUIRE(board.get_cell_state(5,2) == DEAD);

		//iterate over another generation
		board.iteration(1);
		REQUIRE(board.get_cell_state(3,1) == DEAD);
		REQUIRE(board.get_cell_state(3,3) == DEAD);
		REQUIRE(board.get_cell_state(4,1) == DEAD);
		REQUIRE(board.get_cell_state(4,3) == DEAD);

		// extra test so see if the values don't change for large values 
		REQUIRE(board.get_total_cells(LIVE) == 0);
		REQUIRE(board.get_total_cells(DEAD) == 49);
		board.iteration(15);
		REQUIRE(board.get_total_cells(LIVE) == 0);
		REQUIRE(board.get_total_cells(DEAD) == 49);
	}
}

