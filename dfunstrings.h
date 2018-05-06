//Funciones de Daniel Leon para manejar strings
#ifndef _DFUNSTRINGS_H
# define _DFUNSTRINGS_H

//DEFINICIONES PARA COPIAR_STRING
#define FIN             '1'
#define NADA            '0'
#define NO_ESPACIOS     '2'
#define DELIM_FIN       0
#define DELIM_NADA      -1
#define INICIO          'I'

void copia_string(char [], char [], int, int, int, char);
void copia_nstring(char [], char [], int, int, int, char,int);
void copia_caracteres(char [], char, int, int);
int busca_pos (char [], char, int);
int lee_int_char(char [], int, int);
float lee_float_char(char [], int, int);
double lee_double_char(char [], int, int);

#endif
