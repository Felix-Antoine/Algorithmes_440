#include "stdafx.h"

extern int E_[4];

// Selection de la meilleure algorithme de tri
void tri_array(item* array_data, int N, int R, int D)
{
	switch (selection_tri(N,R,D)){
	case 1:
		tri_par_pigeonnier(array_data, N, R);
		break;
	case 2:
		tri_rapide(array_data, N, R);
		break;
	case 3:
		tri_fusion(array_data, N, R);
		break;
	default:
		printf("Erreur");
		break;
	}
}

// Algorithme de tri par pigeonnier (si R est petit)
void tri_par_pigeonnier(item* array_data, int N, int R)
{
	item* tableau_pigeonnier = (item*)calloc((R + 1), sizeof(item));
	int i, j;

	for (i = 0; i < R + 1; i++)
		tableau_pigeonnier[i].element = -1;

	for (i = 0; i < N; i++, E_[0]++){
		tableau_pigeonnier[array_data[i].element].element = array_data[i].element;
		tableau_pigeonnier[array_data[i].element].index = array_data[i].index;
	}

	for (i = 0, j = 0; i < R + 1; i++,E_[0]++)
	{
		if(tableau_pigeonnier[i].element != -1)
		{
			array_data[j].element = tableau_pigeonnier[i].element;
			array_data[j].index = tableau_pigeonnier[i].index;
			j++;
		}
	}
	free(tableau_pigeonnier);
}

// Algorithme de tri rapide (si D est grand)
void tri_rapide(item* array_data, int N, int R)
{
	sub_tri_rapide(array_data, 0, N - 1);
}

void sub_tri_rapide(item* array_data, int low, int high)
{
	int pivot_location;

	if (low < high)
	{
		pivot_location = sub_partition(array_data, low, high);
		sub_tri_rapide(array_data, low, pivot_location - 1);
		sub_tri_rapide(array_data, pivot_location + 1, high);
	}
}

int sub_partition(item* array_data, int low, int high)
{
	int pivot = array_data[low].element;
	int leftwall = low;
	int i;
	item temp;

	for (i = low + 1; i <= high; i++,E_[0]++)
	{
		if (array_data[i].element < pivot)
		{
			leftwall++;
			temp = array_data[i];
			array_data[i] = array_data[leftwall];
			array_data[leftwall] = temp;
		}
	}
	temp = array_data[low];
	array_data[low] = array_data[leftwall];
	array_data[leftwall] = temp;

	return leftwall;
}


// Algorithme de tri par fusion (pour tout autres cas)
void tri_fusion(item* array_data, int N, int R)
{
	int i, j, k;
	int lenght = N / 2;
	item* a = (item*)calloc(lenght, sizeof(item));
	item* b = (item*)calloc((lenght + 1), sizeof(item));

	if (N <= 1)
		return;

	for (i = 0; i < lenght; i++)
	{
		a[i] = array_data[i];
	}
	for (k = 0, j = lenght; j < N; j++, k++)
	{
		b[k] = array_data[j];
	}


	tri_fusion(a, i, R);
	tri_fusion(b, j - lenght, R);

	sub_concatener(array_data, a, b, i, j - lenght);
}

void sub_concatener(item* array_data, item* a, item* b, int Na, int Nb)
{
	int i = 0, aa = 0, bb = 0;

	while (Na != 0 && Nb != 0)
	{
		E_[0]++;
		if (a[aa].element > b[bb].element)
		{
			array_data[i] = b[bb];
			Nb--;
			i++;
			bb++;
		}
		else
		{
			array_data[i] = a[aa];
			Na--;
			i++;
			aa++;
		}
	}
	while (Na != 0)
	{
		array_data[i] = a[aa];
		Na--;
		i++;
		aa++;
	}
	while (Nb != 0)
	{
		array_data[i] = b[bb];
		Nb--;
		i++;
		bb++;
	}

	free(a);
	free(b);
}

int selection_tri(int N, int R, int D)
{
	if (R <= 100000)
		return 1;
	else if (D >= 50)
		return 2;
	else
		return 3;
	return 0;
}