#include <stdio.h>
#include <string.h>

typedef struct pessoa{
        char *nome;
        struct pessoa *proximo;
}Pessoa;

void imprimePessoas(Pessoa p){
	Pessoa *pessoa = &p;
	while(pessoa->proximo != NULL){
		printf("%s\n", pessoa->nome);
		pessoa = pessoa->proximo;
	}
	printf("%s\n", pessoa->nome);
}

int main(){
	Pessoa p1 = {"Fulano"};
	Pessoa p2 = {"Matheus"};
	p1.proximo = &p2;

	Pessoa p3 = {"Maria"};
	p2.proximo = &p3;

	Pessoa p4 = {"Ana"};
	p3.proximo = &p4;

	imprimePessoas(p1);
	return 0;
}

