
#include "stdafx.h"

int N_;
int R_;
int D_;
int K_;
int E_[4];

void main()
{
	item* T1		= NULL;
	item* T1_init	= NULL;
	int* T2			= NULL;
	int* T3			= NULL;
	int i, search, tri_utilise = 0;
	char used_search = 'E';
	char algo_recherche[80];

	T1 = launch_menu_T1();
	T2 = launch_menu_T2();
	search = get_search();
	T1_init = copy_T1(T1);

	E_[0] = 0;
	E_[1] = 0;
	E_[2] = 0;
	E_[3] = 0;

	switch (search){
	case 1:					// Sequential search
		T3 = search_sequential(T1, T2, K_, N_, R_, D_);
		strcpy(algo_recherche, "Recherche sequentielle");
		break;
	case 2:					// Binary search
		T3 = search_binary(T1, T2, K_, N_, R_, D_);
		strcpy(algo_recherche, "Recherche binaire");
		tri_utilise = selection_tri(N_, R_, D_);
		
		break;
	case 3:					// Hashtable search
		T3 = search_hashtable(T1, T2, K_, N_, R_, D_);
		strcpy(algo_recherche, "Recherche par table de hachage");
		break;
	case 4:					// Tree search
		T3 = search_tree(T1, T2, K_, N_, R_, D_);
		strcpy(algo_recherche, "Recherche par arbre");
		break;
	case 5:					// Optimisation search
		T3 = search_optimisee(T1, T2, K_, N_, R_, D_,&used_search);
		switch (used_search){
		case 'S':
			strcpy(algo_recherche, "Recherche optimisee - Recherche sequentielle");
			break;
		case 'B':
			strcpy(algo_recherche, "Recherche optimisee - Recherche binaire");
			tri_utilise = selection_tri(N_, R_, D_);
			break;
		case 'H':
			strcpy(algo_recherche, "Recherche optimisee - Recherche par table de hachage");
			break;
		case 'T':
			strcpy(algo_recherche, "Recherche optimisee - Recherche par arbre");
			break;
		case 'E':
			strcpy(algo_recherche, "Recherche optimisee - Erreur");
			break;
		}
		break;
	}
	E_[2] = E_[0] + E_[1];
	E_[3] = E_[2] / K_;

	print_stats(algo_recherche,tri_utilise,T3);
	save_stats(T1_init, T2, T3, algo_recherche, tri_utilise, "stats.txt");

}

