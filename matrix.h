#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    unsigned int rows;
    unsigned int cols;
    double **data;
} matrix;

matrix* createMatrix(unsigned int rows, unsigned int cols);
void freeMatrix(matrix* mat);

#endif /* MATRIX_H */