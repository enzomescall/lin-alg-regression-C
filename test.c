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

    printf("\nTesting the dot product\n");

    matrix* vec1 = createMatrix(2, 1);
    vec1->data[1][0] = 1;
    printMatrix(vec1);
 
    matrix* vec2 = createMatrix(2, 1);
    vec2->data[0][0] = 1;
    vec2->data[1][0] = 2;
    printMatrix(vec2);

    double mag = magnitude(vec2);
    printf("Magnitude of vec2: %.2lf\n", mag);
    
    double dp = dotProduct(vec1, vec2);
    printf("Result: %.2lf\n", dp);


    return 0;
}
