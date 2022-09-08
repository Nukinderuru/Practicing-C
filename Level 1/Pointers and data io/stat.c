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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                    printf("\n%d %d %.6lf %.6lf", \
                    max_v, min_v, mean_v, variance_v);
                   }

int max(int *a, int n) {
    int max = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(int *a, int n) {
    double mean = 0;
    for (int *p = a; p - a < n; p++) {
        mean += (double)*p / n;
    }
    return mean;
}

double variance(int *a, int n) {
    double mean_square = 0;
    for (int *p = a; p - a < n; p++) {
        mean_square += (double)*p * (double)*p / n;
    }
    double var = mean_square - (mean(a, n) * mean(a, n));
    return var;
}

int main() {
    int n, data[NMAX];
    if ((input(data, &n)) == 0) {
        output(data, n);
        output_result(max(data, n),
                      min(data, n),
                      mean(data, n),
                      variance(data, n));
    }
    return 0;
}
