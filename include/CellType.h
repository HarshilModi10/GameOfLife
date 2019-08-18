/**
 * \file CellType.h
 * \brief The header file for Celltypes
 * \date April 3rd, 2019
*/

#ifndef CELLTYPE_H
#define CELLTYPE_H

//NumT is a Natural number
typedef unsigned short int NumT;

//brief Enumerated type representing the 2 states of a cell: Live or Dead
enum StateT {LIVE, DEAD};

// A Cell Structure which contains the coodinate and State of the cell
struct CellT{	
	NumT row;
	NumT col;
	StateT s;
};


#endif
