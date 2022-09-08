#include <stdio.h>

int fibonacci(int n) {
    int res;
    if (n == 0) {
        res = 0;
    }
    if (n == 1 || n == 2) {
        res = 1;
    }
    int x = 1, y = 1;
    for (int i = 2; i < n; i++) {
       y = x + y;
       x = y - x;
       res = y;
    }
    return res;;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 1;
    }
    char c;
    if ((c = getchar()) != '\n') {
        printf("n/a");
        return 1;
    }
    printf("%d", fibonacci(n));
    return 0;
}
