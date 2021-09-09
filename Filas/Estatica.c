#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Fila Estática - 06/09/21
@Guilherme Moreira.
Revisão Monitória ED 1
*/

//--------------------------Estrutura Fila Estática ----------------------------
//tamanho do vetor definido pelo programador
#define TAM 3

typedef struct{
  int vetor[TAM]; //vetor com o tamanho que o usuáro definiu
  int contador;   //contador, armazena qtd de elementos inseridos
  int inicio;     //aponta pro primeiro elemento que entrou na Fila
  int fim;        //aponta pro último elemento a entrar na fila
}FilaEstatica;

//-------------------------Funções Fila Estática--------------------------------
void IniciaFilaE(FilaEstatica *f){
    //iniciando  a fila na posição 0 do vetor, pois nenhum elemento foi inserido
    f->inicio=0;
    //inicio o fim em -1, pois nenhum elemento foi inserido e após a inserção o elemento ocupará a posição 0 do inicio
    f->fim=-1;
    //iniciando o contador em 0 pois nenhum elemento foi inserido
    f->contador=0;
}//IniciaFilaE

bool VaziaFilaE(FilaEstatica *f){
  return(f->contador==0); //retorna verdadeiro ou falso, se a pilha está vazia
}//VaziaFilaE

bool CheiaFilaE(FilaEstatica *f){
  return(f->contador==TAM);  //retorna verdadeiro ou falso, se a fila está cheia
}//CheiaFilaE

void VerificaStatusFilaE(FilaEstatica *f){
  if(VaziaFilaE(f)){
    printf("A fila estatica esta vazia\n");
  }else{
    printf("A fila estatica nao esta vazia\n");
  }//else
}//VerificaStatusFilaE

int TamanhoFilaE(FilaEstatica *f){
  return(f->contador);  //retorna o tamanho do contador, qtd de elementos inseridos
}//TamanhoFilaE

int BufferCircular(int i){
  int buffer = (i+1) % TAM; //buffer circular, se estourou o limite e tem espaços livres, resetando o indice pra zero
  return(buffer);           //retorna o buffer resetado
}//BufferCircular

void InsereFilaE(FilaEstatica *f, int elemento){
  if(!CheiaFilaE(f)){
    //Verifica se estourou o vetor e tem posições livre e reseta pra zero
    f->fim=BufferCircular(f->fim);
    //o elemento inserido sempre será o ultimo elemento, por isso a inserção dele na posição do fim
    f->vetor[f->fim]=elemento;
    //incrementando a quantidade de elementos
    f->contador++;
  }else{
    printf("A fila esta cheia\n");
  }//else
}//InsereFilaE

void ExibeFilaE(FilaEstatica *f){
  //Printf estético
  printf("\nFila Estatica {");

  //váriaveis auxiliares
  int tamanho=TamanhoFilaE(f);  //recebe o tamanho da função que retorna o contador

  //roda enquanto o inicio não chegar ao fim, buffer circular
    for(int i=0; i<tamanho; i++){
        int indice = (f->inicio + i) % TAM;
       //exibe o elemento na posição i do vetoer
      printf("%d ",f->vetor[indice]);
    }//for

  //Printf estético
  printf("}\n\n");
}//ExibeFilaE

int RemoveFilaE(FilaEstatica *f){
  int removido=-999;//váriavel que irá armazenar o número removido p/retornar p/main

    if(!VaziaFilaE(f)){
        removido=f->vetor[f->inicio];         //recebe o elemento que está na posição do inicio
        f->inicio=BufferCircular(f->inicio);  //Verifica se estourou o começo do vetor e tem posições livre e reseta pra zero
        f->contador--;                        //decrementa a qtd de elementos pois foi removido 1
    }else{
      printf("Erro ao tentar remover, a fila esta vazia\n");
    }//else
  return(removido);               //retorna o elemento removido da fial estatica
}//RemoveFilaE

//-------------------------Função Principal Main--------------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int removido;
  FilaEstatica fe;

    //Inicia Fila Estática
    IniciaFilaE(&fe);

    //VerificaStatus
    VerificaStatusFilaE(&fe);

    printf("Tamanho da Fila Estatica [%d]\n",TamanhoFilaE(&fe));

    InsereFilaE(&fe, 10);
    InsereFilaE(&fe, 3);
    InsereFilaE(&fe, 15);

    ExibeFilaE(&fe);

    removido=RemoveFilaE(&fe);
    printf("Elemento Removido [%d]\n",removido);
    ExibeFilaE(&fe);

    printf("Novo elemento inserido, testando buffer circular");
    InsereFilaE(&fe, 7);
    ExibeFilaE(&fe);

 return 0;
}//Main
