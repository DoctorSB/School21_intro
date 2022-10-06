#include <stdio.h>
#include <math.h>

float formula(float x);

int main() {
    float x;
    if (scanf("%f", &x) != 1){
        printf("n/a");
        return 0;
    }
    printf("%.1f", formula(x));
    return 0;
}

float formula(float x){
    return 7 * pow(10, -3) * pow(x,4) + ((22.8 * pow(x, -3) - 1 * pow(10, 3)) * x + 3) / (x * x / 2) - x * pow((10 + x),(2/x)) - 1.01;
}