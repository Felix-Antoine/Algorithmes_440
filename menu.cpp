/****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy										*/
/* Date :           2015/09/21																		*/
/* Fichier :        menu.cpp																		*/
/*																									*/
/* Descriptiom :    Ce fichier contient tout les fonction menu du projet							*/
/*																                                    */
/****************************************************************************************************/

#include "stdafx.h"

extern int N_;
extern int R_;
extern int D_;
extern int K_;
extern int E_[4];

int ConvertString(char* buffer)
{
	char *ptr;
	int result = 0;
	int i = 0;
	ptr = buffer;
	while (*ptr != '\0')
	{
		result = (result * 10) + (*ptr - '0');
		ptr++; i++;
	}
	return result;
}

char get_mode(){
	char mode = '\n';

	do{
		if (mode == '\n')
			printf("'F' - fichier, 'G' - genere?");
		scanf("%c", &mode);
		mode = toupper(mode);
	} while (mode != 'F' && mode != 'G');
	return mode;
}

item* launch_menu_T1(){
	char mode = 0;
	char fileName[100];
	char temp[100];
	item* T1;

	printf("Quel est le mode a utiliser pour le tableau T1 : \n");
	mode = get_mode();

	if (mode == 'F'){
		// Ask File to use
		T1 = get_data_file();
	}
	else if (mode == 'G'){
		// Ask params for generating new array
		strcpy(temp, set_param("Quelle est la valeur de N ?", 1));
		N_ = ConvertString(temp);
		strcpy(temp, set_param("Quelle est la valeur de R ?", 1));
		R_ = ConvertString(temp);
		strcpy(temp, set_param("Quelle est la valeur de D ?", 1));
		D_ = ConvertString(temp);
		strcpy(fileName, set_param("Quel nom voulez-vous donnez au fichier ?", 0));

		// Generate new array and save it into filename
		T1 = array_gen(N_, R_, D_);
		save_data(T1, fileName);
	}
	return T1;
}

int* launch_menu_T2(){
	char mode = 0;
	char fileName[100];
	char temp[100];
	int* T2;

	printf("Quel est le mode a utiliser pour le tableau T2?\n");
	mode = get_mode();

	if (mode == 'F'){
		// Ask File to use
		T2 = get_search_data_file();
	}
	else if (mode == 'G'){
		K_ = 1;
		T2 = (int*)malloc(1 * sizeof(int));
		strcpy(temp, set_param("Quelle est la valeur a rechercher ?", 1));
		T2[0] = ConvertString(temp);
	}
	strcpy(fileName, "T2.txt");
	save_search_data(T2, fileName);
	return T2;
}

int get_search(){
	char search = 0;
	do{
		if (search != '\n')
			printf("Selectionez un algorithmes de recherche : \n '1' - recherche sequentielle, '2' - recherche binaire, '3' - table de hachage \n '4' - arbre de recherche, '5' - recherche optimisee");
		search = toupper(getchar());
	} while (search != '1' && search != '2' && search != '3' && search != '4' && search != '5' && search != '6');
	return search - '0';
}

item* get_data_file(){
	char fileName[100];
	int firstTime = 0;
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);

	do{
		if (fileName[0] != '\n'){
			if (firstTime == 0){
				printf("Quel est le nom du fichier a utiliser ?");
				firstTime++;
			}
			else
				printf("Fichier non trouve.. Quel est le nom du fichier a utiliser ?");
		}
		fgets(fileName, 100, stdin);
		strtok(fileName, "\n");
	} while (!file_exists(fileName));

	// Get data from file
	item* T = extract_data(fileName);

	return T;
}

int* get_search_data_file(){
	char fileName[100];
	int firstTime = 0;
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);

	do{
		if (fileName[0] != '\n'){
			if (firstTime == 0){
				printf("Quel est le nom du fichier a utiliser ?");
				firstTime++;
			}
			else
				printf("Fichier non trouve.. Quel est le nom du fichier a utiliser ?");
		}
		fgets(fileName, 100, stdin);
		strtok(fileName, "\n");
	} while (!file_exists(fileName));

	// Get data from file
	int* T = extract_search_data(fileName);

	return T;
}

// Cette fonction provient de http://rosettacode.org/wiki/Determine_if_a_string_is_numeric#C
int is_numeric(const char * s)
{
	if (s == NULL || *s == '\0' || isspace(*s))
		return 0;
	char * p;
	strtod(s, &p);
	return *p == '\0';
}

char* set_param(char* message, int isNumericCondition){
	char param[125];
	int firstTime = 0;

	do{
		if (firstTime == 0){
			printf(message);
			firstTime++;
		}
		else{
			if (isNumericCondition == 1 && !is_numeric(param)){
				if (param[0] != 10 && param[0] != 0)
					printf("Cette valeure a besoin d'etre numerique.");
			}
			else
				break;
		}
		fgets(param, 100, stdin);
		strtok(param, "\n");
	} while (1);

	return param;
}

item* copy_T1(item* T1)
{
	int i;
	item* T1_cpy;

	T1_cpy = (item*)malloc(N_*sizeof(item));

	for (i = 0; i < N_; i++)
	{
		T1_cpy[i] = T1[i];
	}

	return T1_cpy;
}