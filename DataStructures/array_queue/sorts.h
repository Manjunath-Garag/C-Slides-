#ifndef SORTS_H
#define SORTS_H

void insertion(int *a,int size);

void selection(int *a,int size);

void bubble(int *a,int size);

void print_array(int *a,int size);

void merge_partition(int *a,int low,int high);
void merge_sort(int *a,int low,int high);


int partition(int *arr, int low, int high);
void quick_sort(int *arr, int low, int high);

void max_heapify(int *arr,int size, int parent);
void heap_sort(int *arr,int size);

#endif
