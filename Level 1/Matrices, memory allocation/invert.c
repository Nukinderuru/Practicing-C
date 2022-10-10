#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input(double **data, int n, int m) {
    printf("Now enter the elements of your matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &data[i][j]) != 1) {
                printf("n/a");
                return 1;
            }
        }
    }
    return 0;
}

void output(double **data, int n, int m) {
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        printf("%lf", data[i][j]);
        if (j < m - 1) {
            printf(" ");
        }
    }
    if (i < n - 1)
        printf("\n");
    }
    printf("\n");
}

void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix) {
    int offsetRow = 0;
    int offsetCol = 0;
    for(int i = 0; i < size - 1; i++) {
        if(i == row) {
            offsetRow = 1;
        }
        offsetCol = 0;
        for(int j = 0; j < size - 1; j++) {
            if(j == col) {
                offsetCol = 1;
            }
            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}

float determinant(double **matrix, int m) {
    int k = 1, n = m - 1;
    float d;
    if (m < 1) {
        printf("n/a");
        return 1;
    } else if (m == 1) {
        d = matrix[0][0];
    } else if (m == 2) {
        d = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
    } else {
        double **newMatrix = malloc(n * n * sizeof(double) + n * sizeof(double *));
        if (newMatrix != NULL) {
            double *ptr = (double *)(newMatrix + n);
                for (int i = 0; i < n; i++) {
                    newMatrix[i] = ptr + n * i;
                }
            for (int j = 0; j < m; j++) {
                getMatrixWithoutRowAndCol(matrix, m, 0, j, newMatrix);
                d += (k * matrix[0][j] * determinant(newMatrix, n));
                k = -k;
            }
        } else {
            printf("n/a");
            return 1;
        }
        free(newMatrix);
    }
    return d;
}

void transpose(double **matrix, int n, float det) {
    double b[n][n];
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = matrix[j][i] / det;
            printf("%lf", b[i][j]);
            if (j != n - 1) {
                printf(" ");
            }
		}
        printf("\n");
	}
}

void cofactor(double **matrix, double **new_matrix, int size, float det) {
    int p, q, m, n, i, j;
    double **newMatrix = malloc(size * size * sizeof(double) + size * sizeof(double *));
        if (newMatrix != NULL) {
            double *ptr = (double *)(newMatrix + size);
                for (int i = 0; i < size; i++) {
                    newMatrix[i] = ptr + size * i;
                }
            for (q = 0; q < size; q++) {
                for (p = 0;p < size; p++) {
                    m = 0;
                    n = 0;
                    for (i = 0; i < size; i++) {
                        for (j = 0;j < size; j++) {
                            if (i != q && j != p) {
                                newMatrix[m][n] = matrix[i][j];
                                if (n < (size - 2)) {
                                    n++;
                                } else {
                                    n = 0;
                                    m++;
                                }
                            }
                        }
                    }
                    new_matrix[q][p] = pow(-1, q + p) * determinant(newMatrix, size - 1);
                }
            }
        }
    transpose(new_matrix, size, det);
    free(newMatrix);
}

int main() {
    double **matrix = NULL, **invert_matrix = NULL;
    int n = 0, m = 0;
    printf("Please enter the size of your matrix (2 integers):\n");
    if ((scanf("%d %d", &n, &m) != 2) || n < 0 || m < 0 || n != m) {
        printf("n/a");
        return 1;
    }
    matrix = malloc(n * m * sizeof(double) 
        + n * sizeof(double *));
    invert_matrix = malloc(n * m * sizeof(double) 
        + n * sizeof(double *));
    if (matrix != NULL && invert_matrix != NULL) {
        double *ptr = (double *)(matrix + n);
        for (int i = 0; i < n; i++) {
            matrix[i] = ptr + m * i;
        }
        double *ptr_inv = (double *)(invert_matrix + n);
        for (int i = 0; i < n; i++) {
            invert_matrix[i] = ptr_inv + m * i;
        }
        input(matrix, n, m);
        float det = determinant(matrix, n);
        if (det == 0) {
            printf("There is no invert matrix possible.\n");
            return 1;
        } else {
            cofactor(matrix, invert_matrix, n, det);
        }
        free(matrix);
        free(invert_matrix);
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}
