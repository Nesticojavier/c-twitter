#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"

int main()
{
    // srand (time(NULL));  

    /* NOTA: Falta Implementar Tabla hash.*/

    /* Falta Hacer login */

    /* Crear 10 usuarios random */
    char users[10][10];
    char password[10][10];

    /* Generar usuarios y contrasenas para testear*/
    char i = 0;
    while (i < 10)
    {
        char username[10] = "nombre";
        char pwd[10] = "pass";

        /* Anadir Caracteres */
        char charRand = 'A' + rand() % 20;
        char count = i + '0';
        strncat(username, &count, 1);
        strncat(username, &charRand, 1);
        strncat(pwd, &count, 1);
        strncat(pwd, &charRand, 1);
        strcpy(users[i], username);
        strcpy(password[i], pwd);
        i++;
    }


    /* PROGRAMA  */
    /* La tabla Hash debe ser un array de LinkedList */
    /* Como aun no se ha implementado la tabla hash, almacenare todos los users
    en una lista enlazada */
    LinkedList *listInBucket = create_list();

    int j;
    for (j = 0; j < 10; j++) {

        /*              CREAR USER           */

        /* Funcion para insertar en la tabla hash */
        /* insert_in_HashTable(HashTable* tabla, User*??? HashItem) */
            /* Comportamiento de la funcion: */

            /* Hashear username para encontrar el bucket donde debe ser guardado */


            /* Buscar el user en la lista enlazada que esta en ese bucket */
            if (search_user(listInBucket, users[j]) != NULL) {
                printf("El usuario ya esta registrado\n");
                continue;
            }

            /* Si no se encuentra el username: Se crea el user */
            User *user = create_user(users[j], password[j]);
            /* NOTA: Falta Cifrar el password. Esto se puede hacer dentro de create_user */
            /* Se inserta en la lista */
            insert_list(listInBucket, user);
    }

    printf("\tUsuarios en el bucket: %d\n", listInBucket->size);

    /* Esta funcion debe ser modificada para poder imprimir.
    Actualmente Imprime objetos tipo User. Ver linkedList.c */
    print_list(listInBucket);
    printf("\n");


    /* Fin del programa */


    /* Testing Add Followers */
    int randomIndexUser = rand() % 10; /* Numero entre 0 y 10 */

    /* Seleccionar un usuario aleatorio */
    char *username = users[randomIndexUser];
    User* user = search_user(listInBucket, username);

    printf("Testing anadir seguidos por un user\n");
    printf("\tSeleccionar un usuario random: %s\n", user->username );

    /* Seleccionar 10 usuarios Aleatorios a seguir */
    int x;
    for (x = 0; x < 10; x++) {
        /* Seleccionar un usuario aleatorio a seguir */
        int randomIndexFollow = rand() % 10; /* Numero entre 0 y 10 */
        char *usernameToFollow = users[randomIndexFollow];
        User* userToFollow = search_user(listInBucket, usernameToFollow);
        printf("\t\tBuscar Usuario a seguir: %s\n", userToFollow->username);
         
        printf("\t\t");

        if (follow_user(user, userToFollow) == 1) {
            printf("Seguido con exito\n");
        }
    }
    

    printf("\nSeguidos por:  %s\n", user->username);
    printf("\nNumero de seguidos:  %d\n", user->following->size);

    print_list(user->following);






    return 0;
}