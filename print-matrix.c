/*
*	Ilya Aronov
*	CSCI 310 - print-matrix.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char** argv) {
	int size;
	double** matrix;
	
	// check for arguments
	if (argc < 2) {
		fprintf(stderr, "Uknown argument: <binary input file>\n");
		exit(1);
	}

	// load array from file
	loadFile2Darray(&size, &matrix, argv[1]);
	
	// print array to screen
	print2Darray(size, size, matrix);

	// free memory
	free2Darray(matrix);

	return 0;
}
