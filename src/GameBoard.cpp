/**
 * \file GameBoard.cpp
 * \brief The class file for GameBoard
 * \author Harshil Modi MacID: modih1
 * \date April 3rd, 2019
*/

#include <iostream>
#include "../include/CellType.h"
#include "../include/GameBoard.h"
#include  <vector>

using namespace std;

GameBoardT::GameBoardT(int row, int col, vector<vector<CellT> > grid){
	this->number_rows = row;
	this->number_columns = col;
	this -> Grid = grid;
}

void GameBoardT::set_cell_state(int row, int col, StateT state){
	if(valid_cell_state(row, col, state)){
		this->Grid[row][col].s = state;
	}
	else{
		throw std::invalid_argument("invalid_argument");
	}
}

StateT GameBoardT::get_cell_state(int row, int col){
	if(valid_cell(row, col)){
		return this->Grid[row][col].s;
	}
	else{
		throw std::invalid_argument("invalid_argument");
	}
}

vector<vector<CellT> > GameBoardT::get_gameBoard(){
	return this->Grid;
}

int GameBoardT::get_total_cells(StateT state){
	int count = 0;
	for (int i = 0; i < this->number_rows; i ++){
		for (int j = 0; j < this->number_columns; j ++){
			if(this->Grid[i][j].s == state){
				count++;
			}
		}
	}
	return count;
}

int GameBoardT::get_neighbour_state(int row, int col, StateT state){
	int count = 0;
	if(valid_cell_state(row, col, state)){
		for(int i = -1; i < 2; i++){
			for (int j = -1; j < 2; j++){
				if (!(i ==0 && j == 0) && valid_cell(row+i,col+j)){
					if (this->Grid[row+i][col+j].s == state){
						count++;
					}
				}
			}
		}
	}
	return count;
}

void GameBoardT::iteration(int n){

	for(int i = 0; i < n; i++){
		vector<CellT> change;
		for(int j = 0; j < this->number_rows; j++){
			for(int z = 0; z < this->number_columns; z++){
				CellT cell = this->Grid[j][z];
				if(cell.s == DEAD){
					if(get_neighbour_state(j,z,LIVE) == 3){
						change.push_back(cell);
					}
				}
				if(cell.s == LIVE){
					if(get_neighbour_state(j,z,DEAD) >=4 || get_neighbour_state(j,z,DEAD) <=1){
						change.push_back(cell);
					}
				}
			}
		}
		for(unsigned int k =0; k < change.size(); k++){
			if(change[k].s == DEAD)
				set_cell_state(change[k].row,change[k].col,LIVE);
			else
				set_cell_state(change[k].row,change[k].col,DEAD);
		}
	}

}

/* Private Methods */
bool GameBoardT::valid_cell(int row, int col){
	return (valid_row(row) && valid_column(col));
}
bool GameBoardT::valid_cell_state(int row, int col, StateT state){

	return (valid_row(row) && valid_column(col) && valid_state(state));

}

bool GameBoardT::valid_row(int row){
	return 0<= row && row < this->number_rows;
}

bool GameBoardT::valid_column(int col){
	return 0<= col && col < this->number_columns;
}

bool GameBoardT::valid_state(StateT state){
	return (state == LIVE || state == DEAD);
}