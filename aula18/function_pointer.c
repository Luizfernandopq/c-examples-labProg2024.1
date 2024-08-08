#include <stdio.h>

int imprime(int x){
    printf("%d\n", x);
    return 0;
}

int main(){
    int (*fPtr)(int);
    fPtr = imprime;
    fPtr(15);
    return 0;
}
