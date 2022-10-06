#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *size);
void print(int *a, int size);
void sort(int *a, int size);


int main() {
    int *a = NULL;
    int size;
    scanf("%d", &size);
    a = (int*) malloc(size * sizeof(int));
    if (input(a, &size) == 0) {
        sort(a, size);
        print(a, size);
    } else {
        printf("n/a");
    }
    free(a);
    return 0;
}
void print(int *a, int size) {
    for (int i = 0; i < size; i++)
    if (i == size-1) {
        printf("%d", a[i]);
    } else {
        printf("%d ", a[i]);
    }
}
void sort(int *a, int size) {
    int buffer;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                buffer = a[i];
                a[i] = a[j];
                a[j] = buffer;
            }
        }
    }
}
int input(int *a, int *size) {
    char str;
    int count = 0;
    int problemes;
    for (int i = 0; i < *size; i++) {
        count2 += 1;
        if (((scanf("%d%c", &a[i], &str)) == 2) && ((str == ' ') || (str == '\n'))) {
            count += 1;
        } else {
            if (count != *size) {
                problemes = 1;
            } else {
                problemes = 0;
            }
        }
    }
    return problemes;
}


























