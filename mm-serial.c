#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(int argc, char** argv) {
	double** matrix_one;
	double** matrix_two;
	double** product_matrix;
	int matrix_one_size;
	int matrix_two_size;
	int product_matrix_size;
	//unsigned long floating_point_operations;

	clock_t start, stop;
	double elapse_time;
	//unsigned long flops;

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
	mult2Darray(matrix_one_size, matrix_one, matrix_two, product_matrix);
	stop = clock();
	elapse_time = (double)(stop - start) / CLOCKS_PER_SEC;
	//floating_point_operations = product_matrix_size * product_matrix_size * product_matrix_size;
	//flops = floating_point_operations / elapse_time;
	// print results to screen
	printf("%i\t%f\n", product_matrix_size, elapse_time);

	// write answer to file
	printArrayToFile(product_matrix_size, product_matrix, argv[3]);
	
	// free arrays
	free2Darray(matrix_one);
	free2Darray(matrix_two);
	free2Darray(product_matrix);
	return 0;
}
