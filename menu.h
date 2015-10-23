/*****************************************************************************************************/
/* Auteur :         Felix-Antoine Picard & Jean-Sebastien Roy									     */
/* Date :           2015/09/21																	     */
/* Fichier :        menu.h																		     */
/*																								     */
/* Descriptiom :    Ce fichier contient les declarations des fonctions de menu						 */
/*								                                                                     */
/*****************************************************************************************************/
#ifndef MENU_H
#define MENU_H

#include "search.h"

item* launch_menu_T1();

int* launch_menu_T2();

char get_mode();

int get_search();

item* get_data_file();

int* get_search_data_file();

int is_numeric(const char *);

char* set_param(char*, int);

int ConvertString(char*);

item* copy_T1(item* T1);

#endif