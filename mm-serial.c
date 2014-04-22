#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#define NUMBER_OF_PASSES 10

int main(int argc, char** argv) {
	double** matrix_one;
	double** matrix_two;
	double** product_matrix;
	int matrix_one_size;
	int matrix_two_size;
	int product_matrix_size;
	int i;

	clock_t start, stop;
	double elapse_time;

	// check for the number of arguments passed	
	if(argc < 4) {
		fprintf(stderr, "Not enough arguments.\nRequired binary files:\n<Matrix File One> <Matrix File Two> <Output Matrix File>\n");
		exit(1);
	}

	// load first matrix
	loadFile2Darray(&matrix_one_size, &matrix_one, argv[1]);

	// load second matrix
	loadFile2Darray(&matrix_two_size, &matrix_two, argv[2]);

	// check for compatibility
	if(matrix_one_size != matrix_two_size) {
		fprintf(stderr, "Error.\nMatricies are not the same size.\n");
		exit(1);
	}
	else {
		product_matrix_size = matrix_one_size;
	}

	// alloc product matrix
	alloc2Darray(product_matrix_size, product_matrix_size, &product_matrix);

	// timing
	start = clock();
	// multiply matricies
	for (i = 0; i < NUMBER_OF_PASSES; i++) {
		mult2Darray(matrix_one_size, matrix_one, matrix_two, product_matrix);
	}
	stop = clock();
	elapse_time = (double)(stop - start) / CLOCKS_PER_SEC;

	// print results to screen
	printf("%i\t%i\t%f\n", NUMBER_OF_PASSES, product_matrix_size, elapse_time);

	// write answer to file
	printArrayToFile(product_matrix_size, product_matrix, argv[3]);
	
	// free arrays
	free2Darray(matrix_one);
	free2Darray(matrix_two);
	free2Darray(product_matrix);
	return 0;
}
