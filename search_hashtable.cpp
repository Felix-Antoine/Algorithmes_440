#include "stdafx.h"
extern int E_[4];
int final_m = 3; // Begin at 3
double final_alpha;

llist sub_add_to_llist(llist liste, item data){
	list* newList = (list*)malloc(sizeof(list));

	newList->data = data;

	newList->next = liste;

	return newList;
}

int sub_find_n(llist* array_hashing, int m){
	list *tmp;
	int count, maximum = 0;

	for (int i = 0; i < m; i++){
		count = 0;
		tmp = array_hashing[i];

		while (tmp != NULL){
			E_[0]++;
			count++;
			tmp = tmp->next;
		}

		if (count > maximum)
			maximum = count;
	}
	return maximum;
}

llist* sub_prepare_search_hashtable(item* array_data, int N){
	int modulo;
	llist* array_hashing = (llist*)calloc(final_m, sizeof(list*));

	for (int i = 0; i < N; i++, E_[0]++){
		modulo = array_data[i].element % final_m;
		array_hashing[modulo] = sub_add_to_llist(array_hashing[modulo], array_data[i]);
	}

	final_alpha = (double)sub_find_n(array_hashing, final_m) / final_m;

	if (final_alpha > 1.0){
		final_m = (int)(final_m * 2);

		free(array_hashing);
		return sub_prepare_search_hashtable(array_data, N);

	}
	else
		return array_hashing;
}

int sub_search_hashtable(llist* array_hashing, int value){

	int modulo = value % final_m;
	list *tmp = array_hashing[modulo];

	while (tmp != NULL){
		E_[1]++;
		if (tmp->data.element == value)
			return tmp->data.index;
		tmp = tmp->next;
	}

	return -1;
}

int* search_hashtable(item* array_data, int* array_search, int K, int N, int R, int D){

	int* array_result­ = (int*)calloc(K, sizeof(int));
	llist* array_hashing = sub_prepare_search_hashtable(array_data, N);

	for (int i = 0; i < K; i++)
		array_result­[i] = sub_search_hashtable(array_hashing, array_search[i]);

	free(array_hashing);
	return array_result­;
}





