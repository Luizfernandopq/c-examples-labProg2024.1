#include <stdio.h>
typedef struct client{
	int contaNum;
	char Nome[15];
	char Sobrenome[15];
	double saldo;
}Cliente;

int main(){

	Cliente clienteVazio = {0, "", "", 0.0};
	FILE *arquivoAleat;
	if ((arquivoAleat = fopen("credit.dat", "wb" ) ) == NULL){
		printf("exit\n");
		return 10;
	} else{
		for(int i=0;i<100;i++){
			fwrite(&clienteVazio, sizeof(Cliente), 1, arquivoAleat);
		}
		fclose(arquivoAleat);
		printf("Criado arquivo com %ld bytes\n", 100 * sizeof(Cliente));
	}
	return 0;
}
