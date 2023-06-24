#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free, your mom

#include "matrix.h"


/*
Matrix creation and destruction
Input: rows, cols as unsigned ints (legal: only positive integers)
WARNING: negative ints will wrap around to large positive ints
Output: struct with first two elements unsigned ints rows and cols, and last element a pointer to an
array of row arrays of size rows
*/ 
matrix* createMatrix(unsigned int rows, unsigned int cols) {
    if (rows == 0 || cols == 0) {
        fprintf(stderr, "Error: Invalid number of rows or columns.\n");
        return NULL;
    }

    // Assigns a pointer to the heap
    matrix* mat = (matrix*) malloc(sizeof(matrix));
    if (mat == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }

    // Initializes matrix row and col values, and a pointer to heap for (as array of row arrays)
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**) malloc(rows * sizeof(double*));
    if (mat->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(mat);
        return NULL;
    }

    for (unsigned int i = 0; i < rows; i++) {
        mat->data[i] = (double*) malloc(cols * sizeof(double));
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

    // Initialize the matrix values to 0
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }

    return mat;
}

/* 
Freeing matrix heap memory after use of matrix has finished
Input: pointer to matrix struct
Output: null
*/
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

matrix* copyMatrix(matrix* mat) {
    if (mat == NULL) {
        fprintf(stderr, "Error: Cannot copy NULL matrix.\n");
        return NULL;
    }

    unsigned int rows = mat->rows;
    unsigned int cols = mat->cols;

    matrix* result = createMatrix(rows, cols);
    if (result == NULL) {
        return NULL;
    }

    // Copy the matrix values
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            result->data[i][j] = mat->data[i][j];
        }
    }

    return result;
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

// Vector operations
double dotProduct(matrix* vec1, matrix* vec2) {
    // Check if vectors are valid
    if (vec1 == NULL || vec2 == NULL) {
        printf("Error: Invalid input vectors.\n");
        exit(1);
    }

    // Check if vectors have compatible dimensions
    if (vec1->rows != vec2->rows) {
        printf("Error: Incompatible dimensions between vectors.\n");
        exit(1);
    }

    // Check if vectors are actually vectors
    if (vec1->cols != 1 || vec2->cols != 1) {
        printf("Error: Input matrices are not vectors.\n");
        exit(1);
    }

    double result;

    // Perform dot product
    for (unsigned int i = 0; i < vec1->rows; i++) {
        result += vec1->data[i][0] * vec2->data[i][0];
    }

    return result;
}

matrix* crossProduct(matrix* vec1, matrix* vec2) {
    // Check if vectors are valid
    if (vec1 == NULL || vec2 == NULL) {
        printf("Error: Invalid input vectors.\n");
        exit(1);
    }

    // Check if vectors have compatible dimensions
    if (vec1->rows != vec2->rows) {
        printf("Error: Incompatible dimensions between vectors.\n");
        exit(1);
    }

    // Check if vectors are actually vectors
    if (vec1->cols != 1 || vec2->cols != 1) {
        printf("Error: Input matrices are not vectors.\n");
        exit(1);
    }

    unsigned int rows = vec1->rows;

    // Calculate cross product
    matrix* result = createMatrix(rows, 1);

    // unfinished
}

// Matrix and scalar operations