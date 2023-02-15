#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"
#include "hashTable.h"

#define MAX_PASSWORD_LENGTH 10
#define MAX_USER_LENGTH 10
#define MAX_TABLE_LENGTH 10
#define MAX_TWEET_LENGHT 280

/* Declaring the variables that will be used in the program. */
char comandos[15];
char tweet[MAX_TWEET_LENGHT];
char input[15];
LinkedList *hashTable[MAX_TABLE_LENGTH];

/**
 * It's a function that asks the user to login, signup or leave. If the user chooses to login, it calls
 * the login function, if the user chooses to signup, it calls the signup function, if the user chooses
 * to leave, it breaks the loop and ends the function.
 */
void function(){
    while (1) {
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf(">");
        scanf("%s", input);
    
        if (strcmp(input, "login") == 0) {
            login();
        } 
        else if (strcmp(input, "signup") == 0) {
            signup();
        }else if (strcmp(input, "leave") == 0) {
            break;
        } else {
            printf("Debe indicar una de las opciones validas\n");
        }
       
       
    }

}

/**
 * It prints a menu with the options: +, @, logout. If the user types +, it asks for a tweet, if the
 * user types @, it asks for a username, if the user types logout, it returns to the main menu
 */
void timeline(){
    printf("WHAT’S HAPPENING?\n");
    printf("+--------------------+---------------+\n");
    /*TODO: timeline del usuario con los tweets de las personas que sigue*/
    printf("+");
    printf("                    @");
    printf("                    logout\n");
    printf("+--------------------+---------------+\n");
    if(strcmp(comandos,  "+") == 0){
        printf("El texto a continuación es un tweet");
        scanf("%s", tweet);
       }else if(strcmp(comandos, "@") == 0){
        printf("El texto a continuación es un nombre de usuario cuyo perfil se desea ver");
    }else if (strcmp(comandos, "logout") == 0){
        /*Vuelve al prompt inicial*/
        function();
    }
    printf("+--------------------+---------------+\n");
    /* TODO: hacer verificacion de login*/
    /* TODO: timeline del usuario con los tweets de las personas que sigue*/
    /* TODO: WHAT'S HAPPENING?*/
    /* TODO:    - + "tweet del usuario logeado"*/
    /* TODO:    - @user: entrar en perfil de user   */
    /* TODO:        -imprimir todos sus tweets*/
    /* TODO:        -follow*/
    /* TODO:        -back*/
    /* TODO:    - logout cerrar sesion*/

    printf("Falta hacer el login\n");
}

/**
 * It takes a string and returns a hash of that string
 */
void login(){
    int i;
    char *username = malloc(MAX_USER_LENGTH);
    char *password = malloc(MAX_PASSWORD_LENGTH);
    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);
    for(i=0; i < MAX_TABLE_LENGTH ; i++ ){
        if(search_user(hashTable[i],username)){
            continue;
        }else{
            printf("USERNAME OR PASSWORD INVALID\n");
            login();
        }
    }
    /*Timeline del usuario*/
    timeline();
}

/**
 * It creates a user and inserts it into the hash table
 */
void signup(){
    int index;
    int i;
    char *username = malloc(MAX_USER_LENGTH);
    char *password = malloc(MAX_PASSWORD_LENGTH);
    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    /*TODO: verificar si el usuario ya está registrado*/
    for(i=0; i < MAX_TABLE_LENGTH ; i++ ){
        if(search_user(hashTable[i],username)){
            printf("USERNAME already taken\n");
            signup();
        }else{
            /* obtener indice de la tabla donde estará contenida */
            index = hash(password);

            /* Crear user */
            User *user = create_user(username, index);

            /* almacenar en la tabla hash */
            insert_list(hashTable[index], user);

            /*Vuelve al prompt inical*/
            function();
        }
    }
}

int main() {

    /* creacion de la tabla hash como un array de listas enlazadas */

    int i;
    for (i = 0; i < 10; i++) {
        hashTable[i] = create_list();
    }
   


    /* It's a function that asks the user to login, signup or leave. If the user chooses to login, it
    calls
    the login function, if the user chooses to signup, it calls the signup function, if the user
    chooses
    to leave, it breaks the loop and ends the function. */
    
    
    function();
    

    return 0;
}