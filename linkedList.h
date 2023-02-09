#ifndef __LINKEDLIST__
#define __LINKEDLIST__

typedef struct node
{
    void *value;
    struct node *next;
} Node;

typedef struct linkedList
{
    Node *head;
    int size;
} LinkedList;

Node *create_node(void *value);
void push_node(LinkedList *list, Node *node);
LinkedList *create_list();
void insert_list(LinkedList *list, void *value);
void print_list(LinkedList *list);

#endif