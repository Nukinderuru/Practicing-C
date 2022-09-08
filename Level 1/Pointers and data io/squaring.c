#include <stdio.h>
#define NMAX 10

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0) {
        printf("n/a");
        return 1;
    }
    char c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    int count = 0;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a");
            return 1;
        } else {
            count++;
        }
    }
    c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    if (count != *n) {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", a[n - 1]);
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 1) {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}
