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

    /* creacion de la tabla hash como un array de listas enlazadas */
    LinkedList *hashTable[MAX_TABLE_LENGTH];
    int i;
    for (i = 0; i < 10; i++) {
        hashTable[i] = create_list();
    }

    printf("###################### TEST login #####################\n");

    int index;
    for (i = 0; i < 3; i++) {
/*         char *username = malloc(MAX_USER_LENGTH);
        char *password = malloc(MAX_PASSWORD_LENGTH);
 */
        char *username = malloc(MAX_USER_LENGTH);
        char *password = malloc(MAX_PASSWORD_LENGTH);
        printf("Nombre de usuario: ");
        scanf("%s", username);
        fflush(stdin);
        printf("Contraseña: ");
        scanf("%s", password);
        fflush(stdin);

        /* obtener indice de la tabla donde estará contenida */
        index = hash(password);

        /* Crear user */
        User *user = create_user(username, index);

        /* almacenar en la tabla hash */
        insert_list(hashTable[0], user);
    }

    printf("\tUsuarios en el bucket: %d\n", hashTable[0]->size);
    print_list(hashTable[0]);

    return 0;
}