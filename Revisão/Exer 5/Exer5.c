#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[20];
  char estilo[20];
  int integrantes;
  int ranking;
}Playlist;

//---------------------------Funções do Código----------------------------------
void PreencheBanda(Playlist banda[],int quantidade){
  for(int i=0; i<quantidade; i++){
    printf("Digite o nome da [%d] banda: ",i+1);
    setbuf(stdin,NULL);
    fgets(banda[i].nome,19,stdin);
    banda[i].nome[strcspn(banda[i].nome,"\n")]='\0';

    printf("Digite o estilo da [%d] banda: ",i+1);
    setbuf(stdin,NULL);
    fgets(banda[i].estilo,19,stdin);
    banda[i].estilo[strcspn(banda[i].estilo,"\n")]='\0';

    printf("Digite quantidade de integrantes da [%d] banda: ",i+1);
    scanf("%d",&banda[i].integrantes);

    printf("De 1 a 5, digite a posicao da [%d] banda: ",i+1);
    scanf("%d",&banda[i].ranking);
    printf("\n");
  }//for
}//PreencheBanda

void ExibeBandas(Playlist banda[], int quantidade){
  for(int i=0; i<quantidade; i++){
    printf("Banda [%s]\n Estilo [%s]\n Integrantes [%d]\n Raking [%d]\n\n",banda[i].nome,banda[i].estilo,banda[i].integrantes,banda[i].ranking);
  }//for
}//ExibeBandas

void Exibe_Pesquisa(Playlist banda[], int quantidade ,int pesquisa){
  printf("\n");
  for(int i=0; i<quantidade; i++){
    if(pesquisa==banda[i].ranking){
        printf("Banda [%s]\n Estilo [%s]\n Integrantes [%d]\n Raking [%d]\n\n",banda[i].nome,banda[i].estilo,banda[i].integrantes,banda[i].ranking);
    }//if
  }//for
}//Exibe_Pesquisa

//---------------------------Função Principal-----------------------------------
int main(int argc, const char *argv){
  //váriaveis
  Playlist banda[2];
  int pesquisa;

  //Preenchendo bandas
  PreencheBanda(banda,2);

  ExibeBandas(banda, 2);

  printf("Digite o ranking da banda que deseja procurar: ");
  scanf("%d",&pesquisa);

  Exibe_Pesquisa(banda,2,pesquisa);
  return 0;
}//main
