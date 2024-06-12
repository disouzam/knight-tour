#include "knight.h"

#define BOARD_SIZE 8
#define NULO_A 0

// Construtor. Argumentos: posição inicial do cavalo no tabuleiro.
knight::knight(const int h, const int v)
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
	
	visited = 1;
	initializeacessibility();
	coordinate p;	
	if (!board.isoccupied(h,v))
	{
		p.set(h,v);
	}else
	{
		p.set(0,0);
	}	
	
	set_position(p);				
	visited = 1;
	updateacessibility();
	visited = 2;
}

// Destrutor. Não executa nenhuma ação. Não é criada memória dinâmica.
knight::~knight()
{
	
}

// Inicializa a matriz de acessibilidades para o tabuleiro vazio.
void knight::initializeacessibility()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			acessibility[i][j] = 0;
		}
	}
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{			
			int count = 0;
			
			for (int k = 0; k < BOARD_SIZE; k++)
			{
				int new_h = i + movements[k].gethor();
				int new_v = j + movements[k].getver();
				
				if ((new_h >= 0 && new_h < BOARD_SIZE)  
					  && (new_v >= 0 && new_v < BOARD_SIZE))
				{
					count++;
				}				
			}			
			acessibility[i][j] = count;
		}
	}
}

// Determina as posições possíveis para a posição atual do cavalo.
void knight::set_possible()
{
	int iter = 0;
	int min_acess = 9;
	
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		int new_h = position.gethor() + movements[i].gethor();
		int new_v = position.getver() + movements[i].getver();
				
		if (!board.isoccupied(new_h,new_v))		
		{
			index_of_moves[iter] = i;
			iter++;
			
			coordinate p;
			p.set(new_h,new_v);
			
			possible[i].position = p;
			possible[i].acess_number = acessibility[new_h][new_v];
			
			if (acessibility[new_h][new_v] < min_acess)
			{
				min_acess = acessibility[new_h][new_v];
				index_of_min_acess = i;
			}
			
		}
	}
	number_of_moves = iter;	
}

// Retorna o número de movimentos possíveis para a posição atual.
int knight::number_moves()
{
	return number_of_moves;
}

// Especifica uma nova posição para o cavalo.
// Pré-condição: a posição deve estar vazia.
void knight::set_position(const coordinate& new_p)
{
	updateacessibility();
	position.set(new_p.gethor(), new_p.getver());
	board.fillposition(new_p,visited);
	acessibility[position.gethor()][position.getver()] = NULO_A;
	visited++;		
	set_possible();
}

// Atualiza a matriz de acessibilidades para o tabuleiro no estado atual.
void knight::updateacessibility()
{
		if (visited > 1)
		{
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				int new_h = position.gethor() + movements[i].gethor();
				int new_v = position.getver() + movements[i].getver();
				
				if (!board.isoccupied(new_h, new_v))
				{
					acessibility[new_h][new_v]--;
				}		
			}	
		}
		else
		{
			acessibility[position.gethor()][position.getver()] = NULO_A;	
		}
		
}

// Imprime matriz de acessibilidades.
void knight::print_acessibility() const
{
	const int WIDTH = 6;
	textcolor(WHITE);
	cout << "\n\nMatriz de acessibilidades:";
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
			
			if (acessibility[i][j] == 0)
			{
				cout << "-";
			}else
			{
				cout << acessibility[i][j];
			}
		}
		cout << endl << endl;
	}
}

int knight::knight_tour()
{	
	while (number_moves() != 0)
	{		
		board.print();
		print_acessibility();
		system("PAUSE");
		set_position(possible[index_of_min_acess].position);		
	}
	board.print();
	print_acessibility();
	system("PAUSE");
	return board.empty_positions();
}
