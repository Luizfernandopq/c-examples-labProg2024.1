#include <stdio.h>

typedef struct client{
	int contaNum;
	char Nome[15];
	char Sobrenome[15];
	double saldo;
}Cliente;

int main(){

	Cliente cliente = {0, "", "", 0.0};
	
	FILE *clients;

	if ((clients = fopen("credit.dat", "rb+" ) ) == NULL){
		printf("exit\n");
		return 10;
	} else{
		printf("Digite o número da conta: ");
		scanf( "%d", &cliente.contaNum );
		while(cliente.contaNum){
			printf("Digite o Nome, sobrenome e saldo: \n");

			fscanf(stdin, "%s%s%lf", cliente.Nome, cliente.Sobrenome, &cliente.saldo);

			//     Arquivo  |         Deslocamento            |   Posição inicial
			fseek(clients, (cliente.contaNum - 1) * sizeof(Cliente), SEEK_SET);

			//     void ptr |  tamanho Dado  | quantidade    |    Arquivo
			fwrite(&cliente, sizeof(Cliente),       1,          clients);
			printf("Digite o número da conta: ");
			scanf( "%d", &cliente.contaNum );
		}
		fclose(clients);
	}
	return 0;
}
