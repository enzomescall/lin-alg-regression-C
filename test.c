#include <stdio.h> 
#include "matrix.h"

int main() {
    unsigned int rows = 3;
    unsigned int cols = 3;

    // Create a matrix
    matrix* mat = createMatrix(rows, cols);
    if (mat == NULL) {
        printf("Matrix creation failed.\n");
        return 1;
    }

    // Set the matrix values
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            mat->data[i][j] = i * cols + j;
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            printf("%.2f ", mat->data[i][j]);
        }
        printf("\n");
    }

    // Free the matrix memory
    freeMatrix(mat);

    return 0;
}
