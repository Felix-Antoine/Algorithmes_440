#ifndef ARRAY_GEN_H
#define ARRAY_GEN_H

item* tri_array_gen(item* T1, int N, int R);
void sub_tri_array_gen(item* T, int low, int high);
int partition_array_gen(item* T, int low, int high);

item* array_gen(int N, int R, int D);
item* data_gen(int N, int R, int D);
void desordering(item* T, int N, int D);

#endif