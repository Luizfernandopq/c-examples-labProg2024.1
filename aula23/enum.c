#include <stdio.h>

enum months {JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ };

int main( void ){
	enum months month; 

 	const char *monthName[] = { "", "Janeiro", "Fevereiro", "Marco",
 								"Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro",
 								"Novembro", "Dezembro" };

 	for ( month = JAN; month <= DEZ; month++ ) {
 			printf( "%2d %15s\n", month, monthName[ month ] );
	} 
	return 0;
}
