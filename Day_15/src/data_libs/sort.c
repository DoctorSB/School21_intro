#include "data_stat.h"

void sort(double *data, int n) {
    double buffer;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                buffer = data[i];
                data[i] = data[j];
                data[j] = buffer;
            }
        }
    }
}

