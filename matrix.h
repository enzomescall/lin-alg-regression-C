#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free

#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    unsigned int rows;
    unsigned int cols;
    double **data;
} matrix;




#endif /* MATRIX_H */