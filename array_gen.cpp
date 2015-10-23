/****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy                                       */
/* Date :           2015/09/21                                                                      */
/* Fichier :        array_gen.cpp			                                                        */
/*                                                                                                  */
/* Descriptiom :    Ce fichier permet la generation de donnees aleatoires en fonction de R, D et N  */
/*																                                    */
/****************************************************************************************************/

#include "stdafx.h"

item* array_gen(int N, int R, int D)
{
	int i;
	item* T;
	T = data_gen(N, R, D);
	T = tri_array_gen(T, N, R);
	desordering(T, N, D);

	for (i = 0; i < N; i++)
	{
		T[i].index = i;
	}

	return T;
}

/*Source de l'algorithme de generation : http://stackoverflow.com/questions/1608181/unique-random-numbers-in-an-integer-array-in-the-c-programming-language */
/*Algorithme de Floyd*/
item* data_gen(int N, int R, int D)
{
	item* T = (item*)calloc(N, sizeof(item));
	int r, iR, iN = 0;
	int* is_used = (int*)calloc(R, sizeof(int));
	// Insertion des donnees
	for (iR = R - N; iR<R && iN<N; iR++)
	{
		r = rand() % (iR + 1);
		if (is_used[r])
		{
			r = iR;
		}
		T[iN++].element = r;
		is_used[r] = 1;
	}
	return T;
}

void desordering(item* T, int N, int D)
{
	int M = N / 2;
	int m = M;
	int i, k, L;
	item temp;
	// Initialisation tableau Tp = {1,2,3,...,M}
	int* Tp = (int*)malloc(M*sizeof(int));
	for (i = 1; i <= M; i++)
	{
		Tp[i - 1] = i;
	}

	// Boucle de désordonnement
	for (i = 0; i < (M*D) / 100; i++)
	{
		k = rand() % m;
		L = Tp[k];
		Tp[k] = Tp[m - 1];
		m = m - 1;

		temp = T[M - L];
		T[M - L] = T[M + L - 1];
		T[M + L - 1] = temp;
	}

}