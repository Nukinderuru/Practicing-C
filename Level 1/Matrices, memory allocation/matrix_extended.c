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

void find_max(int **data, int n, int m) {
    int max = 0, max_nums[n], i = 0, k = 0;
    for (i = 0; i < n; i++) {
        int j = 0;
        max = data[i][j];
        for (j = 0; j < m - 1; j++) {
            if (data[i][j + 1] > max) {
                max = data[i][j + 1];
            }
        }
        max_nums[k] = max;
        k++;
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", max_nums[i]);
    }
    printf("%d\n", max_nums[n - 1]);
}

void find_min(int **data, int n, int m) {
    int min = 0, min_nums[m], j = 0, k = 0;
    for (j = 0; j < m; j++) {
        int i = 0;
        min = data[i][j];
        for (i = 0; i < n - 1; i++) {
            if (data[i + 1][j] < min) {
                min = data[i + 1][j];
            }
        }
        min_nums[k] = min;
        k++;
    }
    for (int i = 0; i < m - 1; i++) {
        printf("%d ", min_nums[i]);
    }
    printf("%d\n", min_nums[m - 1]);
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
            find_max(data_array, n, m);
            find_min(data_array, n, m);
        }
        free(data_array);
    }
    return 0;
}
