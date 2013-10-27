#include "sortings.h"

void swap(double * e1, double * e2) {
	double tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void bubbleSort(double * arr, int n){
	for (int j = 0; j<n-2; j++) {
		for (int i = 0; i<n-j-1; i++) {
			if (arr[i]>arr[i+1]) {
				swap(&arr[i], &arr[i+1]);
			}
		}
	}
}



void mergeSort(double * arr, int n){
	if (n>1){
		//разбиваем массив на 2 подмассива
		int lSize = n/2;
		int rSize = n-lSize;
		int doubleSize = sizeof(double);
		double * arrLeft = NULL;
		double * arrRight = NULL;
		arrLeft = (double*)malloc(lSize*doubleSize);
		arrRight = (double*)malloc(rSize*doubleSize);
		memcpy(arrLeft, arr, lSize*doubleSize);
		memcpy(arrRight, arr+lSize, rSize*doubleSize);

		//рекурсивный спуск
		mergeSort(arrLeft, lSize);
		mergeSort(arrRight, rSize);

		//слияние
		int lCounter = 0;
		int rCounter = 0;
		int i;
		for (i = 0; (i < n)&&(lCounter < lSize)&&(rCounter < rSize); i++) {
			if (arrLeft[lCounter] < arrRight[rCounter]) {
				arr[i] = arrLeft[lCounter];
				lCounter++;
			}
			else {
				arr[i] = arrRight[rCounter];
				rCounter++;
			}
		}

		//добавление остатка
		if (lCounter < lSize) {
			for (int j = i; j < n; j++) {
				arr[j] = arrLeft[lCounter];
				lCounter++;
			}
		}

		if (rCounter < rSize) {
			for (int j = i; j < n; j++) {
				arr[j] = arrRight[rCounter];
				rCounter++;
			}
		}
		
		free(arrRight);
		free(arrLeft);

	}
}

void quickSort(double * arr, int n) {
	if (n>2) { 
		int left = 0;
		int right = n-1;
		int middle = n/2;

		while (left < right) {

			while (arr[left] < arr[middle]) left++;
			while (arr[right] > arr[middle]) right--;

			if (left < right) {
				if (left == middle) middle = right;
				else if (right == middle) middle = left;
				swap(&arr[left], &arr[right]);
				left++;
				right--;
			}
		}
	
		quickSort(arr, &arr[middle]-arr);
		quickSort(&arr[middle]+1, n-1-(&arr[middle]-arr));
	}
	else if (n==2) {
		if (arr[0] > arr[1]) swap(&arr[0], &arr[1]);
	}
}


void selectionSort(double * arr, int n) {
	int min;
	for (int i = 0; i < (n-1); i++) {
		min = i;
		for (int j = i+1; j<n; j++) {
			if (arr[j]<arr[min]) min = j;
		}
		if (min!=i) {
			swap(&arr[i], &arr[min]);
		}
	}
}
