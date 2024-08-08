#include <stdio.h>

int soma(int a, int b){
    return a+b;
}

int subtrai(int a, int b){
    return a-b;
}

int (*escolhe_funcao(int x))(int, int){
    if (x){
        return soma;  
    } else{
        return subtrai;
    }
}

int main(){
  int (*func)(int, int) = escolhe_funcao(0);
  int resultado = (*func)(10, 5);
  printf("%d\n", resultado);
  }
