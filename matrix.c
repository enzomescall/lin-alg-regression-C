#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free

#include "matrix.h"

matrix* createMatrix(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        fprintf(stderr, "Error: Invalid number of rows or columns.\n");
        return NULL;
    }

    matrix* mat = (matrix*)malloc(sizeof(matrix));
    if (mat == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**)malloc(rows * sizeof(double *));
    if (mat->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(mat);
        return NULL;
    }

    for (unsigned int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
        if (mat->data[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            // Free previously allocated memory
            for (unsigned int j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }

    return mat;
}

void freeMatrix(matrix* mat) {
    if (mat == NULL) {
        return;
    }

    for (unsigned int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}