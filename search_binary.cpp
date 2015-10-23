
#include "stdafx.h"

extern int E_[4];

int* search_binary(item* array_data, int* array_search, int K, int N, int R, int D){

	sub_prepare_search_binary(array_data, N, R, D);

	int* array_result­ = (int*)calloc(K, sizeof(int));

	for (int i = 0; i < K; i++,E_[1]++)
		array_result­[i] = sub_search_binary(array_data, array_search[i], 0, N);

	return array_result­;
}

void sub_prepare_search_binary(item* array_data, int N, int R, int D){
	tri_array(array_data, N, R, D);
}

int sub_search_binary(item* array_data, int search_element, int start, int end){
	E_[1]++;

	if (start > end)
		return -1;

	int center = (start + end) / 2;

	if (array_data[center].element == search_element)
		return array_data[center].index;

	if (array_data[center].element < search_element)
		return sub_search_binary(array_data, search_element, center + 1, end);
	else
		return sub_search_binary(array_data, search_element, start, center - 1);

}