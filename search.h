#ifndef SEARCH_H
#define SEARCH_H

typedef struct {
	int index;
	int element;
} item;


typedef struct list list;
struct list
{
	item data;
	list* next;
};
typedef list* llist;

typedef struct tree tree;
typedef struct tree
{
	char BF;
	item data;
	tree* firstChild;
	tree* SecondChild;
};

typedef tree* ttree;

// search_binary.cpp
int* search_binary(item* array_data, int* array_search, int K, int N, int R, int D);
void sub_prepare_search_binary(item* array_data, int N, int R, int D);
int sub_search_binary(item* array_data, int search_element, int start, int end);

// search_sequential.cpp
int* search_sequential(item* array_data, int* array_search, int K, int N, int R, int D);
int sub_search_sequential(item* array_data, int search_element, int N);

// search_hashtable.cpp 
int* search_hashtable(item* array_data, int* array_search, int K, int N, int R, int D);
int sub_search_hashtable(llist* array_hashing, int value);
llist* sub_prepare_search_hashtable(item* array_data, int N, int m);
int sub_find_n(llist* array_hashing, int m);
llist sub_add_to_llist(llist liste, item data);

// search_tree.cpp
int* search_tree(item* array_data, int* array_search, int K, int N, int R, int D);
ttree sub_prepare_search_tree(item* array_data, int N);
ttree sub_add_to_tree(ttree arbre, item data);
void sub_balance_left(ttree* arbre);
void sub_balance_right(ttree* arbre);
void sub_left_rotation(ttree* arbre);
void sub_right_rotation(ttree* arbre);
void sub_reorganise_BF(ttree* arbre);

// search_optimisee.cpp
int* search_optimisee(item* array_data, int* array_search, int K, int N, int R, int D, char* used_search);

void count_height(ttree arbre, int temp_height, int height);


#endif
