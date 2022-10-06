#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    input(data, &n);
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

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
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
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
void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
}
int max(int *a, int n) {
    int max = *a;
    for (int i = 1; i < n; ++i) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}
int min(int *a, int n) {
    int min = *a;
    for (int i = 1; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

