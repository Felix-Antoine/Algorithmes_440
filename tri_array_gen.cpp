/****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy                                       */
/* Date :           2015/09/21                                                                      */
/* Fichier :        tri_array_gen.cpp                                                               */
/*                                                                                                  */
/* Descriptiom :    Ce fichier permet le tri d'un tableau de donnée de taille N, rang R et niveau de*/
/*                  desordre D selon l'agorithme du tri rapide                                      */
/****************************************************************************************************/

#include "stdafx.h"

item* tri_array_gen(item* T1, int N, int R)
{
	sub_tri_array_gen(T1, 0, N - 1);
	return T1;
}

void sub_tri_array_gen(item* T, int low, int high)
{
	int pivot_location;

	if (low < high)
	{
		pivot_location = partition_array_gen(T, low, high);
		sub_tri_array_gen(T, low, pivot_location - 1);
		sub_tri_array_gen(T, pivot_location + 1, high);
	}
}

int partition_array_gen(item* T, int low, int high)
{
	int pivot = T[low].element;
	int leftwall = low;
	int i;
	item temp;

	for (i = low + 1; i <= high; i++)
	{
		if (T[i].element < pivot)
		{
			leftwall++;
			temp = T[i];
			T[i] = T[leftwall];
			T[leftwall] = temp;
		}
	}
	temp = T[low];
	T[low] = T[leftwall];
	T[leftwall] = temp;

	return leftwall;
}