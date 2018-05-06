#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "/home/danileo/bin/include/dfunstrings.h"
#include <time.h>

//Funcion para leer un wfdisc de CSS y guardarlo en una estructura wfdisc.
wfdisc lee_wfdisc(char linea[]){
  wfdisc salida;
  char lnx[30];
  double d;int i;
  copia_string(linea,salida.sta,6,0,0,FIN);
  copia_string(linea,salida.sta2,DELIM_FIN,0,0,' ');
  copia_string(linea,salida.chan,8,7,0,FIN);
  salida.tini=lee_double_char(linea,17,17);
  salida.wfid=lee_int_char(linea,8,34);
  salida.chanid=lee_int_char(linea,8,43);
  copia_string(linea,salida.jdate,8,53,0,FIN);
  salida.tfin=lee_double_char(linea,17,62);
  salida.nsamp=lee_int_char(linea,8,79);
  salida.fsamp=lee_double_char(linea,12,88);
  salida.calib=lee_double_char(linea,15,101);
  salida.calper=lee_double_char(linea,15,118);
  copia_string(linea,salida.instype,6,134,0,FIN);
  salida.segtype=linea[141];
  copia_string(linea,salida.datatype,2,143,0,FIN);
  salida.clip=linea[146];
  copia_string(linea,salida.dir,64,148,0,FIN);
  for(i=199;linea[i]==' ';i++){
    salida.nw[0]=linea[i];
  }
  copia_string(linea,salida.nw,DELIM_FIN,i,0,' ');
  salida.foff=lee_int_char(linea,10,246);
  salida.commid=lee_int_char(linea,8,257);
  salida.ldate=lee_double_char(linea,17,266);
  return(salida);
}

//Funcion para imprimir en un char un wfdisc.
void print_wfdisc(wfdisc wf, char lnwf[]){
  char lnx[100];   
  int i;
  for(i=0;i<299;i++)
    lnwf[i]=' ';
  lnwf[298]='\0';
  copia_string(wf.sta,lnwf,DELIM_NADA,0,0,'\0');
  copia_string(wf.chan,lnwf,DELIM_NADA,0,7,'\0');
  //printf("ACA\n%s\n",lnwf);
  sprintf(lnx,"%16.5lf",wf.tini);
  copia_string(lnx,lnwf,16,0,17,NADA);
  sprintf(lnx,"%8d",wf.wfid);
  copia_string(lnx,lnwf,8,0,34,NADA);
  sprintf(lnx,"%8d",wf.chanid);
  copia_string(lnx,lnwf,8,0,43,NADA);
  copia_string(wf.jdate,lnwf,DELIM_NADA,0,53,'\0');
  //printf("ACA\n%s\n",lnwf);
  sprintf(lnx,"%16.5lf",wf.tfin);
  copia_string(lnx,lnwf,16,0,62,NADA);
  sprintf(lnx,"%8d",wf.nsamp);
  copia_string(lnx,lnwf,8,0,79,NADA);
  sprintf(lnx,"%11.5lf",wf.fsamp);   
  copia_string(lnx,lnwf,11,0,89,NADA);
  sprintf(lnx,"%16.6lf",wf.calib);
  copia_string(lnx,lnwf,16,0,100,NADA);
  sprintf(lnx,"%16.6lf",wf.calper);
  copia_string(lnx,lnwf,16,0,117,NADA);
  copia_string(wf.instype,lnwf,6,0,134,NADA);
  lnwf[141]=wf.segtype;
  copia_string(wf.datatype,lnwf,2,0,143,NADA);
  lnwf[146]=wf.clip;
  copia_string(wf.dir,lnwf,DELIM_NADA,0,148,'\0');
  i=235-strlen(wf.nw);
  copia_string(wf.nw,lnwf,DELIM_NADA,0,i,'\0');
  sprintf(lnx,"%10d",wf.foff);
  copia_string(lnx,lnwf,10,0,246,NADA);
  sprintf(lnx,"%8d",wf.commid);
  copia_string(lnx,lnwf,8,0,257,NADA);
  sprintf(lnx,"%16.6lf",wf.ldate);
  copia_string(lnx,lnwf,17,0,267,'\n');
  lnwf[283]='\0';
}
//Funcion para imprimir un arrival en un char[]
void printarrival(char lnr[], double tmarca, char esta[], char canal[], char marca[]){
  char lnarr[]="                  .00000                         -1       -1                   - -1.000   -1.00   -1.00   -1.00   -1.00   -1.00  -1.000       -1.0   -1.00 -999.00 - c.      -1.00 - dbp:danileo:109       -1                  \n";
  char lnx[50];
  int i,j,k,l;
  struct tm taux;
  time_t t_aux;
  double d1,d2,d3;

  t_aux=(time_t)tmarca;
  taux=*gmtime(&t_aux);

  sprintf(lnx,"%16.5lfx",tmarca);
  copia_string(esta,lnarr,DELIM_NADA,0,0,'\0');
  copia_string(lnx,lnarr,DELIM_NADA,0,8,'x');
  lnarr[32]='1';

  sprintf(lnx,"%d%03dx",taux.tm_year+1900,taux.tm_yday+1);
  copia_string(lnx,lnarr,DELIM_NADA,0,35,'x');
  copia_string(canal,lnarr,DELIM_NADA,0,61,'\0');
  copia_string(marca,lnarr,DELIM_NADA,0,70,'\0');
  t_aux=0;t_aux=time(NULL);
  sprintf(lnx,"%16.6lf",(double)t_aux - 18000);
  copia_string(lnx,lnarr,16,0,207,NADA);

  strcpy(lnr,lnarr);
}

