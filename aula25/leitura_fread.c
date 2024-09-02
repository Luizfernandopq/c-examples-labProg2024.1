#include <stdio.h>

typedef struct client{
	int contaNum;
	char Nome[15];
	char Sobrenome[15];
	double saldo;
}Cliente;

int main(){

	FILE *clients;
	Cliente client = {0, "", "" , 0.0};
	if ( ( clients = fopen( "credit.dat", "rb" ) ) == NULL ) {
		printf( "Arquivo não pode ser aberto\n" );
	}
	else {
		printf( "%-22s%-15s%s\n", "Account", "Name", "Balance" );
		while ( !feof( clients ) ) {
			fread( &client, sizeof(Cliente), 1, clients);
			printf( "%-5d%16s %-16s%.2f\n", client.contaNum, client.Nome, client.Sobrenome, client.saldo );
			
		} /* fim do while */
		fclose( clients );
	}
	

	return 0;
	
}
