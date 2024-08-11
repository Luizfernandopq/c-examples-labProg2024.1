#include <stdio.h>

struct senha {
	char tipo[20];
	int numero;
}senha;

int main(){

	struct senha cliente1 = {"prioridade", 10};
	struct senha cliente2 = {"normal", 11};

	printf("Senha: %s %d\n", cliente1.tipo, cliente2.numero);

}
