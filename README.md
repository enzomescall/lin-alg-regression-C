# lin-alg-regression-C

**Done: Linear Algebra**

1. Implement basic matrix operations:
   - Matrix addition/subtraction
   - Matrix multiplication (still need Strassen)
   - Matrix transposition
   - Scalar multiplication
   - Vector dot product

**To-Do: Linear Algebra**
0. Implement ways to add data to a matrix
   - Element-wise (sort of done, since you can just access the [i][j] row and column of matrix->data)
   - One whole column at a time
   - One whole row at a time
   - Randomly
   - From a text file

1. Implement basic matrix operations:
   - Checking equality of matrices
   - Vector cross product
   - Vector scaling
   
2. Input validation:
   - Handle memory allocation failures and report errors appropriately
   - Check for compatibility of matrix sizes in operations

3. Implement additional matrix operations:
   - Vector cross product
   - Matrix inversion
   - Row reduction
   - Determinant calculation
   - Kronecker product
   - Bilinear form
   - Quadratic form
   - Rayleigh quotient
   - Moore-Penrose inverse (pseudoinverse)
   - Matrix to some number power
   - e^matrix
   - Pfaffian

4. Implement error handling and exception handling:
   - Define error codes or exceptions for specific error scenarios
   - Provide meaningful error messages for easier debugging

5. Implement vector operations
   - Orthogonal basis from any basis input
   - Check if list of vectors is linearly independent
   - Gram matrix from a list of vectors
   - Check if list of vectors in the same (generalized) eigenspace

6. Invariants
   - Eigenvalues
   - Eigenvectors
   - Orthogonal bases for eigenspaces
   - Generalized eigenspaces
   - Singular values

7. Implement matrix factorization
   - Matrix block decomposition
   - LU
   - LRU
   - M = A^TA
   - Matrix square root (both varieties)
   - Cholesky
   - QR
   - Diagonal
   - Unitary/orthogonal diagonal
   - Polar
   - SVD
   - Schur
   - Jordan normal
   - Jordan-Chevalley
   - Rational normal
   - Smith normal
   - (Symmetric + skew-symmetric)/2

8. Implement matrix comparisons
   - Similar
   - Congruent
   - Simultaneously triangularizable
   - Simultaneously diagonalizable
   - Commutative
   - Check if symmetric, skew-symmetric, psd, positive-definite

9.  Applications
   - Matrix Eckart-Young low-rank approximation
   - Smth smth least squares
   - PCA