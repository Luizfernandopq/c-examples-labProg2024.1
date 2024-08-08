#include <stdio.h>

void apply(int (*function)(int), int x){
    printf("função apply at %p chamando %p\n", &apply, &function);
    function(x);
}

int imprime(int x){
    printf("%d\n", x);
    return 0;
}
int dobra(int y){
    printf("%d\n", y*2);
    return 0;
}

int main(){
    apply(dobra, 10);
    return 0;
}
