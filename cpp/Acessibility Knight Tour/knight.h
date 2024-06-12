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
		coordinate position; // Especifica a posição atual do cavalo no tabuleiro.
		int visited; // Especifica a quantidade de posiçoes visitadas no tabuleiro.	
		
		chessboard board; // Cria um tabuleiro para ser percorrido pelo cavalo. 
		int acessibility[8][8]; // Especifica a acessibilidade de cada posição do tabuleiro.
		
		struct board_pos
		{
			coordinate position;			
			int acess_number;
		};
		
		board_pos possible[8];
		
		int index_of_min_acess;
		
		// Indica o número de movimentos possíveis para a posição atual do cavalo e estado atual do tabuleiro.
		int number_of_moves; 
		
		// Utiliza as posições de 0 a number_of_moves - 1 para 
		//indicar as posições possíveis no array possible do tipo board_pos
		int index_of_moves[8];
		
		
		// Especifica os movimentos permitidos para o cavalo. 
		// Não significa que todos são possíveis.
		// Algumas posições podem cair fora do tabuleiro.
		// Esse vetor especifica o número de casas a andar em um dado movimento.
		coordinate movements[8]; 
		
		// Inicializa a matriz de acessibilidades para o tabuleiro vazio.
		void initializeacessibility();
		
		// Atualiza a matriz de acessibilidades para o tabuleiro no estado atual.
		void updateacessibility();
		
		// Imprime matriz de acessibilidades.
		void print_acessibility() const;
		
		// Determina as posições possíveis para a posição atual do cavalo.
		void set_possible();
		
	public:
		// Construtor. Argumentos: posição inicial do cavalo no tabuleiro.
		knight(const int h, const int v);
		
		// Destrutor. Não executa nenhuma ação. Não é criada memória dinâmica.
		~knight();
		
		// Retorna o número de movimentos possíveis para a posição atual.
		int number_moves();
		
		// Especifica uma nova posição para o cavalo.
		// Pré-condição: a posição deve estar vazia.
		void set_position(const coordinate& new_p);
		
		int knight_tour();
};

#endif
