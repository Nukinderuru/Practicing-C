#include <stdio.h>
#include <stdlib.h>

int input(int **data, int n, int m) {
    printf("Now enter yout matrix:\n");
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
    for (int j = 0; j < m; j++) {
        printf("%d", data[i][j]);
        if (j < m - 1) {
            printf(" ");
        }
    }
    if (i < n - 1)
        printf("\n");
    }
}

void output_horizontal(int **data, int n, int m) {
    for (int i = 0; i < n; i++) {
        int k = m - 1;
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0) {
                printf("%d", data[i][j]);
            } else {
                printf("%d", data[i][k]);
                k--;
            }
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

void output_vertical(int **data, int n, int m) {
    int **new_matrix = malloc(n * m * sizeof(int) 
    + n * sizeof(int *));
    if (new_matrix != NULL) {
        int *new_ptr = (int *)(new_matrix + n);
        for (int i = 0; i < n; i++) {
            new_matrix[i] = new_ptr + m * i;
        }
        int count = 0, i = 0, j = 0;
        while (count != n * m) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    new_matrix[i][j] = data[k][l];
                    count++;
                    if (j % 2 == 0) {
                        if (i == n - 1) {
                            j++;
                        } else {
                            i++;
                        }
                    } else {
                        if (i == 0) {
                            j++;
                        } else {
                            i--;
                        }
                    }
                }
            }
        }
        output(new_matrix, n, m);
        if (new_matrix != NULL) {
            free(new_matrix);
        }
    }
}

int main() {
    int n, m;
    printf("Enter the size of your matrix (2 integers):\n");
    if (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        int **data = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
        if (data != NULL) {
            int *ptr = (int *)(data + n);
            for (int i = 0; i < n; i++) {
                data[i] = ptr + m * i;
            }
            if (input(data, n, m) != 1) {
                printf("\n");
                output_horizontal(data, n, m);                
                printf("\n\n");
                output_vertical(data, n, m);
            }
            free(data);
        }
    } else {
        printf("n/a");
    }
}
