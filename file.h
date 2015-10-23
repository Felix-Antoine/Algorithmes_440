/****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy                                       */
/* Date :           2015/09/21                                                                      */
/* Fichier :        file.h											                                */
/*                                                                                                  */
/* Descriptiom :    Ce fichier contient les declarations des fonctions de gestion des fichiers      */
/*								                                                                    */
/****************************************************************************************************/
#ifndef FILE_H
#define FILE_H

bool file_exists(const char *);

item* extract_data(const char *);

int* extract_search_data(const char * filename);

void save_data(item*, char[100]);

void save_search_data(int* T, char filename[100]);

void save_stats(item* T1, int* T2, int* T3, char nom_algo[80], int tri, char filename[100]);

void print_stats(char nom_algo[80], int tri, int* T3);

#endif