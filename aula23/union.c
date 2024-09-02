#include <stdio.h>

union numero {
	int x;
	double y;
};

int main(){

	union numero value;

	printf("size: %ld\n", sizeof(value));


// 	value.x = 100;
// 	printf("value.x=100\n");
// 	printf("x: %d \ny: %f\n", value.x, value.y);
// 
// 	value.y = 100.0;
// 	printf("value.y=100.0\n");
// 	printf("x: %d \ny: %f\n", value.x, value.y);	
// 	return 0;
}

