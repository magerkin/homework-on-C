#include "main.h"

//копирование (с выделением новой области памяти)
double * copyArr(double * inputArr, int n) {
	double * arr = NULL;
	arr = (double*)malloc(n*sizeof(double));
	memcpy(arr, inputArr, n*sizeof(double));
	return arr;
}

int main(){
	int n;
	printf("Please, input size of arrays \n");
	scanf("%d", &n);
	srand(time(NULL));

	void (*sortings[NUM_OF_SORTS])(double *, int n) = {bubbleSort, mergeSort, quickSort, selectionSort};
	double * (*generations[NUM_OF_ARRAYS])(int) = {increasingArr, decreasingArr, randomArr, almostSortedArr};
	char * namesOfArrays[NUM_OF_ARRAYS] = {"increasing  ", "decreasing  ", "random      ", "alm. sort.  "};
	double table[NUM_OF_ARRAYS][NUM_OF_SORTS];

	for (int i = 0; i < NUM_OF_ARRAYS; i++) {
		double * arr = generations[i](n);
		for (int j = 0; j < NUM_OF_SORTS; j++) {
			double * tmp = copyArr(arr, n);
			table[i][j] = clock();
			sortings[j](tmp, n);
			table[i][j] = (clock() - table[i][j]) /(double)  CLOCKS_PER_SEC;
			free(tmp);
		}
		free(arr);
	}

	// вывод
	printf("\n            bubbleSort mergeSort  quickSort  selectionSort \n");
	for (int i = 0; i<NUM_OF_ARRAYS; i++) {
		printf(namesOfArrays[i]);
		for (int j = 0; j<NUM_OF_SORTS; j++) {
			printf("%-10.3f ", table[i][j]);
		}
		printf("\n");
	}
	


}