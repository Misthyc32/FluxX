#ifndef FLUXX_TENSOR_H
#define FLUXX_TENSOR_H


#include <stdlib.h>
#include <stdio.h>

//tensor struct     

typedef struct 
{
    float *ftdata;
    int *ftshape;
    int  ftrank;
    int *ftstrides;
    int ftsize;


} FluxXTensor;

//Functions

FluxXTensor* create_ftensor(int *shape, int rank);
void haddamard_ftensor_product(FluxXTensor *ftensor1,FluxXTensor *ftensor2, FluxXTensor *ftensor3);
void matrix_mult(FluxXTensor *ftensor1, FluxXTensor *ftensor2, FluxXTensor *ftensor3);
void sum_ftensor(FluxXTensor *ftensor1,FluxXTensor *ftenso2, FluxXTensor *ftensor3);
void free_ftensor(FluxXTensor *ftensor);

#endif