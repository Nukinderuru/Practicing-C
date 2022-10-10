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

void mult(int **matrix1, int **matrix2, int n1, int n2, int m2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            int sum = 0;
            for (int k = 0; k < n2; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d", sum);
            if (j != m2 - 1) {
                printf(" ");
            }
        }
        printf("\n");
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
    int n1 = 0, n2 = 0, m1 = 0, m2 = 0, operation;
    printf("Which operation would you like to implement?\n\
    1 - Addition of 2 matrices;\n\
    2 - Multiplication of 2 matrices;\n\
    3 - Transposition of a matrix.\n");
    if ((scanf("%d", &operation) != 1) || operation > 3 || operation < 0) {
        printf("n/a");
        return 1;
    }
    if (operation != 3) {
        printf("Please enter the sizes of your matrices (2 integers each):\n");
        if ((scanf("%d %d", &n1, &m1) != 2) || n1 < 0 || m1 < 0) {
            printf("n/a");
            return 1;
        }
        if ((scanf("%d %d", &n2, &m2) != 2) || n2 < 0 || m2 < 0) {
            printf("n/a");
            return 1;
        }
        matrix1 = malloc(n1 * m1 * sizeof(int) 
            + n1 * sizeof(int *));
        matrix2 = malloc(n2 * m2 * sizeof(int) 
            + n2 * sizeof(int *));
        if (matrix1 != NULL && matrix2 != NULL) {
            int *ptr1 = (int *)(matrix1 + n1);
            for (int i = 0; i < n1; i++) {
                matrix1[i] = ptr1 + m1 * i;
            }
            int *ptr2 = (int *)(matrix2 + n2);
            for (int i = 0; i < n2; i++) {
                matrix2[i] = ptr2 + m2 * i;
            }
            if (operation == 1 && (n1 != n2 || m1 != m2)) {
                printf("To add matrices they have to be equal size.\n");
                return 1;
            }
            if (operation == 2 && m1 != n2) {
                printf("To multiply matrices the first one must contain the same amount of columns as the second's amount of rows.\n");
                return 1;
            }
            int status1 = input(matrix1, n1, m1);
            int status2 = input(matrix2, n2, m2);
            if (status1 != 1 && status2 != 1) {
                if (operation == 1) {
                    add(matrix1, matrix2, n1, m1);
                } else if (operation == 2) {
                    mult(matrix1, matrix2, n1, n2, m2);
                }
            }
        } else {
            printf("n/a");
            return 1;
        }
    } else {
        printf("Please enter the size of your matrix (2 integers):\n");
        if ((scanf("%d %d", &n1, &m1) != 2) || n1 < 0 || m1 < 0) {
            printf("n/a");
            return 1;
        }
        matrix1 = malloc(n1 * m1 * sizeof(int) 
            + n1 * sizeof(int *));
        matrix2 = malloc(n1 * m1 * sizeof(int) 
            + n1 * sizeof(int *));
        if (matrix1 != NULL && matrix2 != NULL) {
            int *ptr1 = (int *)(matrix1 + n1);
            for (int i = 0; i < n1; i++) {
                matrix1[i] = ptr1 + m1 * i;
            }
            int *ptr2 = (int *)(matrix2 + n1);
            for (int i = 0; i < n1; i++) {
                matrix2[i] = ptr2 + m1 * i;
            }
            if (input(matrix1, n1, m1) != 1) {
                trans(matrix1, matrix2, n1);
            }
        } else {
            printf("n/a");
            return 1;
        }
    }
    free(matrix1);
    free(matrix2);
    return 0;
}
