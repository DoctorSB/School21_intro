#include <stdio.h>

int max(int a,int b);

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2){
        printf("n/a");
        return 0;
    }
    printf("%d", max(a, b));
    return 0;
}

int max(int a,int b){
    if(a > b){
        return a;
    }
    else if(a < b){
        return b;
    }
    else{
        return a;
    }
}