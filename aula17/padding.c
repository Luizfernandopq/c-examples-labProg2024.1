#include <stdio.h>

struct pessoa{
    char letra_inicial;
    int idade;
};
int main(){
    struct pessoa p1;
    p1.letra_inicial = 'L';
    p1.idade = 30;
    printf("%ld\n", sizeof(p1));
}
