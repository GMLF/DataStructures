#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>



void VerificaParametro(int argc){
  if(argc!=3){
    printf("Erro na quantidade de parametros\n");
    exit(1);
  }//if
}//VerificaParametro

//---------------------------------Função Verifica------------------------------
void VerificaAbertura(FILE *arqentrada, FILE *arqsaida){
  if(arqentrada == NULL || arqsaida == NULL){
    printf("Erro ao abrir os arquivos\n");
    exit(1);
  }//if
}//VerificaAbertura

//---------------------------------Função Código--------------------------------
void LeArquivo_EscreveArquivo(FILE *arqentrada, FILE *arqsaida){
char caracter;

  while(!feof(arqentrada)){

    fscanf(arqentrada,"%c",&caracter);

    //convertendo para minusculo
    caracter=tolower(caracter);

    if(caracter=='a'|| caracter=='e'|| caracter=='i'|| caracter=='o'|| caracter=='u'){
      fprintf(arqsaida,"*");
    }else {
      fprintf(arqsaida,"%c",caracter);
    }//else
  }//while
}//LeArquivo_EscreveArquivo

//--------------------------------Função Principal------------------------------
int main(int argc, const char *argv[]){

    VerificaParametro(argc);

    FILE *arqentrada=fopen(argv[1],"r");
    FILE *arqsaida  =fopen(argv[2],"w");

    //VerificaAbertura
    VerificaAbertura(arqentrada, arqsaida);

    LeArquivo_EscreveArquivo(arqentrada,arqsaida);

  fclose(arqsaida);
  fclose(arqentrada);

  return 0;
}//main
