/**
 * \file Display.h
 * \brief The header file for Display
 * \author Harshil Modi MacID: modih1
 * \date April 3rd, 2019
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "GameBoard.h"
#include "CellType.h"

/**
This class is used to reading data from textfile, write to textfile, and write to standard output
*/
class Display {
	private:
		//The path to input textfile	
		string input_path;

		//The path to output textfile
		string output_path;

	public:

		/**
		 * \brief Initializes the Display class
		 * \details Takes in the path to read and write file and initalizes a Display class
		 * \param input_path the path need to access the input.txt file
		 * \param output_path the path need to access the output.txt file
		 * \return None
		*/
		Display(string input_path, string ouput_path);

		/**
		 * \brief writes games state to output_path
		 * \details takes the grid as input and writes to ouput textfile the current state of game
		 * \param Grid the current gameboard for the game
		 * \return None
		*/
		void write_game_state(vector<std::vector<CellT> > Grid);

		/**
		 * \brief displays games state
		 * \details takes the grid as input and displays the current state of game to standard output
		 * \param Grid the current gameboard for the game
		 * \return None
		*/
		void display_game_state(vector<std::vector<CellT> > Grid);

		/**
		 * \brief reads games state from textfile input_path
		 * \details reads the input textfile to determine current state of game
		 * \return Grid which repersents the current state of game
		*/
		vector<vector<CellT> > read_game_state();
};
#endif
