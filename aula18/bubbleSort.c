#include <stdio.h>

void swap(int *numPtr1, int *numPtr2){
    int temp = *numPtr1;
    *numPtr1 = *numPtr2;
    *numPtr2 = temp;
}

void bubbleSort(int * const array,
                int (*compare)(int, int),
                const int size
                ){
    for(int passada = 0; passada < size - 1; passada++){
        for (int index = 0; index < size - 1; index++){
            if(compare(array[index], array[index+1])){
                swap(&array[index], &array[index+1]);
            }
        }
    }
}

int crescente(int x, int y){
    return x>y;
}

int decrescente(int x, int y){
    return x<y;
}

void apply(int * const arr, int (*function)(int), int size){
    for(int i=0; i<size; i++){
        arr[i] = function(arr[i]);
    }
}

int imprime(int x){
    printf("%d\t", x);
    return x;
}


int main(void){
    int array[] = {4, 2, 5, 7, 10, 6, 1};
    int size = sizeof(array) / sizeof(int);
    
    apply(array, imprime, size);
    printf("\n");
    
    bubbleSort(array, decrescente, size);
    
    apply(array, imprime, size);
    printf("\n");
    return 0; 
}

