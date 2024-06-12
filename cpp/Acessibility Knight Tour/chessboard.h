#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <iomanip>

#include "C:\Dev-Cpp\include\conio2.h"
#include "coordinate.h"

#define TAM 8
#define NULO -1

struct chessboard
{
	private:
		int board[8][8];		
		int occupiedpositions;		
		
	public:
		chessboard(); // Construtor
		~chessboard(); // Destrutor
		bool fillposition (const coordinate& position, const int i);
		bool isoccupied(const int h, const int v) const;
		void print() const;
		void clearboard();
		bool isfull() const;
		int empty_positions() const;		
};

#endif
