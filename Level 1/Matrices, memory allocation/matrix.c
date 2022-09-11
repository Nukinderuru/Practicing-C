#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int input(int **data, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }
    return 0;
}

void output(int **data, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            printf("%d ", data[i][j]);
        }
        printf("%d", data[i][m - 1]);
        printf("\n");
    }
}

int static_matrix(int n, int m) {
    int data[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            printf("%d ", data[i][j]);
        }
        printf("%d", data[i][m - 1]);
        printf("\n");
    }
    return 0;
}

int main() {
    int way = 0;
    int *values_array = NULL, **pointer_array = NULL, **data_array = NULL;
    printf("Please choose how the memory should be allocated:\n\
    1 - Statically;\n\
    2 - Via an array of pointers to arrays of values;\n\
    3 - Via an array of pointers to different parts of an array of values;\n\
    4 - Via one array containing both pointers and values.\n");
    if (scanf("%d", &way) != 1) {
        printf("n/a");
        return 1;
    }
    printf("Now enter 2 numbers - the size of your matrix:\n");
    int n = 0, m = 0;
    if (scanf("%d %d", &n, &m) != 2 || n > MAX || n < 0 ||
        m > MAX || m < 0) {
        printf("n/a");
        return 1;
    }
    printf("And, finally, enter the elements of the matrix:\n");
    switch (way) {
        case 1:
            static_matrix(n, m);
            break;
        case 2:
            if ((pointer_array = malloc(n * sizeof(int *)))) {
                for (int i = 0; i < n; i++) {
                    pointer_array[i] = malloc(m * sizeof(int));
                }
                if (input(pointer_array, n, m) != 1) {
                    output(pointer_array, n, m);
                }
                for (int i = 0; i < n; i++) {
                    free(pointer_array[i]);
                }
                free(pointer_array);
            }
            break;
        case 3:
            if ((pointer_array = malloc(n * sizeof(int *))) &&
                (values_array = malloc(n * m * sizeof(int)))) {
                    for (int i = 0; i < n; i++) {
                        pointer_array[i] = values_array + m * i;
                    }
                    if (input(pointer_array, n, m) != 1) {
                        output(pointer_array, n, m);
                    }
                    free(values_array);
                    free(pointer_array);
                }
            break;
        case 4:
            if ((data_array = malloc(n * m * sizeof(int) + \
                n * sizeof(int *)))) {
                int *ptr = (int *)(data_array + n);
                for (int i = 0; i < n; i++) {
                    data_array[i] = ptr + m *i;
                }
                if (input(data_array, n, m) != 1) {
                    output(data_array, n, m);
                }
                free(data_array);
            }
            break;
        default:
            printf("n/a");
            return 1;
    }
    return 0;
}
