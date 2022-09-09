#include <stdio.h>
#define N_MAX 10

int input(int *data) {
    int status = 0;
    for (int i = 0; i < N_MAX; i++) {
        status += scanf("%d", &data[i]);
    }
    if (status != N_MAX) {
        printf("n/a");
        return 1;
    }
    char c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *data) {
    for (int i = 0; i < N_MAX - 1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d", data[N_MAX - 1]);
}

void sort(int *data) {
    for (int i = 0; i < N_MAX; i++) {
        for (int j = 0; j < N_MAX - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    int data[N_MAX];
    if (input(data) != 1) {
        sort(data);
        output(data);
    }
    return 0;
}
