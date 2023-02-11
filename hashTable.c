#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TABLE_LENGTH 10;

/*La función hash es hace uso de la técnica de hash djb2,
esta toma una cadena de entrada (str) y devuelve un número 
entero que representa la "clave hash" de la cadena.*/
unsigned int hash(const char *str) {
  unsigned int hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % HASH_TABLE_LENGTH;
}