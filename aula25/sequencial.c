#include <stdio.h>

int main(){
	int account; /* número da conta */
	char name[ 30 ]; /* nome da conta */
	double balance; /* saldo da conta */	

	FILE *clients;
	if ( ( clients = fopen( "clients.dat", "w" ) ) == NULL ) {
		printf( "Arquivo não pode ser aberto\n" );
	}
	else {
		printf( "Digite o número de conta, o nome e o saldo.\n" );
		printf( "Digite fim de arquivo para terminar a entrada.\n" );
		printf( "? " );
		scanf( "%d%s%lf", &account, name, &balance );
		while ( !feof( stdin ) ) {
			fprintf( clients, "%d %s %.2f\n", account, name, balance );
			printf( "? " );
			scanf( "%d%s%lf", &account, name, &balance );
		} /* fim do while */
		fclose( clients ); /* fclose fecha arquivo */
	} 

	return 0;
	
}
