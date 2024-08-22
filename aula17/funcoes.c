#include <stdio.h>
#include <string.h>

struct senha {
        char tipo[20];
        int numero;
};

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

int main(){
	struct senha cliente = gera_senha();
	imprime(cliente);

        return 0;
}
