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


} FluxXTensor;

//Functions

FluxXTensor* create_ftensor(int *shape, int rank);
void hadamard_product(FluxXTensor *ftensor1,FluxXTensor *ftensor2, FluxXTensor *ftensor3);
void free_ftensor(FluxXTensor *ftensor);

#endif