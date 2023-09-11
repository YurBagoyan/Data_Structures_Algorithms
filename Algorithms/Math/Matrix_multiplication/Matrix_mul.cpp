#include <iostream>
#include <vector>
#include <stdexcept>

using Matrix = std::vector<std::vector<int>>;

// Function to print a matrix
void printMatrix(const Matrix& matrix)
{
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[0].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
}

Matrix matrix_mul(const Matrix& A, const Matrix& B)
{
	// Check if the matrices can be multiplied
    if(A[0].size() != B.size()) {
        throw std::runtime_error("Matrices cannot be multiplied");
    }

    const int A_row_size = A.size();
    const int B_col_size = B[0].size();
    const int m = A[0].size();
  
	// Create a result matrix C initialized with zeros
    Matrix C(A_row_size, std::vector<int>(B_col_size));

	// Perform matrix multiplication
    for(int i = 0; i < A_row_size; ++i) {
        for(int j = 0; j < B_col_size; ++j) {
            for(int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main()
{
    Matrix A = {
        {1, 2, 3},
        {3, 1, 2}
    };

    Matrix B = {
        {1, 2},
        {3, 2},
        {1, 2}
    };

    Matrix C = matrix_mul(A, B);

    printMatrix(C);
}
