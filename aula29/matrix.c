#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 3 // Dimensão das matrizes (N x N)

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

	clock_t start, end;
	double tempo_cpu;
	
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[N][N] = {0};

    start = clock();
	
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
	end = clock();
		
	tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("matmul em %lf s\n", tempo_cpu);

    printf("Matriz A:\n");
    print_matrix(A);
    printf("Matriz B:\n");
    print_matrix(B);
    printf("Matriz C (resultado):\n");
    print_matrix(C);

	
	
    return 0;
}
