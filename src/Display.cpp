/**
 * \file Display.cpp
 * \brief The class file for Display
 * \date April 3rd, 2019
*/

#include <iostream>
#include "../include/CellType.h"
#include "../include/GameBoard.h"
#include "../include/Display.h"
#include  <vector>
#include<string.h>
#include <fstream>
using namespace std;

Display::Display(string input_path, string output_path){
	this->input_path = input_path;
	this->output_path = output_path;
}

void Display::write_game_state(vector<std::vector<CellT> > Grid){

	ofstream myfile;
  	myfile.open (this->output_path.c_str());

	for(unsigned int j = 0; j < Grid.size(); j++){
			for(unsigned int z = 0; z < Grid[0].size(); z++){
				CellT cell = Grid[j][z];
				if (cell.s == DEAD){
					myfile << "O";
				}
				else{
					myfile <<"X";
				}
			}
			myfile << "\n";
		}

  	myfile.close();

}
void Display::display_game_state(vector<std::vector<CellT> > Grid){

	for(unsigned int j = 0; j < Grid.size(); j++){
			for(unsigned int z = 0; z < Grid[0].size(); z++){
				CellT cell = Grid[j][z];
				if (cell.s == DEAD){
					cout << "O ";
				}
				else{
					cout <<"X ";
				}
			}
			cout<<endl;
			cout<<endl;
		}
}

vector<vector<CellT> > Display::read_game_state(){
	string line;
	int num_row = 0;

	ifstream file(this->input_path.c_str());
    while (getline(file, line))
        num_row++;

	vector<std::vector<CellT> > Grid(num_row);
  	ifstream myfile (this->input_path.c_str());
  	short unsigned int j = 0;
  	if (myfile.is_open()) {
    	while ( getline (myfile,line)){
    		for(short unsigned int i = 0; i < line.length(); i++){    			
    			string test = "O";
    			if(line[i] == test[0]){
    				
    				CellT cell = {j,i,DEAD};
    				Grid[j].push_back(cell);
    				
    			}
    			else{
    				CellT cell = {j,i,LIVE};
    				Grid[j].push_back(cell);
    			}
    		}
    	j++;
    	}
  	}
	else{ cout << "Unable to open file"; }
	myfile.close();

	return Grid;
}