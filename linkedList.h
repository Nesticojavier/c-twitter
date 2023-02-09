#ifndef __LINKEDLIST__
#define __LINKEDLIST__

typedef struct node
{
    void *value;
    struct node *next;   
} Node;


typedef struct linkedList
{
    Node* head;
    int size; 
} LinkedList;


LinkedList* create_List();

/* Recibe la direccion de memoria de lo que se desea guardar */
Node* create_node(void *value);
void push_node(LinkedList* list, Node* node);
void insert_List(LinkedList* list, void *value);
void print_list(LinkedList* list);

#endif