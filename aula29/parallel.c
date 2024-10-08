#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    long int n = INT_MAX;
    n = n >> 4;
    int *arr = malloc(sizeof(int) * n);
	if (arr == NULL){
		printf("NULL\n");
		return 1;
	}
    clock_t start, end;
    double tempo_cpu;

	start = clock();
	
	#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
	#if 0
    for (int i = 0; i < n; i++) {
            printf("%d\t", arr[i]);
   	}
	#endif

	end = clock();
	
	tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("array de tamanho %ld preenchido em %lf s\n", n, tempo_cpu);
	return 0;
}
