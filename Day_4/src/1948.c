#include <stdio.h>
int main() {
    float a, b;
    int z = scanf("%f %f", &a, &b);
    if ( z != 0 )
        if ( (a * a + b * b) < 25){
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        } else {
            printf("n/a\n");
        }
return 0;
}