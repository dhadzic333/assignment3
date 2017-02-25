#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAXWIDTH 16 

void printArray(int a[][MAXWIDTH], int numRows, int numCols) {
	for(int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			printf("a[%d][%d]=%d", i, j, a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int numRows = 3;
	int numCols = 2;
	int a[3][MAXWIDTH] = {{1,2}, {3,4}, {5,6}};
	// first dimension is lost information because of decaying. Have to pass the number of rows in.
	printArray(a, numRows, numCols);
	
	int **c = malloc(numRows * sizeof(void*));
	for (int i = 0; i < numRows; i++) {
		c[i] = malloc(numCols * sizeof(int));
	}
	
	// dynamic allocation
	int (*b)[MAXWIDTH] = malloc(numRows*sizeof(int[MAXWIDTH]));
	memcpy(b, a, numRows*sizeof(int[MAXWIDTH]));
	for (int i = 0; i < numRows; i++) {
		memcpy(b[i], a[i], sizeof(int[MAXWIDTH]));
	}
	
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			b[i][j] = a[i][j];
		}
	}
	printArray(b, numRows, numCols);
	
	// free b because of valgrind - memory would be wasted (error) otherwise.
	if (b) free(b);

	return 0;
}
