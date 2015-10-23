#include "stdafx.h"
extern int E_[4];
int Higher = 0;

void count_height(ttree arbre,int temp_height,int*height)
{
	temp_height++;
	
	if (temp_height > *height)
		*height = temp_height;

	if (arbre != NULL)
	{
		count_height(arbre->firstChild, temp_height, height);
		count_height(arbre->SecondChild, temp_height, height);
	}
}

ttree sub_add_to_tree(ttree arbre, item data)
{
	E_[0]++;
	if (arbre == NULL)
	{
		tree* newBranch = (tree*)malloc(sizeof(tree));
		newBranch->data = data;
		newBranch->firstChild = NULL;
		newBranch->SecondChild = NULL;
		Higher = 1;
		newBranch->BF = '=';
		return newBranch;
	}
	else if (data.element <= arbre->data.element)
	{
		arbre->firstChild = sub_add_to_tree(arbre->firstChild, data);
		if (Higher)
		{
			if (arbre->BF == 'L')
			{
				sub_balance_left(&arbre);
				Higher = 0;
			}
				
			else if (arbre->BF == '=')
			{
				arbre->BF = 'L';
			}
				
			else if (arbre->BF == 'R')
			{
				arbre->BF = '=';
				Higher = 0;
			}
		}
	}
	else
	{
		arbre->SecondChild = sub_add_to_tree(arbre->SecondChild, data);
		if (Higher)
		{
			if (arbre->BF == 'R')
			{
				sub_balance_right(&arbre);
				Higher = 0;
			}
				
			else if (arbre->BF == '=')
			{
				arbre->BF = 'R';
			}
				
			else if (arbre->BF == 'L')
			{
				arbre->BF = '=';
				Higher = 0;
			}
		}
	}
	return arbre;
}

void sub_balance_left(ttree* arbre)
{
	if ((*arbre)->firstChild->BF == 'R')
		sub_left_rotation(&((*arbre)->firstChild));
	sub_right_rotation(arbre);
	sub_reorganise_BF(arbre);
}

void sub_balance_right(ttree* arbre)
{
	if ((*arbre)->SecondChild->BF == 'L')
		sub_right_rotation(&((*arbre)->SecondChild));
	sub_left_rotation(arbre);
	sub_reorganise_BF(arbre);
}

void sub_left_rotation(ttree* arbre)
{
	ttree temp;
	temp = (tree*)malloc(1 * sizeof(tree));
	temp->BF = (*arbre)->BF;
	temp->data = (*arbre)->data;
	temp->firstChild = (*arbre)->firstChild;
	temp->SecondChild = (*arbre)->SecondChild;

	temp->SecondChild = (*arbre)->SecondChild->firstChild;
	(*arbre) = (*arbre)->SecondChild;
	(*arbre)->firstChild = temp;
}

void sub_right_rotation(ttree* arbre)
{
	ttree temp;
	temp = (tree*)malloc(1 * sizeof(tree));
	temp->BF = (*arbre)->BF;
	temp->data = (*arbre)->data;
	temp->firstChild = (*arbre)->firstChild;
	temp->SecondChild = (*arbre)->SecondChild;

	temp->firstChild = (*arbre)->firstChild->SecondChild;
	(*arbre) = (*arbre)->firstChild;
	(*arbre)->SecondChild = temp;
}

void sub_reorganise_BF(ttree* arbre)
{
	int left = 0;
	int right = 0;
	E_[0]++;
	if ((*arbre)->firstChild == NULL && (*arbre)->SecondChild != NULL)		// Right unbalanced
	{		
		(*arbre)->BF = 'R';
		sub_reorganise_BF(&(*arbre)->SecondChild);
	}
	else if ((*arbre)->firstChild != NULL && (*arbre)->SecondChild == NULL)	// Left unbalanced
	{	
		(*arbre)->BF = 'L';
		sub_reorganise_BF(&(*arbre)->firstChild);
	}
	else if ((*arbre)->firstChild != NULL && (*arbre)->SecondChild != NULL)	
	{	
		count_height((*arbre)->firstChild, 0, &left);
		count_height((*arbre)->SecondChild, 0, &right);
		if (left > right)
		{
			(*arbre)->BF = 'L';
		}
		else if (right > left)
		{
			(*arbre)->BF = 'R';
		}
		else
		{
			(*arbre)->BF = '=';
		}
		sub_reorganise_BF(&(*arbre)->firstChild);
		sub_reorganise_BF(&(*arbre)->SecondChild);
	}
	else						// Balanced
		(*arbre)->BF = '=';
}

ttree sub_prepare_search_tree(item* array_data, int N){
	ttree arbre = NULL;

	for (int i = 0; i < N; i++)
	{
		arbre = sub_add_to_tree(arbre, array_data[i]);
	}
	return arbre;
}

int sub_search_tree(ttree arbre, int value){
	E_[1]++;
	if (arbre == NULL)
		return -1;
	else if (arbre->data.element == value)
		return arbre->data.index;
	else if (arbre->data.element < value)
		return sub_search_tree(arbre->SecondChild, value);
	else if (arbre->data.element > value)
		return sub_search_tree(arbre->firstChild, value);

	return -1; // Should never return here
}

int* search_tree(item* array_data, int* array_search, int K, int N, int R, int D){

	int* array_result­ = (int*)calloc(K, sizeof(int));
	ttree arbre = sub_prepare_search_tree(array_data, N);

	for (int i = 0; i < K; i++)
		array_result­[i] = sub_search_tree(arbre, array_search[i]);

	free(arbre);
	return array_result­;
}