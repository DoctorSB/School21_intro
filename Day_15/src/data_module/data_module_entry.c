#include <stdio.h>
#include <stdlib.h>
#include "data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"


int main() {
    double *data;
    int n;
    scanf("%d", &n);
    data = malloc(n * sizeof(double));
    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");
    free(data);
    return 0;
}
