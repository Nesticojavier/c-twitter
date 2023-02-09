#include "linkedList.h"
#ifndef __USER__
#define __USER__

typedef struct user
{
    char *username;
    char *password_encrypted;
    LinkedList *tweets;
    LinkedList *following;
} User;

User* create_user(char username[], char password[]);
User* search_user(LinkedList* list, char username[]);
int follow_user(User* user, User* followed);


#endif