#include "arrGenerations.h"


double * increasingArr (int size) {
	double * arr = NULL;
	arr = (double*)malloc(size*sizeof(double));
	arr[0] =  rand()/(double)(rand() + 1);
	for (int i=1; i<size; i++) {
		arr[i] =  arr[i-1] + rand()/(double)(rand() + 1);
	}
	return arr;
}

double * decreasingArr (int size) {
	double * arr = NULL;
	arr = (double*)malloc(size*sizeof(double));
	double * tmpArr = increasingArr(size);
	for (int i=0; i<size; i++) arr[i] = tmpArr[(size-1)-i];
	free(tmpArr);
	return arr;
}

double * randomArr (int size) {
	double * arr = NULL;
	arr = (double*)malloc(size*sizeof(double));
	for (int i=0; i<size; i++) {
		arr[i] =  rand()/(double)(rand() + 1);
	}
	return arr;
}

double * almostSortedArr (int size) {
	 double * arr = increasingArr(size);
	 for (int i = 0; i<(size/PROC); i++) {
		 int j = rand() % size;
		 arr[j] = rand()/(double)(rand() + 1);
	 }
	 return arr;
}

void printArr (double * arr, int n) {
	for (int i=0; i<n; i++) {
			printf("%f %c", arr[i], ' ');
	}
}