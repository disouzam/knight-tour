#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "coordinate.h"
#include "chesstable.h"

#define NULO -1
#define TABULEIRO_SIZE 8
#define VDEBUG_ 0

struct knight 
{
	private:
		coordinate position;
		int visitedcells;
		coordinate movements[TABULEIRO_SIZE]; // Constante
		coordinate possibleposition[TABULEIRO_SIZE];
		int possiblemovements[TABULEIRO_SIZE];						
		
		chesstable table;		
		
		void incrementvisited();
		void setvisitedcells(int i);
		
	public:
		knight(int h, int v);
		~knight();
		coordinate getposition();
		int getvisitedcells();
		bool getpossibleposition(int i, coordinate *position_);
		int numberofmoves();
		void possiblemovements_array(int M[], int n);
		coordinate getmovements(int i);
		bool setposition(int h, int v);				
		void setpossiblepositions();		
		int knight_tour(bool step, bool print);
		void print_table();
		void save_table();
};

#endif
