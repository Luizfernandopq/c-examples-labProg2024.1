#include <stdio.h>
#include <string.h>

struct senha {
	char tipo[20];
	int numero;
};

int main(){

	struct senha cliente1 = {"prioridade", 10};
	struct senha cliente2 = {"normal", 11};

	printf("Senha: %s %d\n", cliente1.tipo, cliente2.numero);

	struct senha cliente3;
	strcpy(cliente3.tipo, "prioridade");
	cliente3.numero = 12;
	return 0;
}
