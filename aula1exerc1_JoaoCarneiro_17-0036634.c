#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro {
  char placa[7];
  char cpf_do_dono[11];
} Carro;

typedef struct pessoa {
  char cpf[12];
  char nome[60];
  int numero_de_carros;
  Carro carros[10];
} Pessoa;

void menu_inicial();

int main(int argc, char *argv[]){

  FILE *db_carro;
  FILE *db_pessoa;
  char seletor = 'P';
  char aux;
  char aux_string[60],aux_string_1[60],aux_string_2[60];
  db_carro = fopen("banco_de_dados_carro.txt", "w");
  db_pessoa = fopen("banco_de_dados_pessoas.txt", "w");
  Carro lista_de_carros[1000];
  Pessoa lista_de_pessoas[1000];


  if(db_carro == NULL){
    printf("Erro ao abrir o arquivo de carros");
    exit(1);
  }

  if(db_pessoa == NULL){
    printf("Erro ao abrir o arquivo de pessoas");
    exit(1);
  }

  fscanf(db_carro, "%c", &aux);
  rewind(db_carro);

  if(aux == '$'){
    int cont = 0;
    while(aux != EOF){
      fscanf(db_carro, " %[^\n]", aux_string);
      strcpy(lista_de_carros[cont].placa, aux_string);
      fscanf(db_carro, " %[^\n]", aux_string);
      strcpy(lista_de_carros[cont].cpf_do_dono, aux_string);
      cont++;
      fscanf(db_carro, "%c", aux);
      fscanf(db_carro, "%c", aux);
    }
    cont = 0;
    while(aux != EOF){
      int carros = 0;
      fscanf(db_pessoa, " %[^\n]", aux_string);
      strcpy(lista_de_pessoas[cont].cpf, aux_string);
      fscanf(db_pessoa, " %[^\n]", aux_string);
      strcpy(lista_de_pessoas[cont].nome, aux_string);
      fscanf(db_pessoa, " %d", carros);
      for(int contin = 0; cont < carros; cont++){
        fscanf(db_pessoa, " %[^\n]", aux_string);
        strcpy(lista_de_pessoas[cont].carros, aux_string);
      }
      cont++;
      fscanf(db_pessoa, "%c", aux);
      fscanf(db_pessoa, "%c", aux);
    }
  }

  while(seletor != '4'){
    menu_inicial();
    scanf(" %c", &seletor);
    int contador = 0;
    ////Primeira Opção
    if (seletor == '1') {

      for(contador = 0; contador < 1000; contador++){
      }
    }

    ///Segunda Opção
    else if (seletor == '2') {


    }

    ///Terceira Opção
    else if (seletor == '3') {
      fscanf(db_pessoa, "%c", &aux);
      if(aux == EOF){
        printf("Banco de Dados Vazio. Realize uma operação de inserção.\n");
      }
      else if(aux == '$'){
        printf("---\t\t\tDigite o CPF do novo usuário (somente números): \t\t\t\t\t---\n");
        scanf(" %[^\n]", aux_string_1);
        rewind(db_pessoa);

        while(aux != EOF){
          fscanf(db_pessoa, "%c", aux);
          if(aux == '$'){
            fscanf(db_pessoa, " %[^\n]", aux_string_2);
            if(strcmp(aux_string_1, aux_string_2) == 0){
              printf("Usuário já existente\n");
            }
          }
        }
        if(aux == EOF){
          fprintf(db_pessoa, "%s", aux_string_1);

        }

      }
    }


    else {
      printf("Opção inválida!\n");
    }
  }









  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

void menu_inicial() {
  printf("\n-------------------------------------------------------------------------------------------\n");
  printf("---\t\t\tBANCO DE DADOS DE CARROS:\t\t\t\t\t---\n");
  printf("-------------------------------------------------------------------------------------------\n");
  printf("---\t\t\t(1) Consultar Carro\t\t\t\t\t---\n");
  printf("---\t\t\t(2) Consultar Usuário\t\t\t\t\t---\n");
  printf("---\t\t\t(3) Adicionar Usuário (Obrigatório Possuir Carro)\t\t\t\t\t---\n");
  printf("---\t\t\t(4) Sair\t\t\t\t\t\t\t---\n");
  printf("-------------------------------------------------------------------------------------------\n");
}

/////////////////////////////////////////////////////////////////////////////////////////
