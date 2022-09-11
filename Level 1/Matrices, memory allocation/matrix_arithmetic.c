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

void add(int **matrix1, int **matrix2, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = matrix1[i][j] + matrix2[i][j];
            printf("%d", sum);
            if (j != m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void mult(int **matrix1, int **matrix2, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d\n", sum);
        }
    }
}

void trans(int **matrix1, int **matrix2, int n) {
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix2[i][j] = matrix1[j][i];
            printf("%d", matrix2[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
		}
        printf("\n");
	}
}

int main() {
    int **matrix1 = NULL, **matrix2 = NULL;
    int n = 0, m = 0, operation;
    printf("Which operation would you like to implement?\n\
    1 - Addition of 2 matrices;\n\
    2 - Multiplication of 2 matrices;\n\
    3 - Transosition of a matrix.\n");
    if ((scanf("%d", &operation) != 1) || operation > 3 || operation < 0) {
        printf("n/a");
        return 1;
    }
    printf("Please enter the size of your matrices (2 integers):\n");
    if ((scanf("%d %d", &n, &m) != 2) || n < 0 || m < 0 || n != m) {
        printf("n/a");
        return 1;
    }
    matrix1 = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
    matrix2 = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
    if (matrix1 != NULL && matrix2 != NULL) {
        int *ptr1 = (int *)(matrix1 + n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix1[i] = ptr1 + m * i * sizeof(int);
        }
        int *ptr2 = (int *)(matrix2 + n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix2[i] = ptr2 + m * i * sizeof(int);
        }
        if (operation == 1 || operation == 2) {
            int status1 = input(matrix1, n, m);
            int status2 = input(matrix2, n, m);
            if (status1 != 1 && status2 != 1) {
                if (operation == 1) {
                    add(matrix1, matrix2, n, m);
                } else if (operation == 2) {
                    mult(matrix1, matrix2, n, m);
                }
            }
        } else if (operation == 3) {
            if (input(matrix1, n, m) != 1) {
                trans(matrix1, matrix2, n);
            }
        }
        free(matrix1);
        free(matrix2);
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}
