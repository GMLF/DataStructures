#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Pilha Dinâmica- 06/09/21
@Guilherme Moreira.
Revisão Monitória ED 1
*/

//--------------------------------Renomeando NoPilha----------------------------
typedef struct NoPilha *PtrNoPilha; //Renomeando através da definição do Ziviani

//------------------------------Struct Pilha Dinâmica---------------------------
typedef struct NoPilha{
  int elemento;       //elemento que será inserido e armazenado no nó
  PtrNoPilha proximo; //Ponteiro que aponta para o próximo no de pilha
}NoPilha;

typedef struct{
  PtrNoPilha topo;  //topo, elemento mais recente inserido na pilha
  int contador;     //contador, contabiliza a quantidade de elementos inseridos na pilha
}PilhaDinamica;

//-------------------------------Funções Pilha Dinâmica-------------------------
void IniciaDinamica(PilhaDinamica *p){
  p->topo=NULL;     //topo aponta para o NULL pois nenhum elemento foi inserido
  p->contador=0;    //contador inicia em zero pois nenhum elemento foi inserido
}//IniciaDinamica

bool VaziaDinamica(PilhaDinamica *p){
  return(p->topo==NULL); //Retorna verdadeiro ou falso
}//VaziaDinamica

int TamanhoDinamica(PilhaDinamica *p){
  return(p->contador);  //Retorna o tamanho, quantidade de elementos inseridos
}//TamanhoDinamica

void VerificaStatus(PilhaDinamica *p){
  if(VaziaDinamica(p)){
    printf("A pilha esta vazia\n");
  }else{
    printf("Existem elementos na pilha\n");
  }//else
}//VerificaStatus

void InsereDinamica(PilhaDinamica *p, int elemento){
  //Ponteiro NoPilha auxiliar, alocando memória do nó a ser inserido
  PtrNoPilha auxiliar=(PtrNoPilha)malloc(sizeof(NoPilha));;
  //o nó recebe o elemento inserido
  auxiliar->elemento=elemento;
  //o próximo do nó aponta para onde o topo aponta
  auxiliar->proximo=p->topo;
  //O topo aponta para o nó inserido
  p->topo=auxiliar;
  //Incrementa a quantidade de elementos inseridos
  p->contador++;
}//InsereDinamica

void ImprimeDinamica(PilhaDinamica *p){ //função do tipo void pois não precisa de retorno
  //printf para estética
  printf("Pilha Dinamica {");
  //Ponteiro auxiliar pois o for irá percorrer entre os ponteiros
  PtrNoPilha ptr;
    //o ponteiro recebe o ponteiro topo, inicio da pilha e roda enquanto for diferente de NULL
    for(ptr=p->topo; ptr!=NULL; ptr=ptr->proximo){
      //exibe os elementos de cada Nó de pilha
      printf("%d ",ptr->elemento);
    }//for
    //Printf para estética
    printf("}\n");
}//ImprimeDinamica

int RemoveDinamica(PilhaDinamica *p){
  //váriavei que irá retornar o elemento removido p/main
  int removido=-1;

    //Só é possivel remover caso a pilha não esteja vazia
    if(!VaziaDinamica(p)){
      //ponteiro auxiliar, irá auxiliar na remoção do mesmo
      PtrNoPilha auxiliar;
      //ponteiro auxiliar copia o que o topo aponta
      auxiliar=p->topo;
      //recebendo o elemento que irá ser removido da pilha dinâmica
      removido=auxiliar->elemento;
      //o topo recebe o próximo que o topo aponta
      p->topo=p->topo->proximo;
      //liberando a memória do nó removido
      free(auxiliar);
      //diminuindo a quantidade de elementos na pilha
      p->contador--;
      return(removido);
    }else{
      printf("A pilha dinamica esta vazia\n");
    }//else
}//RemoveDinamica

void TopoDinamica(PilhaDinamica *p){
    //váriavel que recebe o elemento do topo
    int topo=-1;
    //ponteiro auxiliar para pegar o elemento do topo
    PtrNoPilha auxiliar;
    //auxiliar recebe o nó que o topo aponta
    auxiliar=p->topo;
    //a variável topo recebe o elemento do nó copiado
    topo=auxiliar->elemento;
    //Exibindo o elemento do nó copiado
    printf("Topo [%d]\n",topo);
}//TopoDinamica

//Como tarefa,  tentem fazer a função que destroi a pilha dinâmica

//-------------------------------Função Principal Main--------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int removido;
  PilhaDinamica Pd;

    //Iniciando Pilha Dinâmica
    IniciaDinamica(&Pd);

    //Verificando se a Pilha Dinâmica está VaziaDinamica
    VerificaStatus(&Pd);

    //Exibe o tamanho da Pilha dinâmica
    printf("Tamanho da Pilha Dinamica [%d]\n",TamanhoDinamica(&Pd));

    //Inserindo Elementos na Pilha Dinamica
    InsereDinamica(&Pd,5);
    InsereDinamica(&Pd,15);
    InsereDinamica(&Pd,25);

    //Exibindo os elementos inseridos na pilha dinâmica
    ImprimeDinamica(&Pd);

    //Removendo um elemento e recebendo o elemento removido
    removido=RemoveDinamica(&Pd);
    //Exibindo o elemento que foi removido
    printf("\nElemento Removido [%d]\n",removido);
    //Exibindo a forma com que a pilha ficou após a remoção
    ImprimeDinamica(&Pd);

    //Exibindo o Topo
    TopoDinamica(&Pd);

 return 0;
}//Main
