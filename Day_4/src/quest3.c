#include <stdio.h>

int fib(int n);

int main() {
  int n;
  char str;

  if ((scanf("%d%c", &n, &str) == 2) && str == '\n') {
      printf("%d", fib(n));
      return 0;
  }
  printf("n/a");
  return 0;
}

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}
