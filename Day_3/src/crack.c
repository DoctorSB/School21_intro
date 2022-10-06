#include <stdio.h>

float crack(int a,int b);

int main() {
    float a, b;
    if (scanf("%f %f", &a, &b) != 2){
        printf("n/a");
        return 0;
    }

    crack(a, b);
    return 0;
}

float crack(int a,int b){
    if (a * a + b * b <= 25){
        printf("GOTCHA") ;
    }
    else{
        printf("MISS");
    }
}