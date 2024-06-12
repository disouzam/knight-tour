#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <cstdlib>
#include "C:\Dev-Cpp\include\conio2.h"

#include "coordinate.h"
#include "chessboard.h"

struct knight
{
	private:
		coordinate position; // Especifica a posi��o atual do cavalo no tabuleiro.
		int visited; // Especifica a quantidade de posi�oes visitadas no tabuleiro.	
		
		chessboard board; // Cria um tabuleiro para ser percorrido pelo cavalo. 
		int acessibility[8][8]; // Especifica a acessibilidade de cada posi��o do tabuleiro.
		
		struct board_pos
		{
			coordinate position;			
			int acess_number;
		};
		
		board_pos possible[8];
		
		int index_of_min_acess;
		
		// Indica o n�mero de movimentos poss�veis para a posi��o atual do cavalo e estado atual do tabuleiro.
		int number_of_moves; 
		
		// Utiliza as posi��es de 0 a number_of_moves - 1 para 
		//indicar as posi��es poss�veis no array possible do tipo board_pos
		int index_of_moves[8];
		
		
		// Especifica os movimentos permitidos para o cavalo. 
		// N�o significa que todos s�o poss�veis.
		// Algumas posi��es podem cair fora do tabuleiro.
		// Esse vetor especifica o n�mero de casas a andar em um dado movimento.
		coordinate movements[8]; 
		
		// Inicializa a matriz de acessibilidades para o tabuleiro vazio.
		void initializeacessibility();
		
		// Atualiza a matriz de acessibilidades para o tabuleiro no estado atual.
		void updateacessibility();
		
		// Imprime matriz de acessibilidades.
		void print_acessibility() const;
		
		// Determina as posi��es poss�veis para a posi��o atual do cavalo.
		void set_possible();
		
	public:
		// Construtor. Argumentos: posi��o inicial do cavalo no tabuleiro.
		knight(const int h, const int v);
		
		// Destrutor. N�o executa nenhuma a��o. N�o � criada mem�ria din�mica.
		~knight();
		
		// Retorna o n�mero de movimentos poss�veis para a posi��o atual.
		int number_moves();
		
		// Especifica uma nova posi��o para o cavalo.
		// Pr�-condi��o: a posi��o deve estar vazia.
		void set_position(const coordinate& new_p);
		
		int knight_tour();
};

#endif
