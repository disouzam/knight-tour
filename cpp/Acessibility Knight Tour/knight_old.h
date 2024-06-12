#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "C:\Dev-Cpp\include\conio2.h"

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
		
		int acessibility[8][8];
		
		void incrementvisited();
		
		void setvisitedcells(int i);
		
		void updateacessibility();
		
		void initializeacessibility();
		
		void print_acessibility() const;
		
		
	public:
		knight(const int h, const int v);
		
		~knight();
		
		coordinate getposition() const;
		
		int getvisitedcells() const;
		
		bool getpossibleposition(int i, coordinate *position_) const;
		
		int numberofmoves() const;
		
		void possiblemovements_array(int M[], int n) const;
		
		coordinate getmovements(int i) const;
		
		bool setposition(int h, int v);				
		
		void setpossiblepositions();		
		
		int knight_tour(bool step, bool print);
		
		void print_table() const;
		
};

#endif
