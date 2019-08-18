/**
 * \file GameBoard.h
 * \brief The header file for GameBoard
 * \author Harshil Modi MacID: modih1
 * \date April 3rd, 2019
*/
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <iostream>
#include "CellType.h"
using namespace std;



/**
This class is used to implement the logic of the game of life
*/
class GameBoardT {
	private:
		//A 2D vector representing the playing feild of game of life
		std::vector<std::vector<CellT> > Grid;
		//The number of rows in Grid
		int number_rows;
		//The number of Columns in Grid
		int number_columns;

		// Private methods used in the implementation of GameBoardT
		bool valid_cell(int row, int col);
		bool valid_cell_state(int row, int col, StateT state);
		bool valid_row(int row);
		bool valid_column(int col);
		bool valid_state(StateT state);
	public:

		/**
		 * \brief Initializes the GameBoardT class
		 * \details Takes in the number of rows, columns, and intial Grid imported from input file
		   \and intializes the class
		 * \param row the number of rows in Grid
		 * \param col the number of columns in Grid
		 * \return None
		*/
		GameBoardT(int row, int col, vector<vector<CellT> > grid);

		/**
		 * \brief sets the state of the cell
		 * \details Takes the row, column and state as input and set the Cell
		 * \param row the row number in Grid
		 * \param col the col number in Grid
		 * \param state the state to set the current cell too
		 * \return None
		*/
		void set_cell_state(int row, int col, StateT state);

		/**
		 * \brief get the state of the cell
		 * \details Takes the row and column number as input and retrieves the current state of cell
		 * \param row the row number in Grid
		 * \param col the col number in Grid
		 * \return stateT the current state of cell
		*/
		StateT get_cell_state(int row, int col);

		/**
		 * \brief get gameBoard
		 * \details this function returns the state of current GameBoard
		 * \return the 2D Grid of current game
		*/
		vector<vector<CellT> > get_gameBoard();

		/**
		 * \brief counts total cells of StateT state
		 * \details takes state of type StateT as input and counts total number of cells of type state
		 * \return the number of cells with StateT state
		*/
		int get_total_cells(StateT state);

		/**
		 * \brief gets the number of neignbours with stateT state
		 * \details Takes the row, column and state as input and counts the number of neignbours with StateT state
		 * \param row the row number in Grid
		 * \param col the col number in Grid
		 * \param state the state yo count neighbour cells
		 * \return number of neighbours with StateT state
		*/
		int get_neighbour_state(int row, int col, StateT state);

		/**
		 * \brief iterates over the game
		 * \details takes n as input and interates over the game n times
		 * \param n the number of times to interate the game
		 * \return none
		*/
		void iteration(int n);
};
#endif
