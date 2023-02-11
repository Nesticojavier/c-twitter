#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"
#include "hashTable.h"

#define MAX_PASSWORD_LENGTH 10
#define MAX_USER_LENGTH 10
#define MAX_TABLE_LENGTH 10

int main() {
    int index;
    char input[15];
    LinkedList *hashTable[MAX_TABLE_LENGTH];

    /* creacion de la tabla hash como un array de listas enlazadas */
    int i;
    for (i = 0; i < 10; i++) {
        hashTable[i] = create_list();
    }

    while (1) {
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf(">");
        scanf("%s", input);

        if (strcmp(input, "login") == 0) {
            // TODO: hacer verificacion de login
            // TODO: timeline del usuario con los tweets de las personas que sigue
            // TODO: WHAT'S HAPPENING?
            // TODO:    - + "tweet del usuario logeado"
            // TODO:    - @user: entrar en perfil de user   
            // TODO:        -imprimir todos sus tweets
            // TODO:        -follow
            // TODO:        -back
            // TODO:    - logout cerrar sesion

            printf("Falta hacer el login\n");
        } else if (strcmp(input, "signup") == 0) {
            char *username = malloc(MAX_USER_LENGTH);
            char *password = malloc(MAX_PASSWORD_LENGTH);
            printf("USERNAME: ");
            scanf("%s", username);
            printf("PASSWORD: ");
            scanf("%s", password);

            // TODO: verificar si el usuario ya está registrado

            /* obtener indice de la tabla donde estará contenida */
            index = hash(password);

            /* Crear user */
            User *user = create_user(username, index);

            /* almacenar en la tabla hash */
            insert_list(hashTable[index], user);
        }else if (strcmp(input, "leave") == 0) {
            break;
        } else {
            printf("Debe indicar una de las opciones validas\n");
        }
    }

    return 0;
}