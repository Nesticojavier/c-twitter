#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"
#include "hashTable.h"
#include "utils.h"
#include <time.h>

int main() {

    /* creacion de la tabla hash como un array de listas enlazadas */
    int i;
    for (i = 0; i < MAX_TABLE_LENGTH; i++) {
        hashTable[i] = create_list();
    }
   
    // usuario loggeado de prueba1:
    char *username = malloc(MAX_USER_LENGTH);
    char *password = malloc(MAX_PASSWORD_LENGTH);
    username = "nestor";
    password = "hola";
    int index = hash(username);
    int password_hash = hash(password);
    User *user = create_user(username, password_hash);
    insert_list(hashTable[index], user);

    // usuario loggeado de prueba2:
    username = malloc(MAX_USER_LENGTH);
    password = malloc(MAX_PASSWORD_LENGTH);
    username = "felix";
    password = "jkl";
    index = hash(username);
    password_hash = hash(password);
    user = create_user(username, password_hash);
    insert_list(hashTable[index], user);

    /* It's a function that asks the user to login, signup or leave. If the user chooses to login, it
    calls
    the login function, if the user chooses to signup, it calls the signup function, if the user
    chooses
    to leave, it breaks the loop and ends the function. */
    repl();
    
    return 0;
}