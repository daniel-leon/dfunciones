//Funciones de Daniel Leon para manejar archivos CSS
#ifndef _DFUNCSS_H
# define _DFUNCSS_H

struct wwfdisc{
char sta[7];//estacion
char sta2[7];//estacion solo hasta que arranca el espacio
char chan[9]; //canal 
double tini;//t. inicial. f17.5
int wfid; //ident. waveform
int chanid; //ident. canal.
char jdate[9];//fecha juliana
double tfin;//t. final. f17.5
int nsamp;//num. de muestras 
double fsamp; //freq. muestreo 
double calib; //calibracion
double calper;//calibracion periodo
char instype[7];//tipo de instrumento
char segtype; //metodo de indeccion  
char datatype[3]; //almacen. numerico. 
char clip;//clipped data 
char dir[65]; //directorio
char nw[33];//archivo con los datos
int foff; //offset en el archivo con los datos
int commid; //identificador de comentario
double ldate; //hora de grabacion de los datos
};
typedef struct wwfdisc wfdisc;

struct aarrival{
  double epoch;
  char esta[7];
  char chan[9];
  char marca[9];
};
typedef struct aarrival arrival;

wfdisc lee_wfdisc(char []);
void print_wfdisc(wfdisc, char[]);
void printarrival(char [],double, char[], char[], char[]); 

#endif
