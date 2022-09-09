#include <stdio.h>
#define N_MAX 10

int input(int *data, int *n, int *shift) {
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
    for (int i = 0; i < N_MAX; i++) {
        status += scanf("%d", &data[i]);
    }
    if (status != N_MAX) {
        printf("n/a");
        return 1;
    }
    c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    if (scanf("%d", shift) != 1 || shift > n) {
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

void output(int *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d", data[n - 1]);
}

void shift_left(int *data, int n, int shift) {
    int temp[shift];
    for (int i = 0; i < shift; i++) {
        temp[i] = data[i];
    }
    for (int i = 0; i < n - shift; i++) {
        data[i] = data[i + shift];
    }
    for (int i = n - shift; i < n; i++) {
        data[i] = temp[i - n + shift];
    }
}

void shift_right(int *data, int n, int shift) {
    int j = 0, temp[shift], temp2[n - shift];
    for (int i = n - shift; i < n; i++) {
        temp[i - n + shift] = data[i];
        j++;
    }
    for (int i = 0; i < n - shift; i++) {
        temp2[i] = data[i];
    }
    for (int i = shift; i < n; i++) {
        data[i] = temp2[i - shift];
    }
    for (int i = 0; i < shift; i++) {
        data[i] = temp[i];
    }
}

int main() {
    int n, c, data[N_MAX];
    if (input(data, &n, &c) != 1) {
        if (c < 0) {
            c = -c;
            shift_right(data, n, c);
        } else {
            shift_left(data, n, c);
        }
        output(data, n);
    }
    return 0;
}
