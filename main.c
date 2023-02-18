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

    /* It's a function that asks the user to login, signup or leave. If the user chooses to login, it
    calls
    the login function, if the user chooses to signup, it calls the signup function, if the user
    chooses
    to leave, it breaks the loop and ends the function. */
    repl();
    
    return 0;
}