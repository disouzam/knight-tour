#include "knight.h"

knight::knight(int h, int v)
{
	//Definição dos valores de movements.
	movements[0].set(+2, -1);
	movements[1].set(+1, -2);
	movements[2].set(-1, -2);
	movements[3].set(-2, -1);
	movements[4].set(-2, +1);
	movements[5].set(-1, +2);
	movements[6].set(+1, +2);
	movements[7].set(+2, +1);
		
	if ( (h >= 0 && h < TABULEIRO_SIZE) && (v >= 0 && v < TABULEIRO_SIZE))
	{
		position.set(h, v);		
	}else
	{
		position.set(0, 0);
	}
	visitedcells = 1;
	table.fillposition(position, visitedcells);		
	setpossiblepositions();
}

knight::~knight()
{
	//Não executa nenhuma ação.
}

coordinate knight::getposition()
{
	return position;
}

int knight::getvisitedcells()
{
	return visitedcells;
}

bool knight::getpossibleposition(int i, coordinate *position_)
{	
	if (i >= 0 && i <= TABULEIRO_SIZE - 1)
	{
		if (!table.isoccupied(possibleposition[i].gethor(),possibleposition[i].getver()))
		{
			int h = possibleposition[i].gethor();
			int v = possibleposition[i].getver();

			if ((h != NULO) && (v != NULO))
			{
				position_->set(h, v);
				return true;
			}
		}
	}else
	{
		cout << "\nErro. Posicao nao existente."
				 << "\nPosicoes permitidas entre 1 e " << TABULEIRO_SIZE - 1 << "\n";		
	}
	return false;
}

int knight::numberofmoves()
{
	int count = 0;
	for (int i = 0; i < TABULEIRO_SIZE; i++)
	{
		if (possiblemovements[i] != NULO)
		{
			count++;
		}
	}
	return count;
}

void knight::possiblemovements_array(int M[], int n)
{
	if (n == TABULEIRO_SIZE)
	{	
		for (int i = 0; i < n; i++)
		{
			M[i] = possiblemovements[i];
		}
	}else
	{
		cout << "\nO parametro n deve ser igual a " << TABULEIRO_SIZE << endl;
	}
}

coordinate knight::getmovements(int i)
{
	if (i >=0 && i < TABULEIRO_SIZE)
	{
		return movements[i];
	}else
	{
		cout << "\nErro. Posicao nao existente."
				 << "\nPosicoes permitidas entre 1 e " << TABULEIRO_SIZE - 1 << "\n";
		return movements[0];
	}
}

bool knight::setposition(int h, int v)
{	
	
	if ((h >= 0 && h < TABULEIRO_SIZE) && (v >= 0 && v < TABULEIRO_SIZE ))
	{
		if (!table.isoccupied(h,v))
		{
			position.set(h, v);
			incrementvisited();
			setpossiblepositions();
			table.fillposition(position, visitedcells);
			return true;
		}else		
		{
			return false;
		}
		
	}else
	{
		cout << "\nPosicao nao permitida. Excede tamanho do tabuleiro.\n";
		return false;
	}	
}

void knight::setvisitedcells(int i)
{
	visitedcells = i;	
}

void knight::incrementvisited()
{
	visitedcells++;
}

void knight::setpossiblepositions()
{
	int p_h = position.gethor();
	int p_v = position.getver();
	
	for(int i = 0; i < TABULEIRO_SIZE; i++)
	{
		possiblemovements[i] = NULO;
	}
	
	int j = 0;
	
	for(int i = 0; i < TABULEIRO_SIZE; i++)
	{
		int delta_h = movements[i].gethor();
		int delta_v = movements[i].getver();
		int new_h = p_h + delta_h;
		int new_v = p_v + delta_v;
		
		if ((new_h >= 0 && new_h < TABULEIRO_SIZE)  
				&& ((new_v >= 0 && new_v < TABULEIRO_SIZE)
						&& (!table.isoccupied(new_h, new_v))))
		{
			possibleposition[i].set(new_h, new_v);
			possiblemovements[j] = i;
			j++;
		}else
		{
			possibleposition[i].set(NULO, NULO);
		}		
	}	
}

int knight::knight_tour(bool step, bool print)
{			
	if (step)
	{
		table.print();
		cout << "\nNumber of moves = " << numberofmoves() << endl;
		cout << "\nNumber of empty positions = " << table.empty_positions() << endl << endl;
		system("PAUSE");
	}
	
	int n = numberofmoves();
	
	while (n != 0)
	{				
		coordinate cell;						
		int M[TABULEIRO_SIZE];
		possiblemovements_array(M, TABULEIRO_SIZE);
		
		if (VDEBUG_)
		{
			for (int i = 0; i < TABULEIRO_SIZE; i++)
			{
				cout << "\nM[" << i << "] = " << M[i];
			}
		}
		
		int k = rand() % n;
		
		if (VDEBUG_)
		{
			cout << "\nn = " << n;
			cout << "\nk = " << k;
		}

		k = M[k];
		
		if (VDEBUG_)
		{			
			cout << "\nk = " << k;
			system("PAUSE");
		}
		
		getpossibleposition(k, &cell);			
		setposition(cell.gethor(), cell.getver());
		
		if (step)
		{
			table.print();
			cout << "\nNumber of moves = " << numberofmoves() << endl;
			cout << "\nNumber of empty positions = " << table.empty_positions() << endl << endl;
			system("PAUSE");
		}
		
		n = numberofmoves();				
	}
	
	if (print)
	{
		table.print();
		cout << "\nNumber of moves = " << numberofmoves() << endl;
		cout << "\nNumber of empty positions = " << table.empty_positions() << endl << endl;
		system("PAUSE");
	}
	
	if (table.empty_positions() == 0)
	{
		table.print();
		cout << "\n\n=============Closed tour reached==========.";
		cout << "\nNumber of moves = " << numberofmoves() << endl;
		cout << "\nNumber of empty positions = " << table.empty_positions() << endl << endl;
		save_table();		
	}
	
	return table.empty_positions();
	
}

void knight::print_table()
{
	table.print();
}

void knight::save_table()
{
	char fname[] = "knight tour closed tours.txt";
	char message[] = "Closed tour of knight.";
	table.save_table(fname, message);
}
