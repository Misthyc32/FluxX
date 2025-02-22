#include "../include/fluxx_tensor.h"
//Function which creates the cpu ftensor 
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
    //Allocate memory for the total size of the tensor 
    ftensor->ftsize =(int*)malloc(sizeof(int));
    if (!ftensor->ftsize){
        printf("Memory allocatiin failed for the ftensor ftsize.\n");
        free(ftensor->ftsize);
        free(ftensor);
    }
    int total_size=1;
    for (int i=0; i<rank;i++){
        total_size *= shape[i];    
    }
    ftensor->ftsize = total_size;

    //Allocate the memory on the heap for the 1D array redimension 
    ftensor->ftdata = (float*)malloc(total_size * sizeof(float));
    if (!ftensor->ftdata){
        printf("Memory allocatin failed for ftensor ftdata.\n");
        free(ftensor->ftshape);
        free(ftensor->ftsize);
        free(ftensor);
        return NULL;
    }

    //Allocate and calculate the strides
    ftensor->ftstrides = (int*)malloc(rank * sizeof(int));
    if (!ftensor->ftrank){
        printf("Memory allocation failed for ftensor ftstride.\n");
        free(ftensor->ftdata);
        free(ftensor->ftshape);
        free(ftensor->ftsize);
        free(ftensor);
        return NULL;
    }
    int stride = 1;
    for (int i=rank - 1; i>=0; i--){
        ftensor->ftstrides[i] = stride;
        stride *= shape[i];
    }
    return ftensor;
}

//Function which allows the haddamard product of two cpu ftensor
void haddamard_ftensor_product(FluxXTensor *ftensor1,FluxXTensor *ftensor2, FluxXTensor *result){
    //Check same ranks ftensor
    if ((ftensor1->ftrank) != (ftensor2->ftrank) ||  (ftensor1->ftrank) != (result->ftrank)){
        printf("Cannot perform haddamard product ftranks are not equal.\n");
        return NULL;
    }


    //Check same shapes ftensor
    for (int i=0; i< ftensor1->ftrank; i++){
        if ((ftensor1->ftshape[i])!= (ftensor2->ftshape[i]) || (ftensor1->ftshape[i]) != (result->ftshape[i])){
            printf("Cannot perform haddamard product ftshape are not equal.\n");
            return NULL;
        }   
    }
    
    //Performe the Haddamard Product
    for (int i=0; i<(ftensor1->ftsize); i++){
        result->ftdata[i] = ftensor1->ftdata[i] * ftensor2->ftdata[i];
    }
}

void sum_ftensor(FluxXTensor *ftensor1, FluxXTensor *ftensor2, FluxXTensor *result){
    //Check same ranks ftensor
    if ((ftensor1->ftrank) != (ftensor2->ftrank) ||  (ftensor1->ftrank) != (result->ftrank)){
        printf("Cannot perform sum ftranks are not equal.\n");
        return NULL;
    }

    //Check same shapes ftensor
    for (int i=0; i< ftensor1->ftrank; i++){
        if ((ftensor1->ftshape[i])!= (ftensor2->ftshape[i]) || (ftensor1->ftshape[i]) != (result->ftshape[i])){
            printf("Cannot perform sum ftshape are not equal.\n");
            return NULL;
        }   
    }
       
    //Sum the ftensor
    for (int i=0; i<(ftensor1->ftsize); i++){
        result->ftdata[i] = ftensor1->ftdata[i] + ftensor1->ftdata[i]; 
    }
}