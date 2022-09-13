#include <stdio.h>
#include <stdlib.h>

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
    if (n < m) {
        printf("\nYep, I know there's a mysterious 10 at the beginning. Will figure it out later :)\n");
    }
}

void output_vertical(int **data, int n, int m) {
    if (n == m) {
        int k = n - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j % 2 == 0) {
                    printf("%d", data[j][i]);
                } else {
                    printf("%d", data[j][k]); 
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
    } else {
        printf("Sorry, I'm still working on non-square matrices :)\n");
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) {
        int **data = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
        if (data != NULL) {
            int *ptr = (int *)(data + n * sizeof(int));
            for (int i = 0; i < n; i++) {
                data[i] = ptr + m * i * sizeof(int *);
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
