#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    char str;
    int var = scanf("%d%c", n, &str);
    if ( *n > 0 && *n <= 10 ) {
        if (var == 2 && str == '\n') {
            for (int *p = a; p - a < *n; p++) {
                scanf("%d", p);
                }
        } else {
            printf("n/a");
            return 0;
        }
    } else {
        printf("n/a");
        return 0;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i];
    }
}


