#include "chessboard.h"

chessboard::chessboard()
{
	clearboard();
}

chessboard::~chessboard()
{
	//Não executa nenhuma ação.
}

bool chessboard::fillposition(const coordinate &position, const int i)
{
	if (!isoccupied(position.gethor(), position.getver()))
	{
		int p_h = position.gethor();
		int p_v = position.getver();
		board[p_h][p_v] = i;
		occupiedpositions++;
		return true;
	}else
	{		
		return false;
	}
}

bool chessboard::isoccupied(const int h, const int v) const
{
	if ((h >= 0 && h < TAM) && (v >= 0 && v < TAM))
	{
		if (board[h][v] == NULO)
		{
			return false;
		}else
		{
			return true;
		}
	}else
	{		
		return true;
	}	
}

void chessboard::print() const
{	
	const int WIDTH = 6;
	
	int max = 64 - empty_positions();
	
	textcolor(WHITE);
	
	cout << "\n\nChess board:";
	
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
		textcolor(LIGHTBLUE);
		
		for (int j = 0; j < TAM; j++)
		{
			cout << setw(WIDTH) << setiosflags(ios::left);
			
			if (board[i][j] == NULO)
			{
				cout << "-";
			}else
			{
				if (board[i][j] == max)
				{
					textcolor(WHITE);
					cout << board[i][j];
					textcolor(LIGHTBLUE);
				}
				else
				{
					textcolor(LIGHTBLUE);
					cout << board[i][j];
				}
					
			}
		}
		cout << endl << endl;
	}
}

void chessboard::clearboard()
{
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			board[i][j] = NULO;
		}
	}		
	occupiedpositions = 0;
}

bool chessboard::isfull() const
{
	return (occupiedpositions == 64);
}

int chessboard::empty_positions() const
{	
	return (64 - occupiedpositions);
}
