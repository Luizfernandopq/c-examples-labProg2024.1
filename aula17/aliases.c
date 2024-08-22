#include <stdio.h>
#include <string.h>

typedef struct senha {
        char tipo[20];
        int numero;
}Senha;

Senha gera_senha();

void imprime(Senha cliente);

int main(){
        Senha cliente = gera_senha();
        imprime(cliente);

        return 0;
}

struct senha gera_senha(){
        static int senha = 0;
        char *atendimento[2] = {"Prioridade", "Normal"};
        struct senha cliente;
        strcpy(cliente.tipo, atendimento[senha%2]);
        cliente.numero = senha++;
        return cliente;
}

void imprime(struct senha cliente){
        printf("Senha: %s %d\n", cliente.tipo, cliente.numero);
}
