#include <stdio.h> 
#include <math.h> 
#include "matrix.h"

int main() {
    
    matrix* mat = createMatrix(6, 3);

    // populate matrix
    for (unsigned int i = 0; i < mat->rows; i++) {
        for (unsigned int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = i + j;
        }
    }

    matrix* mat2 = createMatrix(6, 3);
    
    // populate matrix
    for (unsigned int i = 0; i < mat2->rows; i++) {
        for (unsigned int j = 0; j < mat2->cols; j++) {
            mat2->data[i][j] = i * j + 1;
        } 
    }

    matrix* mat3 = transposeMatrix(mat2);
    matrix* mat4 = multiplyMatrices(mat, mat3);
    matrix* test = multiplyMatrices(mat, mat2);

    printMatrix(mat);

    printf("mat4 rows: %d\n", mat4->rows);
    matrix* mat5 = multiplyMatrixByScalar(mat, 2);

    printMatrix(mat5);

    return 0;
}
