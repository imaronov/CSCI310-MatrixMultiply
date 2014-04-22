#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// allocate 2D array
void alloc2Darray(int dimension1, int dimension2, double*** array) {
	double** x;
	double* data;

	x = (double**)malloc(dimension1 * sizeof(double*));
	data = (double*)malloc(dimension1 * dimension2 * sizeof(double));

	int i;
	for(i = 0; i < dimension1; i++) {
		x[i] = data + (i * dimension2);
	}

	*array = x;
}

// free 2D array
void free2Darray(double** array) {
	free(array[0]);
	free(array);
}

// loads the array with values
void load2Darray(double lower, double upper, int size, double** array) {
	srand(time(NULL));
	
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			array[i][j] = (double)(rand() * (upper - lower)) / (double)RAND_MAX + lower;
		}
	}
}

// prints to file
void printArrayToFile(int size, double** array, char* file_name) {
	FILE* ptr_file;
	
	ptr_file = fopen(file_name, "w+");
	fwrite(&size, sizeof(int), 1, ptr_file);
	fwrite(array[0], sizeof(double), (size * size) , ptr_file);
	fclose(ptr_file);
}

//TODO: check if file exists
void loadFile2Darray(int* size, double*** array, char* file_name) {
	FILE* ptr_file;
	double** x;
	double* data;

	ptr_file = fopen(file_name, "r");
	
	fread(size, sizeof(int), 1, ptr_file);	// reads the size of the matrix
	x = (double**)malloc(*size * sizeof(double*));
	data = (double*)malloc(*size * *size * sizeof(double));
	fread(data, sizeof(double), *size * *size, ptr_file);

	int i;
	for(i = 0; i < *size; i++) {
		x[i] = data + (i * *size);
	}

	fclose(ptr_file);
	*array = x;
}

// prints array to screen
void print2Darray(int x, int y, double** array) {
	int i, j;
	
	printf("[%d x %d] MATRIX\n", x, y);
	for(i = 0; i < x; i++) {
		for(j = 0; j < y; j++) {
			printf("%.2f ", array[i][j]);
		}
		printf("\n");
	}
}

// multiply matrix
void mult2Darray(int size, double** one, double** two, double** product) {
	int i, j, k;
	double sum = 0;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			for(k = 0; k < size; k++) {
				sum += one[i][k] * two[k][j];
			}
			product[i][j] = sum;
			sum = 0;
		}
	}
}








