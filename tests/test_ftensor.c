#include "../include/fluxx_tensor.h"

void print_ftensor(FluxXTensor *ftensor) {
    if (!ftensor) {
        printf("Tensor is NULL.\n");
        return;
    }

    int rows = ftensor->ftshape[0];  // Número de filas
    int cols = ftensor->ftshape[1];  // Número de columnas (solo válido para rank 2)

    printf("FluxXTensor (%d x %d):\n", rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * ftensor->ftstrides[0] + j * ftensor->ftstrides[1];
            printf("%f ", ftensor->ftdata[index]);
        }
        printf("\n");  // Salto de línea por cada fila
    }
    printf("\n");
}

int main() {
    int shape[2] = {3, 2};  // 2x3 tensor
    FluxXTensor *ftensor = create_ftensor(shape, 2);

    ftensor->ftdata[0] = 1.0;
    ftensor->ftdata[1] = 2.0;
    ftensor->ftdata[2] = 3.0;
    ftensor->ftdata[3] = 4.0;
    ftensor->ftdata[4] = 5.0;
    ftensor->ftdata[5] = 6.0;

    FluxXTensor *ftensor1 = create_ftensor(shape, 2);

    ftensor1->ftdata[0] = 1.0;
    ftensor1->ftdata[1] = 2.0;
    ftensor1->ftdata[2] = 3.0;
    ftensor1->ftdata[3] = 4.0;
    ftensor1->ftdata[4] = 5.0;
    ftensor1->ftdata[5] = 6.0;

    FluxXTensor *ftensor2 = create_ftensor(shape, 2);

    ftensor2->ftdata[0] = 0.0;
    ftensor2->ftdata[1] = 0.0;
    ftensor2->ftdata[2] = 0.0;
    ftensor2->ftdata[3] = 0.0;
    ftensor2->ftdata[4] = 0.0;
    ftensor2->ftdata[5] = 0.0; 

    haddamard_ftensor_product(ftensor,ftensor1,ftensor2);
    printf("Resulting Tensor:\n");
    print_ftensor(ftensor2);

    sum_ftensor(ftensor,ftensor1,ftensor2);
    printf("Resulting Tensor:\n");
    print_ftensor(ftensor2);

    //free_ftensor(ftensor);
    return 0;
}   