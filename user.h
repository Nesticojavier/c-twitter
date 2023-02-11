#include "linkedList.h"
#ifndef __USER__
#define __USER__

typedef struct user
{
    char *username;
    int password_hash;
    LinkedList *tweets;
    LinkedList *following;
} User;

User* create_user(char username[], int password);
User* search_user(LinkedList* list, char username[]);
int follow_user(User* user, User* followed);


#endif