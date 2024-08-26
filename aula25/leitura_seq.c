#include <stdio.h>

int main(){
	int account; /* número da conta */
	char name[ 30 ]; /* nome da conta */
	double balance; /* saldo da conta */	

	FILE *clients;
	if ( ( clients = fopen( "clients.dat", "r" ) ) == NULL ) {
		printf( "Arquivo não pode ser aberto\n" );
	}
	else {
		printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
		fscanf( clients, "%d%s%lf", &account, name, &balance );
		while ( !feof( clients ) ) {
			printf( "%-10d%-13s%7.2f\n", account, name, balance );
			fscanf( clients, "%d%s%lf", &account, name, &balance );
		} /* fim do while */
		fclose( clients );
	}
	

	return 0;
	
}
