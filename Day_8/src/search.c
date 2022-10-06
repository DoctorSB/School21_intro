#include <stdio.h>
#define NMAX 10

int tru(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int input(int *a, int *n);
void output(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    output(data, n);
    return 0;
}
int input(int *a, int *n) {
    char str;
    if ((scanf("%d%c", n, &str) == 2 && *n <= NMAX && *n > 0 && str == '\n')) {
            for (int *i = a; i - a < *n; i++) {
                if ( (scanf("%d%c", i, &str)) == 2 ) {
                    continue;
                }  else {
                    printf("n/a");
                    return 0;
                    }
                }
    } else {
        printf("n/a");
        return 0;
    }
    return 0;
}
void output(int *a, int n) {
        printf("%d ", tru(a, n));
}
double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}
double variance(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ((a[i] - mean(a, n)) * (a[i] - mean(a, n))) / n;
    }
    return sum;
}
int tru(int *a, int n) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean(a, n) && a[i] <=
            mean(a, n) + 3 * (variance(a, n) * variance(a, n)) && a[i] != 0) {
            answer = a[i];
        }
    }
    return answer;
}
