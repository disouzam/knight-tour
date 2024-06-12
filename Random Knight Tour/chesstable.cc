#include "chesstable.h"

chesstable::chesstable()
{
	cleartable();
}

chesstable::~chesstable()
{
	//Não executa nenhuma ação.
}

void chesstable::fillposition(coordinate& position, int i)
{
	if (!isoccupied(position.gethor(), position.getver()))
	{
		int p_h = position.gethor();
		int p_v = position.getver();
		table[p_h][p_v] = i;
		occupiedpositions++;
	}else
	{
		cout << "\nPosicao ocupada." << endl;
	}
}

bool chesstable::isoccupied(int h, int v)
{
	if ((h >= 0 && h < TAM) && (v >= 0 && v < TAM))
	{
		if (table[h][v] == NULO)
		{
			return false;
		}else
		{
			return true;
		}
	}else
	{
		cout << "\nErro: Posicao invalida.\n";
		return true;
	}
	
}

void chesstable::print()
{	
	const int WIDTH = 6;
	cout << endl << endl;	
	cout << setw(WIDTH) << setiosflags(ios::left) << "";
	textcolor(YELLOW);
	for (int i = 0; i < TAM; i++)
	{
		cout << setw(WIDTH) << setiosflags(ios::left) << i;
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < TAM; i++)
	{
		textcolor(YELLOW);
		cout << setw(WIDTH) << setiosflags(ios::left) << i;
		textcolor(WHITE);
		
		for (int j = 0; j < TAM; j++)
		{
			cout << setw(WIDTH) << setiosflags(ios::left);
			
			if (table[i][j] == NULO)
			{
				cout << "-";
			}else
			{
				cout << table[i][j];
			}
		}
		cout << endl << endl;
	}
}

void chesstable::cleartable()
{
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			table[i][j] = NULO;
		}
	}	
	full = false;
	occupiedpositions = 0;
}

bool chesstable::isfull()
{
	return occupiedpositions == 64;
}

int chesstable::empty_positions()
{	
	return (64 - occupiedpositions);
}


void chesstable::save_table(char fname[],char message[])
{
	ofstream CLOSEDTOUR (fname, ios::app);
	const int WIDTH = 6;		
	
	CLOSEDTOUR << message << endl << endl;
	
	CLOSEDTOUR << setw(WIDTH) << setiosflags(ios::left) << "";
	
	for (int i = 0; i < TAM; i++)
	{
		CLOSEDTOUR << setw(WIDTH) << setiosflags(ios::left) << i;
	}
	
	CLOSEDTOUR << endl << endl;
	
	for (int i = 0; i < TAM; i++)
	{		
		CLOSEDTOUR << setw(WIDTH) << setiosflags(ios::left) << i;		
		
		for (int j = 0; j < TAM; j++)
		{
			CLOSEDTOUR << setw(WIDTH) << setiosflags(ios::left);
			
			if (table[i][j] == NULO)
			{
				CLOSEDTOUR << "-";
			}else
			{
				CLOSEDTOUR << table[i][j];
			}
		}
		
		CLOSEDTOUR << endl;;
	}
	CLOSEDTOUR << endl << endl << endl << endl;
	
	CLOSEDTOUR.close();
}
