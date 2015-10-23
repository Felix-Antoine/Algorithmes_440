
#ifndef TRI_H
#define TRI_H

void tri_array(item* array_data, int N, int R, int D);

void tri_par_pigeonnier(item* array_data, int N, int R);

void tri_rapide(item* array_data, int N, int R);

void sub_tri_rapide(item* array_data, int low, int high);

int sub_partition(item* array_data, int low, int high);

void tri_fusion(item* array_data, int N, int R);

void sub_concatener(item* array_data, item* a, item* b, int Na, int Nb);

int selection_tri(int N, int R, int D);

#endif