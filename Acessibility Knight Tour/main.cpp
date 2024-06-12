#include <iostream>
#include <cstdlib>

#include "chessboard.h"
#include "knight.h"

#define TAM 8

using namespace std;

int main()
{	
	int min = 65;
	int max = -1;

	cout << "\nPrograma para simular passeio do cavalo "
			 << " \nno tabuleiro de xadrez 8 x 8 "
			 << "usando a heuristica da acessibilidade.";
			 
	cout << "\n\n";
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{				
			cout << "\n\nPosicao inicial = (" << i << "," << j << ")";
			knight cavalo(i,j);
			int n = cavalo.knight_tour();
			
			if (n < min)
			{
				min = n;									
				cout << "\n\n(i,j) = (" << i << "," << j << ")";
				cout << "\nmax = " << max;
				cout << "\nmin = " << min;
				system("PAUSE");					
			}else if (n > max)
			{
				max = n;
					
				cout << "\n\n(i,j) = (" << i << "," << j << ")";
				cout << "\nmax = " << max;
				cout << "\nmin = " << min;				
				
				system("PAUSE");					
			}							
		}		
	}
	
	system ("PAUSE");
  return 0;
}
