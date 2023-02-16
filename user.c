#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user.h"
#include "linkedList.h"

/* Crea un Usuario. Retorna el apuntador de ese usuario */
User *create_user(char username[], int password){
    /* Pendiente encriptar password */
    /* Pendiente definir Linked List de Tweets*/
    User *user = (User *)malloc(sizeof(User));
    user->username = username;
    user->password_hash = password;
    user->following = create_list();
    user->tweets = create_list();
    return user;
}

/* Busca un si el username de un usuario esta en un LinkedList de users  */
User* search_user(LinkedList *list, char username[]){
    Node *aux = list->head->next;
    while (aux != NULL)
    {
        User *user = aux->value;
        if (strcmp(user->username, username) == 0)
        {
            return user;
        }
        aux = aux->next;
    }
    return NULL;
}

/* Seguir a un user. Se verifica si esta en la lista de Follow */
int follow_user(User *user, User *followed){

    if (strcmp(user->username, followed->username) == 0) {
        printf("No se puede seguir a si mismo :c \n");
        return 0;
    }

    /* Buscar el la lista de followed */
    if (search_user(user->following, followed->username) != NULL) {
        printf("Ya seguias a este usuario :)\n");
        return 0;
    }

    insert_list(user->following, followed);
    return 1;
}
