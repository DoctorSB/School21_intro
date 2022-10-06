#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *size);
void print(int *a, int size);
void sort(int *a, int size);
void sort_vertical(int *a, int x, int y, int maksim[x][y]);
void sort_horizontal(int *a, int x, int y, int vitek[x][y]);
void output(int y, int x, int a[y][x]);

int main() {
    int *a = NULL;
    int x, y;
    scanf("%d%d", &y, &x);
    int dlinna = x * y;
    int maksim[y][x];
    int vitek[y][x];
    a = (int*) malloc(dlinna * sizeof(int));
    if ((input(a, &dlinna) == 0) && (x != 0 && y != 0)) {
        sort(a, dlinna);
        sort_horizontal(a, x, y, vitek);
        output(y, x, vitek);
        printf("\n");
        sort_vertical(a, x, y, maksim);
        output(y, x, maksim);
    } else {
        printf("n/a");
    }
    free(a);
    return 0;
}
void sort_vertical(int *a, int x, int y, int maksim[y][x]) {
    int count = 0;
    for (int i = 0; i < y; i++) {
        if ((i + 1) % 2 !=0) {
            for (int j = 0; j < x; j++) {
                maksim[i][j] = a[count];
                count++;
            }
        } else {
            for (int j = x - 1; j >=0 ; j--) {
                maksim[i][j] = a[count];
                count++;
            }
        }
    }
}
void sort_horizontal(int *a, int x, int y, int vitek[y][x]) {
    int count = 0;
    for (int i = 0; i < x; i++) {
        if ((i + 1) % 2 !=0) {
            for (int j = 0; j < y; j++) {
                vitek[j][i] = a[count];
                count++;
            }
        } else {
            for (int j = y - 1; j >= 0 ; j--) {
                vitek[j][i] = a[count];
                count++;
            }
        }
    }
}
void sort(int *a, int dlinna) {
    int buffer;
    for (int i = 0; i < dlinna - 1; i++) {
        for (int j = i + 1; j < dlinna; j++) {
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
    int problemes = 0;
    for (int i = 0; i < *size; i++) {
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

void output(int y, int x, int a[y][x]) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (j == x - 1) {
                printf("%d", a[i][j]);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}
