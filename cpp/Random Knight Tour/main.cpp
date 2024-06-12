#include <iostream>
#include <cstdlib>
#include <fstream>

#include "chesstable.h"
#include "knight.h"

#define TAM 8

using namespace std;

int main()
{			
	srand(time(0));
	
	int min = 65;
	int max = -1;
	long int DIST[65];
	
	ofstream RESULTADO ("Distribuicao de frequencias.txt", ios::out);
	
	for (int i = 0; i < 65; i++)
	{
		DIST[i] = 0;
	}
	int FREQ_POS[8][8];
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{			
			FREQ_POS[i][j] = 0;
		}
	}
	cout << "\nPrograma para simular passeio do cavalo "
			 << " \nno tabuleiro de xadrez 8 x 8.";
			 
	cout << "\n\nDigite o numero de tentativas para o passeio do cavalo: ";
	
	unsigned long int REPETICAO;
	cin >> REPETICAO;
	
	cout << "\n\n";
	int percentual = 0;
	
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{			
			for (unsigned long int count = 1; count <= REPETICAO/64; count++)
			{				
				knight cavalo(i,j);				
				int n = cavalo.knight_tour(false,false);
				
				DIST[n]++;
				
				if (n == 0)
				{
					FREQ_POS[i][j]++;
				}
				
				if (n < min)
				{
					min = n;
					
					system ("CLS");
					cout << endl;
					for (int k = 0; k < 65; k++)
					{
						cout << "\nDIST[" << k << "] = " << DIST[k];
					}
					cout << "\n\n(i,j) = (" << i << "," << j << ")";
					cout << "\nmax = " << max;
					cout << "\nmin = " << min;
					cout << "\ncount = " << count << " / " << REPETICAO/64; 
					percentual = static_cast<double>(100 * count) / (REPETICAO/64);
					cout << "\nPercentual restante = " << 100 - percentual << " \x25";
					
					cavalo.print_table();
					system("PAUSE");					
				}else if (n > max)
				{
					max = n;
					
					system ("CLS");
					cout << endl;
					for (int k = 0; k < 65; k++)
					{
						cout << "\nDIST[" << k << "] = " << DIST[k];
					}
					cout << "\n\n(i,j) = (" << i << "," << j << ")";
					cout << "\nmax = " << max;
					cout << "\nmin = " << min;
					cout << "\ncount = " << count << " / " << REPETICAO/64; 
					percentual = static_cast<double>(100 * count) / (REPETICAO/64);
					cout << "\nPercentual restante = " << 100 - percentual << " \x25";
					
					cavalo.print_table();
					system("PAUSE");					
				}
				
				if (REPETICAO > 10000)
				{
					if (count % ((REPETICAO/64)/100) == 0)
					{
						system ("CLS");
						cout << endl;
						for (int k = 0; k < 65; k++)
						{
							cout << "\nDIST[" << k << "] = " << DIST[k];
						}
						cout << "\n\n(i,j) = (" << i << "," << j << ")";
						cout << "\nmax = " << max;
						cout << "\nmin = " << min;
						cout << "\ncount = " << count << " / " << REPETICAO/64; 
						percentual = static_cast<double>(100 * count) / (REPETICAO/64);
						cout << "\nPercentual restante = " << (100 - percentual) << " \x25";
					}
				}else
				{
					if (count % 100 == 0)
					{
						system ("CLS");
						cout << endl;
						for (int k = 0; k < 65; k++)
						{
							cout << "\nDIST[" << k << "] = " << DIST[k];
						}
						cout << "\n\n(i,j) = (" << i << "," << j << ")";
						cout << "\nmax = " << max;
						cout << "\nmin = " << min;
						cout << "\ncount = " << count << " / " << REPETICAO/64; 
						percentual = static_cast<double>(100 * count) / (REPETICAO/64);
						cout << "\nPercentual restante = " << 100 - percentual << " \x25";
					}
				}
			}
		}		
	}	
	
	unsigned long int OPERACOES = 0;
	
	RESULTADO << "Passeio do cavalo" << endl;
	RESULTADO << "Posicoes vazias no tabuleiro" << "," << "Frequencia" << endl;
	
	for (int i = 0; i < 65; i++)
	{
		RESULTADO << i << "," << DIST[i] << endl;
		OPERACOES += (64 - i) * DIST[i]; 
	}
	
	RESULTADO.close();
	
	ofstream DIST_POS ("Distribuicao Posicao.txt",ios::out);
	
	DIST_POS << "Distribuicao de frequencias por posicao:\n";
	
	DIST_POS << "\nTentativas simuladas por posicao = " << REPETICAO/64 << endl << endl;
	
	const int WIDTH = 6;
	
	DIST_POS << setw(WIDTH) << setiosflags(ios::left) << "";
	
	for (int i = 0; i < TAM; i++)
	{		
		DIST_POS <<  setw(WIDTH) << setiosflags(ios::left) << i;
	}
	
	DIST_POS << endl << endl;
	
	for (int i = 0; i < TAM; i++)
	{
		DIST_POS <<  setw(WIDTH) << setiosflags(ios::left) << i;
		
		for (int j = 0; j < TAM; j++)
		{			
			DIST_POS <<  setw(WIDTH) << setiosflags(ios::left) << FREQ_POS[i][j];
		}
		
		DIST_POS << endl;
	}
	
	DIST_POS.close();
	
	cout << "\n\nOperacoes realizadas = " << OPERACOES << endl << endl;
	
	system ("PAUSE");
  return 0;
}
