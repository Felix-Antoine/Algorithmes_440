/****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy                                       */
/* Date :           2015/09/21                                                                      */
/* Fichier :        file.cpp																	    */
/*                                                                                                  */
/* Descriptiom :    Ce fichier permet la gestion des fichiers pour ce projet						*/
/*																	                                */
/****************************************************************************************************/

#include "stdafx.h"

extern int N_;
extern int R_;
extern int D_;
extern int K_;
extern int E_[4];

bool file_exists(const char * filename){
	if (FILE * file = fopen(filename, "r")){
		fclose(file);
		return true;
	}
	return false;
}

int concatenate(int x, int y) {
	int pow = 10;
	while (y >= pow)
		pow *= 10;
	return x * pow + y;
}

item* extract_data(const char * filename){
	item* T;
	char line[100];
	char* token;
	char temp[100] = { 0 };
	char* next_token;
	int i = 0;
	int data;

	if (FILE * file = fopen(filename, "r")){


		while (fgets(line, 100, file) != NULL){

			token = strtok(line, "\t");
			while (token){

				sscanf(token, "%d", &data);
				next_token = strtok(NULL, "\t");

				if (temp[0] != 0){

					if (line[0] != '\t' && line[0] != 0){
						strcat(temp, token);
						sscanf(temp, "%d", &data);
						T[i - 3].element = data;
						T[i - 3].index = i - 3;
					}
					else{
						sscanf(temp, "%d", &data);
						T[i - 3].element = data;
						T[i - 3].index = i - 3;
						i++;

						sscanf(token, "%d", &data);
						T[i - 3].element = data;
						T[i - 3].index = i - 3;
					}

					temp[0] = 0;

				}
				else if (i == 0){
					T = (item*)malloc(data*sizeof(item));
					N_ = data;
				}
				else if (i == 1)
					R_ = data;
				else if (i == 2)
					D_ = data;
				else if (next_token == NULL){
					if (line[98] == '\t' || line[98] == 0){
						T[i - 3].element = data;
						T[i - 3].index = i - 3;
						i++;
					}
					else
						strcpy(temp, token);
					break;
				}
				else{
					T[i - 3].element = data;
					T[i - 3].index = i - 3;
				}

				i++;
				token = next_token;
			}
		}

		if (temp[0] != 0){
			sscanf(temp, "%d", &data);
			T[i - 3].element = data;
			T[i - 3].index = i - 3;
		}

		fclose(file);
	}

	return T;
}

int* extract_search_data(const char * filename){
	int* T;
	char line[100];
	char* token;
	char temp[100] = { 0 };
	char* next_token;
	int i = 0;
	int data;

	if (FILE * file = fopen(filename, "r")){


		while (fgets(line, 100, file) != NULL){

			token = strtok(line, "\t");
			while (token){

				sscanf(token, "%d", &data);
				next_token = strtok(NULL, "\t");

				if (temp[0] != 0){

					if (line[0] != 9 && line[0] != 0){
						strcat(temp, token);
						sscanf(temp, "%d", &data);
						T[i - 1] = data;
					}
					else{
						sscanf(temp, "%d", &data);
						T[i - 1] = data;
						i++;

						sscanf(token, "%d", &data);
						T[i - 1] = data;
					}

					temp[0] = 0;

				}
				else if (i == 0){
					T = (int*)malloc(data*sizeof(int));
					K_ = data;
				}
				else if (next_token == NULL){
					if (line[98] == 9 || line[98] == 0){
						T[i - 1] = data;
						i++;
					}
					else
						strcpy(temp, token);
					break;
				}
				else
					T[i - 1] = data;
				i++;
				token = next_token;
			}
		}

		if (temp[0] != 0){
			sscanf(temp, "%d", &data);
			T[i - 1] = data;
		}

		fclose(file);
	}

	return T;
}

void save_stats(item* T1, int* T2, int* T3, char nom_algo[80], int tri, char filename[100]){

	int i, recherche_fructueuse = 0;;

	if (FILE * file = fopen(filename, "w"))
	{
		// Print Stats
		fprintf(file, nom_algo);
		fprintf(file, "\n");
		fprintf(file, "Methode de tri : ");
		switch(tri){
		case 1:
			fprintf(file, "Tri par pigeonnier\n");
			break;
		case 2:
			fprintf(file, "Tri rapide\n");
			break;
		case 3:
			fprintf(file, "Tri fusion\n");
			break;
		default:
			fprintf(file, "N/A\n");
			break;
		}
		fprintf(file, "N = %d\n", N_);
		fprintf(file, "R = %d\n", R_);
		fprintf(file, "D = %d\n", D_);
		fprintf(file, "Nombre de recherche executees : %d\n", K_);
		for (i = 0; i < K_; i++)
		{
			if (T3[i] != -1)
			{
				recherche_fructueuse++;
			}
		}
		fprintf(file, "Nombre de recherche fructueuses : %d\n", recherche_fructueuse);

		fprintf(file, "Performances :\n");
		fprintf(file, "\tTemps de preparation(Tp) = %d\n", E_[0]);
		fprintf(file, "\tTemps total de recherche(Tr) = %d\n", E_[1]);
		fprintf(file, "\tTemps total(T) = %d\n", E_[2]);
		fprintf(file, "\tTemps amorti par recherche(Ta) = %d\n", E_[3]);

		// Print T1
		fprintf(file, "Tableau T1\n");
		for (i = 0; i < N_; i++)
			fprintf(file, "%d\t", T1[i].element);
		fprintf(file, "\n");
		// Print T2
		fprintf(file, "Tableau T2\n");
		for (i = 0; i < K_; i++)
			fprintf(file, "%d\t", T2[i]);
		fprintf(file, "\n");
		//Print T3
		fprintf(file, "Tableau T3\n");
		for (i = 0; i < K_; i++)
			fprintf(file, "%d\t", T3[i]);
		fprintf(file, "\n");

		fclose(file);
	}

}

void save_data(item* T, char filename[100]){

	if (FILE * file = fopen(filename, "w"))
	{
		fprintf(file, "%d\t", N_);
		fprintf(file, "%d\t", R_);
		fprintf(file, "%d\n", D_);

		for (int i = 0; i <= (N_ - 1); i++)
			fprintf(file, "%d\t", T[i].element);

		fclose(file);
	}

}

void save_search_data(int* T, char filename[100]){

	if (FILE * file = fopen(filename, "w"))
	{
		fprintf(file, "%d\n", K_);

		for (int i = 0; i <K_; i++)
			fprintf(file, "%d\t", T[i]);

		fclose(file);
	}

}

void print_stats(char nom_algo[80], int tri, int* T3)
{
	int i, recherche_fructueuse = 0;
	printf(nom_algo);
	printf("\n");
	printf("Methode de tri : ");
	switch (tri){
	case 1:
		printf("Tri par pigeonnier\n");
		break;
	case 2:
		printf("Tri rapide\n");
		break;
	case 3:
		printf("Tri fusion\n");
		break;
	default:
		printf("N/A\n");
		break;
	}
	printf("N = %d\n", N_);
	printf("R = %d\n", R_);
	printf("D = %d\n", D_);
	printf("Nombre de recherche executees : %d\n", K_);
	for (i = 0; i < K_; i++)
	{
		if (T3[i] != -1)
		{
			recherche_fructueuse++;
		}
	}
	printf("Nombre de recherche fructueuses : %d\n", recherche_fructueuse);

	printf("Performances :\n");
	printf("\tTemps de preparation(Tp) = %d\n", E_[0]);
	printf("\tTemps total de recherche(Tr) = %d\n", E_[1]);
	printf("\tTemps total(T) = %d\n", E_[2]);
	printf("\tTemps amorti par recherche(Ta) = %d\n", E_[3]);

}