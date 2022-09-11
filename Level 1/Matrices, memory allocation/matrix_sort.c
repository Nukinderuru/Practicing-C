#include <stdio.h>
#include <stdlib.h>

int input(int **data, int n, int m) {
    printf("Now enter the elements of your matrix:\n");
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

int sum(int *row, int size) {
    int s = 0;
    for (size--; size >= 0; size--) s += row[size];
    return s;
}

void output(int **data, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (sum(data[i], n) < sum(data[j], m)) {
                for (int k = 0; k < 4; k++) {
                    int tmp = data[i][k];
                    data[i][k] = data[j][k];
                    data[j][k] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

}

int main() {
    int **data_array = NULL;
    int n = 0, m = 0;
    printf("Please enter the size of your matrix (2 integers):\n");
    if (scanf("%d %d", &n, &m) != 2 || n < 0 || m < 0) {
        printf("n/a");
        return 1;
    }
    data_array = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
    if (data_array != NULL) {
        int *ptr = (int *)(data_array + n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            data_array[i] = ptr + m * i * sizeof(int);
        }
        if (input(data_array, n, m) != 1) {
            output(data_array, n, m);
        }
        free(data_array);
    }
    return 0;
}
