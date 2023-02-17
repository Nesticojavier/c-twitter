#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"
#include "hashTable.h"
#include "utils.h"
#include <time.h>

/**
 * It's a function that asks the user to login, signup or leave. If the user chooses to login, it calls
 * the login function, if the user chooses to signup, it calls the signup function, if the user chooses
 * to leave, it breaks the loop and ends the function.
 */
void repl(){
    
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
            repl();
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
    printf("WHAT'S HAPPENING %s?\n", user->username);
    printf("+--------------------+-------------------+\n");
    printf("+");
    printf("(El texto a continuación es un tweet)\n");
    printf("@");
    printf("(El texto a continuación es un nombre de usuario cuyo perfil se desea ver)\n");
    printf("logout\n");
    printf("+--------------------+-------------------+\n");
    printf(">");

    fflush(stdin);
    fgets(comandosLogged, sizeof(comandosLogged), stdin);
    comandosLogged[strcspn(comandosLogged, "\n")] = '\0';

    if(comandosLogged[0] == '+'){

        char tweet[strlen(comandosLogged)-1];
        strcpy(tweet, &comandosLogged[1]); 
        insert_list(user->tweets, tweet);
        timeline(user);

    }else if(comandosLogged[0] == '@'){
        User* perfil;
        int index;

        index = hash(&comandosLogged[1]);
        perfil = search_user(hashTable[index],&comandosLogged[1]);
        if (perfil)
        {

            printf("Perfil de %s\n", perfil->username);
            /*TODO: falta mostrar los tweets del perfil a buscar*/
            print_tweets_list(perfil->tweets, &comandosLogged[1]);
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
                /* Vuelve al timeline del usuario loggeado*/
                timeline(user);
            } else{
                printf("Ha salido del perfil\n");
                timeline(user);
            }

        }else{
            printf("Ingreso un usuario que no existe\n");
            timeline(user);
        }
        
    }else if (strcmp(comandosLogged, "logout") == 0){
        /*Vuelve al prompt inicial*/
        repl();
    } else {
        printf("Debe ingresar una de las opciones validas\n");
        timeline(user);
    }
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
        print_tweets_users_list(user->following);
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
        repl();
    }
    
}
