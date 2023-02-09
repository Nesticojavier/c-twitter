#include "linkedList.h"
#ifndef __USER__
#define __USER__

typedef struct user
{
    char *username;
    char *password_encrypted;
    LinkedList *tweets;
    LinkedList *followed;
} User;

#endif
