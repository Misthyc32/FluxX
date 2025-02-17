#include "fluxx_matrix.h"
#include <stdlib.h>
#include <stdio.h>

void matrix_sum_cpu(float *A,float *B, float *C, int rows, int cols){
    int SIZE = rows * cols;
    for (int i = 0; i<SIZE; i++){
        C[i] =  A[i] + B[i];
     }

}
// 
void print_matrix(float* M, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", M[i * cols + j]);
        }
        printf("\n");
    }
}