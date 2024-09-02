#include <stdio.h>
#include <stdlib.h>

int main() {
    // Aloca memória para um inteiro
    int *ptr = (int*) malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

    *ptr = 42; // Usa o bloco de memória alocado
    printf("Valor: %d\n", *ptr);

    // Libera a memória alocada
    free(ptr);

    // Tentando usar de novo o local
    printf("Valor: %d\n", *ptr);
    
    return 0;
}
