#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int alloc(int ***a, int n, int m);
void delete(int **a, int n);
int sum_nei(int **a, int i, int j);
void draw(int **a, int **b, int n, int m);
void get_lives(int **a, int **b, int n, int m);
int check_life(int **a, int **b, int i, int j, int life);
void init(int **a, int n, int m);
int kbhit();
char input_button(double *c);
void menu();
char input(int **matrix, int n, int m);
char game(int **matrix, int **lives, int n, int m);
void start(int **matrix, int **lives, int n, int m);

int main() {
    system("stty -icanon");
    int **matrix, **lives, n = 27, m = 82;
    if (alloc(&matrix, n, m) && alloc(&lives, n, m)) {
        start(matrix, lives, n, m);
        delete(lives, n);
        delete(matrix, n);
    } else {
        printf("n/a");
    }
    return 0;
}

void menu() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Выбор сценария\n");
    printf("Чтобы выбрать сценарий 'Ружье' нажмите - [1]\n");
    printf("Чтобы выбрать сценарий 'Устойчивые фигуры' нажмите - [2]\n");
    printf("Чтобы выбрать сценарий 'Альпинист' нажмите - [3]\n");
    printf("Чтобы выбрать сценарий 'Поезд' нажмите - [4]\n");
    printf("Чтобы выбрать сценарий 'Движжение вперед' нажмите - [5]\n");
    printf("Чтобы войти в инициализацию через stdin нажмите [6]\n");
    printf("\n");
    printf("Повышение скорости - [W]\n");
    printf("Понижение скорости - [S]\n");
    printf("Для возвращения в меню - [M]\n");
    printf("Для выхода из игры - [Q]\n");
    printf("\n");
}

void start(int **matrix, int **lives, int n, int m) {
    menu();
    if (input(matrix, n, m) != 'q') {
        char flag = game(matrix, lives, n, m);
        if (flag == 'm') {
            start(matrix, lives, n, m);
        } else if (flag == 'q') {
            printf("Игра завершена");
        }
    } else {
        system("clear");
        printf("Игра завершена");
    }
}

char game(int **matrix, int **lives, int n, int m) {
    char flag;
    double count = 2;
    while (1) {
        flag = input_button(&count);
        if (flag == 'q' || flag == 'm') {
            break;
        } else {
            init(matrix, n, m);
            get_lives(matrix, lives, n, m);
            draw(matrix, lives, n, m);
            usleep(10000 * count);
            printf("\033c");
        }
    }
    return flag;
}

char input_button(double *c) {
    char but = '0';
    if (kbhit()) {
        but = getc(stdin);
        if (but == 'w' && * c > 0.1) {
                *c /= 2;
        } else if (but == 's' && *c < 15) {
                *c *= 2;
        }
    }
    return but;
}

char input(int **matrix, int n, int m) {
    char *T, t = '0';
    while (t != '1' && t != '2' && t != '3' &&
           t != '4' && t != '5' && t != '6' && t != 'q') {
            scanf("%c", &t);
            if (t == '1') {
                T = "gun.txt";
            } else if (t == '2') {
                T = "stable.txt";
            } else if (t == '3') {
                T = "climber.txt";
            } else if (t == '4') {
                T = "train.txt";
            } else if (t == '5') {
                T = "coperhead.txt";
            } else if (t == '6') {
              for (int i = 1; i < n - 1; i++) {
                  for (int j = 1; j < m - 1; j++)
                      scanf("%d", &matrix[i][j]);
                }
            }
            if (t == '1' || t == '2' ||
                t == '3' || t == '4' ||
                t == '5') {
                FILE *fp;
                fp = fopen(T, "r");
                for (int i = 1; i < n - 1; i++) {
                    for (int j = 1; j < m - 1; j++) {
                        fscanf(fp, "%d", &matrix[i][j]);
                    }
                }
            }
        }
        return t;
}

int kbhit() {
  struct timeval tv;
  fd_set rdfs;

  tv.tv_sec = 0;
  tv.tv_usec = 0;

  FD_ZERO(&rdfs);
  FD_SET(STDIN_FILENO, &rdfs);

  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);
}

void draw(int **a, int **b, int n, int m) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
                if (a[i][j] == 1) {
                    printf("@");
                } else {
                    printf(" ");
                }
                check_life(a, b, i, j, a[i][j]);
        }
        printf("\n");
    }
}

int alloc(int ***a, int n, int m) {
    int check = 0;
    int *ptr = malloc(1);
    if (ptr != NULL) {
        *a = (int**)calloc(n, sizeof(int*));
        for (int i = 0; i < n; i++)
            (*a)[i] = (int*)calloc(m, sizeof(int*));
        check = 1;
    } else {
        check = 0;
    }
    free(ptr);
    return check;
}

void delete(int **a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

void init(int **a, int n, int m) {
    a[0][0] = 1;
    a[0][m - 1] = 1;
    a[n - 1][m - 1] = 1;
    a[n - 1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                a[i][j] = a[n - 2][j];
            } else if (i == n - 1) {
                a[i][j] = a[1][j];
            } else if (j == 0) {
                a[i][j] = a[i][m - 2];
            } else if (j == m - 1) {
                a[i][j] = a[i][1];
            }
        }
    }
}

int sum_nei(int **a, int i, int j) {
    return a[i + 1][j + 1] + a[i + 1][j] + a[i][j + 1]
        + a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1]
        + a[i + 1][j - 1] + a[i - 1][j + 1];
}

void get_lives(int **a, int **b, int n, int m) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            b[i][j] = sum_nei(a, i, j);
        }
    }
}

int check_life(int **a, int **b, int i, int j, int life) {
    if ((life == 0 && b[i][j] == 3) ||
        (life == 1 && (b[i][j] == 2 || b[i][j] == 3)))
        a[i][j] = 1;
    else
        a[i][j] = 0;
    return a[i][j];
}

