#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Pilha Estática - 06/09/21
@Guilherme Moreira.
Revisão Monitória ED 1
*/

#define TAM 6

//----------------------------Struct Pilha Estática-----------------------------
typedef struct{
  int vetor[TAM];
  int topo;
  int contador;
}PilhaEstatica;

//----------------------------Funções Pilha Estática----------------------------
void InicializaPilhaEstatica(PilhaEstatica *p){
  //fazendo com que o indice do vetor, aponte para a primeira posição do vetor
  p->topo=0;
  //iniciando o contador em 0 para não armazenar lixo
  p->contador=0;
}//InicializaPilhaEstatica

bool EstaVaziaPilhaEstatica(PilhaEstatica *p){
  //retorna verdadeiro ou falso, se o topo for 0 não foi inserido elementos.
  return(p->topo==0);
}//EstaVaziaPilhaEstatica

bool EstaCheiaPilhaEstatica(PilhaEstatica *p){
  //retorna verdadeiro ou falso, se o topo for igual ao tamanho a pilha está cheia
  return(p->topo==TAM);
}//EstaCheiaPilhaEstatica

void VerificaStatus(PilhaEstatica *p){
  if(EstaCheiaPilhaEstatica(p)){
    printf("A pilha esta cheia\n");
  }else if(EstaVaziaPilhaEstatica(p)){
    printf("A pilha esta vazia\n");
  }//else if
}//VerificaStatus

int TamanhoPilhaEstatica(PilhaEstatica *p){
  return(p->contador);
}//TamanhoPilhaEstatica

void InserePilhaEstatica(PilhaEstatica *p, int x){
  if(!EstaCheiaPilhaEstatica(p)){ // o exclamação representa uma negação, se a pilha não estiver cheia, faça o que está dentro do if
    p->vetor[p->topo]= x; //o número é inserido no vetor na posição em que o topo aponta
    p->topo++;            // o topo aponta para próxima posição livre
    p->contador++;        //incrementa a quantidade de elementos inseridos
  }else{
    printf("A pilha esta cheia, impossivel inserir\n");
    }
}//InserePilhaEstatica

void ImprimePilhaEstatica(PilhaEstatica *p){
  printf("Pilha = {");
    for(int i=0;i<p->vetor[p->topo-1];i++){
      printf("%d ",p->vetor[i]);
    }//for
    printf("}\n");
}//ImprimePilhaEstatica

int RemovePilhaEstatica(PilhaEstatica *p){
  int aux=-999;   //iniciando uma váriavel para receber o elemento removido e retornar para main
    if(!EstaVaziaPilhaEstatica(p)){
      aux=p->vetor[p->topo-1]; //Auxiliar recebe o ultimo elemento
      p->topo--;               //decrementa o topo, para voltar para a próxima posição
      p->contador--;           //decrementa a quantidade de elemento
    }else{
      printf("A pilha esta vazia\n");
    }
    return aux;               //retornando o último elemento da pilha estatica
}//RemovePilhaEstatica

void TopoPilhaEstatica(PilhaEstatica *p){
  int aux=-99;
    aux=p->vetor[p->topo-1];
    printf("O ultimo elemento [%d]\n",aux);
}//TopoPilhaEstatica

//----------------------------Função Principal Main-----------------------------
int main(int argc,const char *argv[]){
    //váriaveis
    int res;
    PilhaEstatica Pe;

      //Iniciando Pilha Estática
      InicializaPilhaEstatica(&Pe);

      //Verificando status, vazia ou cheia
      VerificaStatus(&Pe);

      //Tamanho da pilha, quantidade de elementos inseridos
      printf("Tamanho da pilha [%d]\n",TamanhoPilhaEstatica(&Pe));

      //for rodando para inserir 4 elementos
      for(int i=1;i<=TAM;i++){
        //Função insere elementos, rodando 4 vezes para inserir números
        InserePilhaEstatica(&Pe,i);
      }//for

      //Imprimindo Pilha Estatica
      ImprimePilhaEstatica(&Pe);

      //Removendo elemento da Pilha Estatica
      res=RemovePilhaEstatica(&Pe);

      //Exibindo o ultimo elemento inserido
      TopoPilhaEstatica(&Pe);
  return 0;
}//main
