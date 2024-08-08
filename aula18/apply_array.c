#include <stdio.h>

void apply(int * const arr, int (*function)(int), int size){
    for(int i=0; i<size; i++){
        arr[i] = function(arr[i]);
    }
}

int imprime(int x){
    printf("%d\t", x);
    return x;
}

int dobra(int x){
    return x*2;
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6};
    
    //apply(array, imprime, 6);
    //printf("\n");
    
    apply(array, dobra, 6);
    
    apply(array, imprime, 6);
    printf("\n");
    return 0;
}
