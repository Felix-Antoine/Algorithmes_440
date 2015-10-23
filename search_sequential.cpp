#include "stdafx.h"
extern int E_[4];

int* search_sequential(item* array_data, int* array_search, int K, int N, int R, int D){

	int* array_result­ = (int*)calloc(K, sizeof(int));
	E_[0] = 0;		// Temps de preparation null

	for (int i = 0; i < K; i++,E_[1]++)
		array_result­[i] = sub_search_sequential(array_data, array_search[i], N);

	return array_result­;
}

int sub_search_sequential(item* array_data, int search_element, int N){

	for (int i = 0; i<N; i++,E_[1]++){
		if (array_data[i].element == search_element)
			return array_data[i].index;
	}
	return -1;
}
