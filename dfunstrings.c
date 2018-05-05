#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./dfunstrings.h"

//Funcion estandar para copiar pedazos de cadena en otra cadena.
void copia_string(char orig[], char dest[], int tam, int off_orig, int off_dest, char modo){
  int i;
  if(tam<1){
    for(i=off_orig;orig[i]!=modo;i++)
      dest[i-off_orig+off_dest]=orig[i];
    if(tam==DELIM_FIN)
      dest[i-off_orig+off_dest]='\0';
  } else{
    for(i=0;i<tam;i++)
      dest[i+off_dest]=orig[i+off_orig];
    if(modo==FIN)
      dest[i+off_dest]='\0';
} }


//Funcion para copiar caracteres de una cadena a otra, pero con limite.
void copia_nstring(char orig[], char dest[], int tam, int off_orig, int off_dest, char modo, int lim){
  int i,j=0;
  if(tam<1){
    for(i=off_orig; orig[i]!=modo && j<lim;i++){
      dest[i-off_orig+off_dest]=orig[i];
      j++;
    } if(tam==DELIM_FIN)
      dest[i-off_orig+off_dest]='\0';
  } else{
    for(i=0;i<tam && j<lim;i++){
      dest[i+off_dest]=orig[i+off_orig];
      j++;
    } if(modo==FIN)
      dest[i+off_dest]='\0';
} }

//Funcion para copiar un caracter en un string desde la posicion inicio a la final.
void copia_caracteres(char cadena[], char caracter, int inicio, int final){
  int i;
  for(i=inicio;i<final;i++)
    cadena[i]=caracter;
  cadena[i]='\0';
}

//funcion que devuelve la posicion en la que un caracter esta en una cadena.
//itera es el parametro para encontrar la n-sima vez del caracter en la cadena.
int busca_pos(char cadena[], char caracter,int itera){
  int i,tam,iaux;
  tam=strlen(cadena);
  i=0;
  iaux=0;
  do{
    if(cadena[i]==caracter)
    iaux++;
    if(iaux==itera)
      return(i); 
    i++;
  } while(i<tam);//printf("no se encontro caracter %c.\n",caracter);
  return(-1);
}

//funcion para leer un entero de una cadena desde una posicion.
int lee_int_char(char cadena[], int tam, int pos){
  char aux[100];
  int i;
  copia_string(cadena,aux,tam,pos,0,FIN);
  sscanf(aux,"%d",&i);
  return(i);
}

//funcion para leer un float de una cadena desde una posicion.
float lee_float_char(char cadena[], int tam, int pos){
  char aux[100];
  float i;
  copia_string(cadena,aux,tam,pos,0,FIN);
  sscanf(aux,"%f",&i);
  return(i);
}

//funcion para leer un double de una cadena desde una posicion.
double lee_double_char(char cadena[], int tam, int pos){
  char aux[100];
  double i;
  copia_string(cadena,aux,tam,pos,0,FIN);
  sscanf(aux,"%lf",&i);
  return(i);
}

