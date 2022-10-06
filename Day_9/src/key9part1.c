/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input (int *buffer, int *length);
void print (int *B, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int* numbers);

/*------------------------------------
    Функция получает массив данных
    через stdin.
    Выдает в stdout особую сумму
    и сформированный массив
    специальных элементов
    (выбранных с помощью найденной суммы):
    это и будет частью ключа
-------------------------------------*/
int main()
{
    int length = 0;
    int A[NMAX];
    int B[NMAX];
    if(input(A, &length) == 0) {
        int x = sum_numbers(A, length);
        int dlinna =  find_numbers(A, length, x, B);
        printf("%d\n", x);
        print(B, length);
    } else{
        printf("n/a");
    }
    return 0;
}

/*------------------------------------
    Функция должна находить
    сумму четных элементов
    с 0-й позиции.
-------------------------------------*/
int input(int *buffer, int *length) {
    char str;
    int count = 0;
    if((scanf("%d%c", length, &str)) == 2 && str == '\n') {
    }
    else{
        return 1;
    }
    for (int i = 0; i <= *length; i++) {
        count += 1;
        if (((scanf("%d%c", buffer, &str)) == 2) && (str == ' ')) {
            buffer++;
            continue;
        } else {
            if(count != *length) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int* i = buffer; i - buffer < length; i++) {
        if (*i % 2 == 0) {
            sum += *i;
        }
    }
    return sum;
}

/*------------------------------------
    Функция должна находить
    все элементы, на которые нацело
    делится переданное число и
    записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers)
{   *numbers = 0;
    int count = 0;
    for (int i = 0; i <= length; i++) {
        if(buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[i] = buffer[i];
            count++;
        } else{
            numbers[i] = 0;
        }
    }
    return count;
}
void print(int *B, int dlinna) {
    for (int i = 0; i < dlinna; i++) {
        if (B[i] != 0)
            printf("%d ", B[i]);
    }
}
