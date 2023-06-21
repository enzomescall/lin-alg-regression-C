typedef struct matrix {
    int rows;
    int cols;
    int **data;
    char is_square;
    // matrix[ i ][ j ] = array[ i*m + j ]
} matrix;

