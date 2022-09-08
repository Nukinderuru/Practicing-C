#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        return 1;
    }
    char c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    int status = 0;
    for (int i = 0; i < *n; i++) {
        status += scanf("%d", &a[i]);
    }
    if (status != *n) {
        printf("n/a");
        return 1;
    }
    c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output_result(int search_v) {
    printf("%d", search_v);
}

double mean(int *a, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean = mean + (double)a[i] / n;
    }
    return mean;
}

double variance(int *a, int n) {
    double mean_square = 0;
    for (int i = 0; i < n; i++) {
        mean_square = mean_square + (double)a[i] * (double)a[i] / n;
    }
    double var = mean_square - (mean(a, n) * mean(a, n));
    return var;
}

int search(int *a, int n) {
    int res = 0;
    double var = variance(a, n);
    double var_sqrt = sqrt(var);
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 == 0) && (a[i] >= mean(a, n)) &&
        (a[i] <= mean(a, n) + 3 * var_sqrt) && (a[i] != 0)) {
            res = a[i];
            break;
        } else {
            res = 0;
        }
    }
    return res;
}

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 1) {
        mean(data, n);
        variance(data, n);
        output_result(search(data, n));
    }
    return 0;
}
