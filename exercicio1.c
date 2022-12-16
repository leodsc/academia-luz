#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_VALUE 50000;
#define MIN_VALUE 1;

//typedef struct {
//	int key;	
//	char[] value;
//} Map;
//

void showArray(int **arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", (*arr)[i]);
	}
	puts("");
}

void swap(int i, int j, int arr[]) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void bubbleSort(int size, int **arr) {
	int isOrdered = 1;
	for (int i = 0; i < size; i++) {
		if (size > 10000) {
			printf("Bubble sort rodando... item atual: %d", i);
			printf("\r");
		}
		for (int j = i; j < size; j++) {
			if ((*arr)[i] > (*arr)[j]) {
				swap(i, j, *arr);
				isOrdered = 0;
			}
		}
		if (isOrdered) {
			break;
		}
	}
	puts("");
}

void selectionSort(int size, int arr[]) {
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[i] < arr[j]) {
				swap(i, j, arr);
			}
		}
	}
}

void insertionSort(int size, int arr[]) {
	for (int i = 1; i < size; i++) {
		int temp = arr[i];
		int j = i-1;
		while (j >= 0 && arr[i] < arr[j]) {
			arr[j+1] = arr[j];
			j -= 1;
		}
		arr[j] = temp;
	}
}

void merge(int arr[], int bottom, int middle, int upper) {

	  int leftSize = middle - bottom + 1;
		int rightSize = upper - middle;
		int left[leftSize], right[rightSize];

		for (int i = 0; i < leftSize; i++) {
				left[i] = arr[bottom + i];
		}
		for (int j = 0; j < rightSize; j++) {
				right[j] = arr[middle + 1 + j];
		}

		int i, j, k;
		i = 0;
		j = 0;
		k = bottom;

		while (i < leftSize && j < rightSize) {
			if (left[i] <= right[j]) {
				arr[k] = left[i];
				i++;
			} else {
				arr[k] = right[j];
				j++;
			}
			k++;
		}

		while (i < leftSize) {
			arr[k] = left[i];
			i++;
			k++;
		}

		while (j < rightSize) {
			arr[k] = right[j];
			j++;
			k++;
		}
}

void mergeSort(int arr[], int bottom, int upper) {
	  if (bottom < upper) {
			int middle = bottom + (upper - bottom) / 2;
			mergeSort(arr, bottom, middle);
			mergeSort(arr, middle + 1, upper);
			merge(arr, bottom, middle, upper);
		}
}

int partition(int **arr, int bottom, int upper) {
	int pivot = (*arr)[upper];
	int currentPos = bottom-1;

	for (int i = bottom; i < upper; i++) {
		if ((*arr)[i] < pivot) {
			currentPos += 1;
			swap(i, currentPos, (*arr));
		}
	}

	swap(currentPos+1, upper, (*arr));
	return currentPos+1;
}

void quickSort(int **arr, int bottom, int upper) {
	if (bottom < upper) {
		int pivotIndex = partition(arr, bottom, upper);
		quickSort(arr, bottom, pivotIndex-1);
		quickSort(arr, pivotIndex+1, upper);
	}
}

void generateArray(int size, int **arr) {
	for (int i = 0; i < size; i++) {
		(*arr)[i] = rand() % MAX_VALUE + MIN_VALUE; 
	}
}

int choices() {
		printf("Escolha uma das opções abaixo: \n");
		printf("1 - Bubble sort\n");
		printf("2 - Selection sort\n");
		printf("3 - Insertion sort\n");
		printf("4 - Merge sort\n");
		printf("5 - Quick sort\n");
		printf("6 - Todos (um após o outro)\n");
		printf("7 - Reiniciar array\n");
		printf("8 - Sair\n");

		int choice;
		scanf("%d", &choice);
		return choice;
}

void menu() {
	int size = -1;
	int answer;
	int *arr;

	printf("Qual o tamanho do array? ");
	scanf("%d", &size);
	arr = malloc(size * sizeof(int));
	generateArray(size, &arr);

	do {
		answer = choices();
		clock_t begin = clock();

		switch (answer) {
			case 1:
				bubbleSort(size, &arr);
				break;
			case 2:
				selectionSort(size, arr);
				break;
			case 3:
				insertionSort(size, arr);
				break;
			case 4:
				mergeSort(arr, 0, size);
				break;
			case 5:
				quickSort(&arr, 0, size);
				break;
			case 6:
				bubbleSort(size, &arr);
				selectionSort(size, arr);
				insertionSort(size, arr);
				break;
			case 7:
				free(arr);
				generateArray(size, &arr);
				puts("Array foi reiniciado!");
				break;
			case 8:
				puts("Obrigado! :)");
				break;
			default:
				puts("Valor inválido! Tente novamente");
		}

		if (answer != 8) {
			clock_t end = clock();
			double timeSpent = (double) (end-begin) / CLOCKS_PER_SEC;
			printf("O algoritmo levou %.2f segundos\n", timeSpent);

			char show;
			puts("Mostrar array? s ou n ");
			getchar();
			scanf("%c", &show);
			if (show == 's') {
				showArray(&arr, size);
			}
		}

	} while (answer != 8);
}

int main() {
	srand(time(NULL));
	menu();
	return 0;
}
