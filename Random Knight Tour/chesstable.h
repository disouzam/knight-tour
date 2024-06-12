#ifndef CHESSTABLE_H
#define CHESSTABLE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "C:\Dev-Cpp\include\conio2.h"
#include "coordinate.h"

#define TAM 8
#define NULO -1

struct chesstable
{
	private:
		int table[8][8];
		int occupiedpositions;
		bool full;
		
	public:
		chesstable();
		~chesstable();
		void fillposition (coordinate& position, int i);
		bool isoccupied(int h, int v);
		void print();
		void cleartable();
		bool isfull();
		int empty_positions();
		void save_table(char fname[], char message[]);
};

#endif
