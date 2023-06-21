#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    unsigned int rows;
    unsigned int cols;
    double **data;
} matrix;

// Matrix creation and destruction
matrix* createMatrix(unsigned int rows, unsigned int cols);
void freeMatrix(matrix* mat);

// Matrix operations
matrix* addMatrices(matrix* mat1, matrix* mat2);
matrix* subtractMatrices(matrix* mat1, matrix* mat2);
matrix* multiplyMatrices(matrix* mat1, matrix* mat2);
matrix* transposeMatrix(matrix* mat);

// Matrix printing
void printMatrix(matrix* mat);

#endif /* MATRIX_H */