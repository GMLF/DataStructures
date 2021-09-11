#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Fila Dinâmica - 06/09/21
@Guilherme Moreira.
Revisão Monitória ED 1
*/

//---------------------------Renomeando NoFila----------------------------------
typedef struct NoFila *PtrNoFila;

//-------------------------Struct Fila Dinâmica---------------------------------
typedef struct NoFila{
  int elemento;           // elemento inserido nos nó de fila
  PtrNoFila proximo;     // ponteiro para o próximo nó de fila
}NoFila;

typedef struct{
  PtrNoFila inicio;   // ponteiro pro primeiro elemento
  PtrNoFila fim;     // ponteiro pro ultimo elemento
  int contador;     //quantidade de elementos inseridos
}FilaDinamica;

//------------------------Funções Fila Dinâmica---------------------------------
void IniciaFilaD(FilaDinamica *fila){
  fila->inicio=NULL;      //inicia o ponteiro inicio em NULL, fila vazia
  fila->fim=NULL;        //inicia o ponteiro fim em NULL, fila vazia
  fila->contador=0;     //inicia o contadore em zero pois não
}//IniciaFilaD

bool VaziaFilaD(FilaDinamica *fila){
  return(fila->inicio==NULL); // retorna falso se o inicio não for igual a NULL
}//VaziaFilaD

int TamanhoFilaD(FilaDinamica *fila){
  return(fila->contador);   //retorna o tamanho do contador
}//TamanhoFilaD

void VerificaStatus(FilaDinamica *fila){
  if(VaziaFilaD(fila)){
    printf("A fila dinamica esta vazia\n");
  }else{
    printf("A fila nao esta vazia\n");
  }//else
}//VerificaStatus

void InsereFilaD(FilaDinamica *fila, int elemento){
  //Acontece nas duas situações
  PtrNoFila auxiliar;
  auxiliar=(PtrNoFila)malloc(sizeof(NoFila));
  //copiando o elemento para o nó de fila inserido
  auxiliar->elemento=elemento;

    //Primeira Inserção
    if(VaziaFilaD(fila)){
      fila->inicio= auxiliar; //ponteiro de inicio aponta para o novo nó
      fila->fim= auxiliar;    //ponteiro do fim aponta para o novo nó
      auxiliar->proximo=NULL; //próximo do novo nó aponta para NULL
    }else{
      //Não é a primeira inserção
      auxiliar->proximo= fila->fim->proximo;  //proximo do novo nó, aponta para o próximo do fim
      fila->fim->proximo=auxiliar;            // o próximo do fim aponta para o elemento inserido
      fila->fim=fila->fim->proximo;           //o Fim aponta para o próximo do fim
    }//else
    fila->contador++;                         //incrementa o contador
}//InsereFilaD

void ExibeFilaD(FilaDinamica *fila){
  printf("\nFila Dinamica {");            //printf estético
  PtrNoFila percorre;                     //ponteiro auxiliar

    for(percorre=fila->inicio; percorre!= NULL; percorre=percorre->proximo){  //ponteiro auxiliar recebe o inicio e roda enquanto for diferente de NULL
      printf("%d ",percorre->elemento); //exibe o elemento do nó
    }//for
  printf("}\n");                        //printf estético
}//ExibeFilaD

int RemoveFilaD(FilaDinamica *fila){
  int removido;                        //váriavel auxiliar que armazena o elemento removido
  PtrNoFila auxiliar;                  //nó auxiliar para cópiar o conteúdo do inicio

  if(!VaziaFilaD(fila)){
    auxiliar=fila->inicio;              //auxiliar recebe o nó do inicio
    removido=auxiliar->elemento;        //recebe o elemento do nó do inicio p/retornar p main
    fila->inicio=fila->inicio->proximo; //o inicio aponta para o próximo do inicio
    free(auxiliar);                     //liberando a memória do nó removido
    fila->contador--;                   //decrementa a quantidade de elementos inseridos
  }else{
    printf("A fila dinamica esta vazia\n");
  }//else

 return removido;                      //retorna o elemento removido
}//RemoveFilaD

void PrimeiroFilaD(FilaDinamica *fila){
  PtrNoFila auxiliar;       //ponteiro auxiliar
  auxiliar=fila->inicio;    //ponteiro auxiliar aponta pro nó do inicio
  printf("O elemento do inicio [%d]\n",auxiliar->elemento);  //exibindo o elemento do nó copiado
}//PrimeiroFilaD

void UltimoFilaD(FilaDinamica *fila){
  PtrNoFila auxiliar;                 //ponteiro auxiliar
  auxiliar=fila->fim;                 //ponteiro auxiliar aponta para o nó do fim
  printf("O ultimo elemento [%d]\n",auxiliar->elemento);     //exibindo o elemento do nó copiado
}//UltimoFilaD

void DestroiFilaD(FilaDinamica *fila){
  printf("\nFila Dinamica Destruida\n");  //printf estético
  PtrNoFila destroi;                      //ponteiro auxiliar para destruir

    while(fila->inicio!=NULL){            //while rodando enquanto incio for diferente de NULL
      destroi=fila->inicio;               //ponteiro auxiliar recebe o nó do inicio
      fila->inicio=fila->inicio->proximo; //faz o inicio apontar para o próximo do inicio
      free(destroi);                      //desaloca o espaço de memória do ponteiro auxiliar
      fila->contador--;                   //decrementa a qtd de elementos da fila dinâmica
    }//while
}//DestroiFilaD

//------------------------Função Principal Main---------------------------------
int main(int argc, const char *argv[]){
    //Váriaveis
    int removido;
    FilaDinamica fd;

      //Iniciando Fila Dinâmica
      IniciaFilaD(&fd);

      //Verificando vazia ou cheia
      VerificaStatus(&fd);

      //Tamanho da Fila Dinâmica
      printf("Tamanho da fila Dinamica [%d]\n",TamanhoFilaD(&fd));

      //Inserido Elementos na Fila Dinâmica
      InsereFilaD(&fd,5);
      InsereFilaD(&fd,7);
      InsereFilaD(&fd,9);
      InsereFilaD(&fd,13);

      //Exibe Fila Dinâmica
      ExibeFilaD(&fd);

      //Exibindo Primeiro elemento da fila dinâmica
      PrimeiroFilaD(&fd);

      //Exibindo o Ultimo elemento da fila dinâmica
      UltimoFilaD(&fd);

      removido=RemoveFilaD(&fd);
      printf("\nElemento Removido [%d]\n",removido);

      //Exibe Fila Dinâmica
      ExibeFilaD(&fd);

      //Destroi Fila Dinâmica
      DestroiFilaD(&fd);

  return 0;
}//Main
