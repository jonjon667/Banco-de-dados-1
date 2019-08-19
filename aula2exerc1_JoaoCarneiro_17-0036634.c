#include <stdio.h>
#include <stdlib.h>

struct carro{
    char modelo[20];
    char marca[20];
    char renavam[11];
    char cor[10];
    char cpfDoProprietario[11];
};

struct proprietario{
    char nome[20];
    char cpf[11];
    char data_nascimento[8];
};


void abreCarro(FILE** arq){
    *arq = fopen("carros.txt", "a");
}
void abreProp(FILE** arq){
    *arq = fopen("proprietario.txt", "a");
}

int main(void){
    struct proprietario p1;
    struct carro c;
    int qntdDeCarros;
    FILE* arq = NULL;
    int i = 0;

    abreProp(&arq);
  
    printf("Insira o nome do proprietário\n");
    scanf("%s",p1.nome);
    printf("Insira o CPF do proprietário\n");
    scanf("%s",p1.cpf);
    printf("Insira a data de nascimento do proprietário\n");
    scanf("%s",p1.data_nascimento);
    printf("Insira a quantidade de carros do proprietário\n");
    scanf("%d",&qntdDeCarros);
    fprintf(arq, "Nome: %s\n CPF: %s\n Nasc: %s\n", p1.nome, p1.cpf, p1.data_nascimento);
    fclose(arq);
    abreCarro(&arq);
    for(i=0; i< qntdDeCarros; i++){
        printf("Cadastre o %d carro do proprietário\n",i+1);
        printf("Insira a cor do carro %d\n",i+1);
        scanf("%s",c.cor);
        printf("Insira a marca do carro %d\n",i+1);
        scanf("%s",c.marca);
        printf("Insira o modelo do carro %d\n",i+1);
        scanf("%s",c.modelo);
        printf("Insira o renavam do carro %d\n",i+1);
        scanf("%s",c.renavam);
        fprintf(arq, "Carro nº:%d\n Cor:%s\n Marca:%s\n Modelo:%s\n Renavam:%s \n CPF do proprietario:%s \n\n", i, c.cor, c.marca, c.modelo, c.renavam, p1.cpf);
    }
    fclose(arq);
    printf("Dados salvos no arquivo com sucesso!\n");

    fclose(arq);

    return 0;
}