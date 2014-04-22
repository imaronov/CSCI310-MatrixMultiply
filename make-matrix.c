/*
*	Ilya Aronov
*	CSCI 310 - make-matrix.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "functions.h"

int main(int argc, char** argv) {
	// variables from argument list
	int c;
	int size_of_matrix = 0;
	double lower_bound = 0;
	double upper_bound = 0;
	char* output_file = "";
	
	// variables for matrix
	double** matrix;

	// check for the number of arguments passed	
	if(argc < 9) {
		fprintf(stderr, "Not enough arguments.\nRequired:\n-n <size of matrix>\n-l <lower bound for matrix>\n-u <upper bound for matrix>\n-o <output file to be written>\n");
		exit(1);
	}

	// get the values from the arguments
	while((c = getopt(argc, argv, "n:l:u:o:")) != -1) {
		switch(c) {
			case 'n':
				size_of_matrix = atof(optarg);
				break;
			case 'l':
				lower_bound = atof(optarg);
				break;
			case 'u':
				upper_bound = atof(optarg);
				break;
			case 'o':
				output_file = optarg;
				break;
			default:
				fprintf(stderr, "invalid argument. \n");
		}
	}
	
	// allocate array
	alloc2Darray(size_of_matrix, size_of_matrix, &matrix);

	// fill up array
	load2Darray(lower_bound, upper_bound, size_of_matrix, matrix);
	
	// print to file
	printArrayToFile(size_of_matrix, matrix, output_file);	

	// free array
	free2Darray(matrix);
	
	return 0;
}

