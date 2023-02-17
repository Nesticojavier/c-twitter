#include "user.h"
#include <time.h>

#ifndef __UTILS__
#define __UTILS__

#define LC_TIME 5
#define MAX_PASSWORD_LENGTH 10
#define MAX_USER_LENGTH 10
#define MAX_TABLE_LENGTH 10
#define MAX_TWEET_LENGHT 280

/* Declaring the variables that will be used in the program. */
void login();
void signup();
void timeline(User* user);
char comandos[15];
char comandosPerfil[15];
char comandosLogged[MAX_TWEET_LENGHT + 1];

char buscar[15];
char input[15];
LinkedList *hashTable[MAX_TABLE_LENGTH];
time_t tiempo;
char cad[80];
struct tm *tmPtr;

void repl();
void timeline(User* user);
void login();
void signup();

#endif