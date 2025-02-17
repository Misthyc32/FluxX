#include <stdio.h>
#include "../include/fluxx_matrix.h"

// Main test function
int main() {
    int rows = 2, cols = 3;
    float A[] = {1, 2, 3, 4, 5, 6};
    float B[] = {6, 5, 4, 3, 2, 1};
    float C[6]; // Output matrix+

    // Call the function from the library
    matrix_sum_cpu(A, B, C, rows, cols);

    // Print results
    printf("Matrix A:\n");
    print_matrix(A, rows, cols);
    printf("Matrix B:\n");
    print_matrix(B, rows, cols);
    printf("Matrix Sum (C = A + B):\n");
    print_matrix(C, rows, cols);

    return 0;
}
