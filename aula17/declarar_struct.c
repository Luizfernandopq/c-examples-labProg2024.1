struct pessoa_tag{
    char *nome;
    int idade;
};

struct pessoa_tag_declaracao{
    char *nome;
    int idade;
}p, p_array[10], *pPtr;

int main(){

struct pessoa_tag p1;
p1.nome = "José";
p1.idade = 10;

p.nome = "João";
p.idade = 21;

p_array[0].nome = "Maria";

p_array[2] = p;

return 0;
}
