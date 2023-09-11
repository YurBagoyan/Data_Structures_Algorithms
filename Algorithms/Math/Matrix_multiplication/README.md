# Matrix Multiplication 

This C++ program provides a simple and efficient implementation of matrix multiplication. Matrix multiplication is a fundamental operation in linear algebra and has numerous applications in various fields, including computer graphics, scientific computing, and machine learning.

## Algorithm

Matrix multiplication, also known as the matrix product, is defined for two matrices A (of size m x n) and B (of size n x p) as the operation that produces a new matrix C (of size m x p), where each element C[i][j] is computed as the dot product of the i-th row of A and the j-th column of B.

The algorithm implemented in this program follows these steps:

Input Matrices: Define two input matrices A and B, which you want to multiply. Ensure that the number of columns in matrix A matches the number of rows in matrix B for a valid multiplication.

Matrix Initialization: Create an empty result matrix C, initially filled with zeros, of size m x p, where m is the number of rows in A, and p is the number of columns in B.

Multiplication: For each element C[i][j] in the result matrix C, calculate its value by iterating over the rows of A (k) and the columns of B (k). Sum the products of corresponding elements from A and B, i.e., C[i][j] += A[i][k] * B[k][j].

Output: The result is a new matrix C, which contains the product of matrices A and B.

