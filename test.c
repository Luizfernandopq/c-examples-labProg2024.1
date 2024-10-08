#include <stdio.h>
#include <stdarg.h>
#define N2

int combine1(int size, int *arr){
	int a = 1;
	for(int i = 0; i<size; i++){
		a += 0.5*arr[i];
	}
	return size*a;
}

int combine2(int count, ...){
	va_list args;
	va_start(args, count);
	int a = 1;
	for(int i = 0; i<count; i++){
		a += va_arg(args, int);
	}
	va_end(args);
	return count*a;
}

int main() {

		int arr[] = {2, 3, 2, 1};
		int size = 4;

		#ifndef N22
			size = 2;
		#endif
		
		int a = combine1(size, arr);
		#ifndef N2
			size = 3;
		#endif
		int b = combine2(size, 2, 3, 4, 1);
		printf("%2d %2d\n", size, b);
		return 0;
}
