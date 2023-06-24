#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    unsigned int rows;
    unsigned int cols;
    double **data;
} matrix;

/*
Matrix creation and destruction
Input: rows, cols as unsigned ints (legal: only positive integers)
WARNING: negative ints will wrap around to large positive ints
Output: struct with first two elements unsigned ints rows and cols, and last element a pointer to an
array of row arrays of size rows
*/ 
matrix* createMatrix(unsigned int rows, unsigned int cols);
void freeMatrix(matrix* mat);
matrix* copyMatrix(matrix* mat);

// Matrix printing
void printMatrix(matrix* mat);

// Matrix operations
matrix* addMatrices(matrix* mat1, matrix* mat2);
matrix* subtractMatrices(matrix* mat1, matrix* mat2);
matrix* multiplyMatrices(matrix* mat1, matrix* mat2);
matrix* transposeMatrix(matrix* mat);

// Vector operations

#endif /* MATRIX_H */