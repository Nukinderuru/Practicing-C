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
    printf("\n");
}

void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col, int **newMatrix) {
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

float determinant(int **matrix, int m) {
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
    int **newMatrix = malloc(n * n * sizeof(int) + n * sizeof(int *));
    if (newMatrix != NULL) {
      int *ptr = (int *)(newMatrix + n);
        for (int i = 0; i < n; i++) {
            newMatrix[i] = ptr + n * i;
        }
      for (int j = 0; j < m; j++) {
        getMatrixWithoutRowAndCol(matrix, m, 0, j, newMatrix);
        d += (k * matrix[0][j] * determinant(newMatrix, n));
        k = -k;
      }
    }
    free(newMatrix);
  }
  return d;
}

int main() {
    int **matrix = NULL;
    int n = 0, m = 0;
    printf("Please enter the size of your matrix (2 integers):\n");
    if ((scanf("%d %d", &n, &m) != 2) || n < 0 || m < 0 || n != m) {
        printf("n/a");
        return 1;
    }
    matrix = malloc(n * m * sizeof(int) 
        + n * sizeof(int *));
    if (matrix != NULL) {
        int *ptr = (int *)(matrix + n);
        for (int i = 0; i < n; i++) {
            matrix[i] = ptr + m * i;
        }
        input(matrix, n, m);
        float det = determinant(matrix, n);
        printf("%.6lf\n", det);
        free(matrix);
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}
