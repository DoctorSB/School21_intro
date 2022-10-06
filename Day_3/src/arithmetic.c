#include <stdio.h>

int main()
{   
    int a, b;
    if (scanf("%d %d", &a, &b) != 2){
        printf("n/a");
        return 0;
    }
    printf("%d %d %d ", a + b, a - b, a * b);
    if (b == 0){
        printf("n/a");
    }
    else{
        printf("%d", a / b);
    }
    return 0;
}