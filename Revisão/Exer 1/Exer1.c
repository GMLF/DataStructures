#include <stdlib.h>
#include <stdio.h>


//------------------------------Função Converte---------------------------------
void ConverteHora(int total, int *horas, int *minutos){
  //executando enquanto o total de minutos forem maiores do que 60
  do{
    if(total>=60){
      (*horas)++;
      total-=60;
    }//if
  }while(total>=60);

  //o restante do total se tornou os minutos, pois é menor do que 60
    (*minutos)=total;
}//ConverteHora

//------------------------------Função Principal--------------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  int total, horas=0, minutos=0;

  if(argc==1){
    //informando a quantidade de minutos a serem convertidos
    printf("Digite a quantide de minutos que deseja transformar em horas: ");
    scanf("%d",&total);

    //chamando a função e passando por cópia o valor total e parâmetro os que vão serem alterados
    ConverteHora(total, &horas, &minutos);

    printf("%d horas, %d minutos\n",horas,minutos);

 return 0;
}//main
