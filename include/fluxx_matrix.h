#ifndef FLUXX_MATRIX_H
#define FLUXX_MATRIX_H
#include <stdlib.h>

//Matrix Sum
void matrix_sum_cpu(float *A, float *B, float*C, int rows, int cols);

void print_matrix(float* M, int rows, int cols);
#endif  // FLUXX_MATRIX_H