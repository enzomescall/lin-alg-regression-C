#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free

#include "matrix.h"


// Matrix creation and destruction
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

// Matrix printing
void printMatrix(matrix* mat) {
    if (mat == NULL) {
         fprintf(stderr, "Error: Cannot print NULL matrix.\n");
        return NULL;
    }

    printf("Matrix:\n");
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Matrix operations
matrix* addMatrices(matrix* mat1, matrix* mat2) {
    // Check if matrices are valid
    if (mat1 == NULL || mat2 == NULL) {
        return NULL;
    }

    // Check if matrices have compatible dimensions
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        return NULL;
    }

    unsigned int rows = mat1->rows;
    unsigned int cols = mat1->cols;

    // Create a new matrix to store the result
    matrix* result = createMatrix(rows, cols);
    if (result == NULL) {
        return NULL;
    }

    // Perform matrix addition
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return result;
}

matrix* subtractMatrices(matrix* mat1, matrix* mat2) {
     // Check if matrices are valid
    if (mat1 == NULL || mat2 == NULL) {
        return NULL;
    }

    // Check if matrices have compatible dimensions
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        return NULL;
    }

    unsigned int rows = mat1->rows;
    unsigned int cols = mat1->cols;

    // Create a new matrix to store the result
    matrix* result = createMatrix(rows, cols);
    if (result == NULL) {
        return NULL;
    }

    // Perform matrix subtraction
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }

    return result;
}

matrix* multiplyMatrices(matrix* mat1, matrix* mat2) {
    // Check if matrices are valid
    if (mat1 == NULL || mat2 == NULL) {
        return NULL;
    }

    // Check if matrices have compatible dimensions
    if (mat1->cols != mat2->rows) {
        return NULL;
    }

    unsigned int rows = mat1->rows;
    unsigned int cols = mat2->cols;

    // Create a new matrix to store the result
    matrix* result = createMatrix(rows, cols);
    if (result == NULL) {
        return NULL;
    }

    // Perform matrix multiplication
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            double sum = 0;
            for (unsigned int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }

    return result;
}

matrix* transposeMatrix(matrix* mat) {
    // Check if matrix is valid
    if (mat == NULL) {
        return NULL;
    }

    unsigned int rows = mat->rows;
    unsigned int cols = mat->cols;

    // Create a new matrix to store the result
    matrix* result = createMatrix(cols, rows);
    if (result == NULL) {
        return NULL;
    }

    // Perform matrix transposition
    for (unsigned int i = 0; i < cols; i++) {
        for (unsigned int j = 0; j < rows; j++) {
            result->data[i][j] = mat->data[j][i];
        }
    }

    return result;
}