#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"
#include "hashTable.h"
#include <time.h>

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
char buscar[15];
char input[15];
LinkedList *hashTable[MAX_TABLE_LENGTH];
time_t tiempo;
char cad[80];
struct tm *tmPtr;

/**
 * It's a function that asks the user to login, signup or leave. If the user chooses to login, it calls
 * the login function, if the user chooses to signup, it calls the signup function, if the user chooses
 * to leave, it breaks the loop and ends the function.
 */
void function(){
    
        printf("DON'T MISS WHAT'S HAPPENING! LOGIN, SIGNUP OR LEAVE\n");
        printf(">");
        scanf("%s", input);
    
        if (strcmp(input, "login") == 0) {
            login();
        } 
        else if (strcmp(input, "signup") == 0) {
            signup();
        }else if (strcmp(input, "leave") == 0) {
            EXIT_SUCCESS;
        } else {
            printf("Debe indicar una de las opciones validas\n");
            function();
        }
       
       
    

}

/**
 * It prints a menu with the options: +, @, logout. If the user types +, it asks for a tweet, if the
 * user types @, it asks for a username, if the user types logout, it returns to the main menu
 */

/* ######################## NOTA ################################## */
/* Se le anade el parametro user, para asi poder acceder a las funciones
de un user en especifico.
Como imprimir Tweets, seguir otros usuarios, etc. */
void timeline(User* user){
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    strftime( cad, 80, "%I:%M, %d/%m/%y", tmPtr );
    printf("WHAT’S HAPPENING %s?\n", user->username);
    printf("+--------------------+-------------------+\n");
    /*TODO: timeline del usuario con los tweets de las personas que sigue y los de el*/
    /*if(user->tweets){
        printf(">");
        print_list(user->tweets);
    }*/
    printf("+");
    printf("(El texto a continuación es un tweet)\n");
    printf("@");
    printf("(El texto a continuación es un nombre de usuario cuyo perfil se desea ver)\n");
    printf("logout\n");
    printf("+--------------------+-------------------+\n");
    printf(">");
    scanf("%s", comandos);
    
    if(strcmp(comandos,  "+") == 0){
        char *tweet = malloc(MAX_TWEET_LENGHT);
        
        fgets(tweet, MAX_TWEET_LENGHT, stdin);
        puts(tweet);
        printf("@%s: %s\n", user->username, cad);

        /*TODO: falta guardar la lista de los tweets del usuario*/
        timeline(user);

    }else if(strcmp(comandos, "@") == 0){
        User* perfil;
        int index;
        
        fgets(buscar, 15, stdin);

        index = hash(buscar);
        perfil = search_user(hashTable[index],buscar);

        if (perfil)
        {

            printf("Perfil de %s\n", perfil->username);
            /*TODO: falta mostrar los tweets del perfil a buscar*/
             printf("+--------------------+-------------------+\n");
            printf("follow");
            printf("                 back\n");
            printf("+--------------------+-------------------+\n");
            printf(">");
            scanf("%s", comandosPerfil);
            if(strcmp(comandosPerfil,  "follow") == 0){
                follow_user(user,perfil);
                timeline(user);
            }else if(strcmp(comandosPerfil,  "back") == 0){
                /* Vuelve al timeline del usuario */
                timeline(user);
            }

        }else{
            printf("Ingreso un usuario que no existe\n");
            timeline(user);
        }
        
    }else if (strcmp(comandos, "logout") == 0){
        /*Vuelve al prompt inicial*/
        function();
    }
    printf("+--------------------+-------------------+\n");
    /* TODO: timeline del usuario con los tweets de las personas que sigue*/
    /* TODO: WHAT'S HAPPENING?*/
    /* TODO:    - + "tweet del usuario logeado"*/
    /* TODO:    - @user: entrar en perfil de user   */
    /* TODO:        -imprimir todos sus tweets*/

    printf("Falta hacer el login\n");
}

/**
 * It takes a string and returns a hash of that string
 */
void login(){
    int index, password_hash;
    User* user;
    char *username = malloc(MAX_USER_LENGTH);
    char *password = malloc(MAX_PASSWORD_LENGTH);
    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);
    

    index = hash(username);

    user = search_user(hashTable[index],username);

    if(user && hash(password) == user->password_hash ) {
        /*Timeline del usuario*/
        timeline(user);
    } else {
        printf("USERNAME OR PASSWORD INVALID\n");
        login();
    }
}

/**
 * It creates a user and inserts it into the hash table
 */
void signup(){
    int index;
    int password_hash;
    char *username = malloc(MAX_USER_LENGTH);
    char *password = malloc(MAX_PASSWORD_LENGTH);
    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");
    scanf("%s", password);

    index = hash(username);

    if(search_user(hashTable[index], username) ){
        printf("USERNAME already taken\n");
        signup();
    } else {
        /* obtener indice de la tabla donde estará contenida */
        password_hash = hash(password);

        /* Crear user */
        User *user = create_user(username, password_hash);

        /* almacenar en la tabla hash */
        insert_list(hashTable[index], user);

        /*Vuelve al prompt inical*/
        function();
    }
    
}

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
    
    
    function();
    

    return 0;
}