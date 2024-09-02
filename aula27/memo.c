#include <stdio.h>
#include <stdlib.h>



int main(){
	int *array;
	array = malloc(10 * sizeof(int));
	for (int i = 0; i<10; i++)
		printf("%d\n", array[i]);
	
	free(array);

	for (int i = 0; i<10; i++)
	printf("%d\n", array[i]);	
	
	return 0;	
}
