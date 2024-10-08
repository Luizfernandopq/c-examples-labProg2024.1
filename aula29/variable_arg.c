#include <stdarg.h>
#include <stdio.h>


double avg(int argc, ...){
	double total = 0.0;
	va_list lista;
	va_start(lista, argc);
	for (int i = 0; i<argc; i++){
		total += va_arg(lista, double);
	}
	va_end(lista);
	return total/argc;
}


int next(int *arr){
	static int contador = 0;
	return arr[contador++];
}


int main(){
	
	int arr[10] ={0};
	for (int i =0; i<10;i++){
		arr[i] = i;
	}
	next(arr);
	next(arr);
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));
	printf("%d\n", next(arr));

	return 0;
	
}
