#include "../include/fluxx_tensor.h"

FluxXTensor* create_ftensor(int *shape, int rank){
    //Allocate the memory for the struct
    FluxXTensor *ftensor = (FluxXTensor*)malloc(sizeof(FluxXTensor)); 
    if (!ftensor){
        printf("Memory allocation failed for ftensor struct .\n");
        return NULL;
    }


    //store rank
    ftensor->ftrank = rank;

    //Allocate memory for the shape array and copy its values
    ftensor->ftshape = (int*)malloc(rank * sizeof(int));
    if (!ftensor->ftshape){
        printf("Memory allocation failed for ftensor ftshape.\n");
        free(ftensor);
        return NULL;
    }


    for (int i=0; i < rank; i++){
        ftensor->ftshape[i] = shape[i];    
    }
    //Total size of the tensor 

    int total_size=1;
    for (int i=0; i<rank;i++){
        total_size *= shape[i];    
    }

    //Allocate the memory on the heap for the 1D array redimension 
    ftensor->ftdata = (float*)malloc(total_size * sizeof(float));
    if (!ftensor->ftdata){
        printf("Memory allocatin failed for ftensor ftdata.\n");
        free(ftensor->ftshape);
        free(ftensor);
        return NULL;
    }

    //Allocate and calculate the strides
    ftensor->ftstrides = (int*)malloc(rank * sizeof(int));
    if (!ftensor->ftrank){
        printf("Memory allocation failed for ftensor ftstride.\n"),
        free(ftensor->ftdata);
        free(ftensor->ftshape);
        free(ftensor);
        return NULL;
    }
    int stride = 1;
    for (int i=rank - 1; i>=0; i--){
        ftensor->ftstrides[i] = stride;
        stride += shape[i];
    }
    return ftensor;
}