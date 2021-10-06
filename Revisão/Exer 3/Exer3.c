#include <stdlib.h>
#include <stdio.h>

/*
Escreva uma função recursiva para calcular o valor de um número inteiro de base
x elevada a um expoente inteiro y.
*/

//--------------------------------Função Recursiva------------------------------
float Expoente(float x, float y){
  if(y==0){
    return(1);
  }else{
  return  x * Expoente(x,y-1);
  }//else
}//Expoente

//--------------------------------Função Principal------------------------------
int main(int argc, const char *argv[]){
  //váriaveis
  float x , y,resultado;

    printf("Informe o valor de X: ");
    scanf("%f",&x);

    printf("Informe o valor de Y: ");
    scanf("%f",&y);


    resultado=Expoente(x,y);

    printf("\nX elevado a y = [%.2f] \n",resultado);

  return 0;
}//main
