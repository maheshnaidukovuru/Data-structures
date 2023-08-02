#include <stdio.h>
#define R1 3
#define C1 3
#define R2 3
#define C2 3
int multiplyMatrices(int mat1[R1][C1], int mat2[R2][C2], int result[R1][C2]) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int displayMatrix(int matrix[R1][C2]) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int matrix1[R1][C1] = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}};
    int matrix2[R2][C2] = {{9, 8, 7},
                                 {6, 5, 4},
                                 {3, 2, 1}};
    int resultMatrix[R1][C2];
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    printf("Result of matrix multiplication:\n");
    displayMatrix(resultMatrix);
    return 0;
}

