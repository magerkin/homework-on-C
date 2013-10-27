#include <stdlib.h>
#include <stdio.h>
#define PROC 5 // 1/PROC - процент изменения в почти отсортированном массиве 

double * increasingArr (int size); 

double * decreasingArr (int size); 

double * randomArr (int size); 

double * almostSortedArr (int size);

void printArr (double * arr, int n);