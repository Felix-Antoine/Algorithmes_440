
#include "stdafx.h"

int* search_optimisee(item* array_data, int* array_search, int K, int N, int R, int D, char* used_search)
{
	int* array_result­ = (int*)calloc(K, sizeof(int));

	if (N < 500)
	{
		array_result­ = search_sequential(array_data, array_search, K, N, R, D);
		*used_search = 'S';
	}
	else if (R - N < 100)
	{
		array_result­ = search_binary(array_data, array_search, K, N, R, D);
		*used_search = 'B';
	}
	else if (D >= 40 && D <= 60)
	{
		array_result­ = search_tree(array_data, array_search, K, N, R, D);
		*used_search = 'T';
	}
	else
	{
		array_result­ = search_hashtable(array_data, array_search, K, N, R, D);
		*used_search = 'H';
	}

	return array_result­;
	
}