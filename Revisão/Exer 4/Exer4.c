#include <stdlib.h>
#include <stdio.h>
//---------------------------Funções do Código----------------------------------
int *AlocaVetor(int tamanho){
  //ponteiro auxiliar
  int *aux;
    //alocando memória do vetor auxiliar
    aux=malloc(tamanho*sizeof(int));
    //retornando o endereço de memória da região alocada
    return(aux);
}//AlocaVetor

void PreencheVetor(int vetor[], int tamanho){
  for(int i=0;i<tamanho;i++){
    printf("Digite o elemento [%d] do vetor: ",i+1);
    scanf("%d",&vetor[i]);
  }//for
}//PreencheVetor

void ExibeVetor(int vetor[], int tamanho){
  printf("Vetor { ");

  for(int i=0; i<tamanho; i++){
    printf("%d ",vetor[i]);
  }//for

    printf("}");
}//ExibeVetor

//---------------------------Função Principal-----------------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int tamanho,*vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tamanho);

    //vetor recebe o endereço da região alocada
    vetor=AlocaVetor(tamanho);
    printf("\n");

    //chamando função que preenche o vetor
    PreencheVetor(vetor, tamanho);
    printf("\n");

    //Exibe vetor
    ExibeVetor(vetor, tamanho);

   //liberando memória alocada do vetor
   free(vetor);
  return 0;
}//main
