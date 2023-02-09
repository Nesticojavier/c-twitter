#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

/* Recibe como parametro un apuntador a cualquier tipo de dato. */
Node *create_node(void *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}


void push_node(LinkedList* list, Node* node) {
    Node* aux = list->head;
    node->next = aux->next;
    aux->next = node;
}

LinkedList *create_List()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    Node *head = (Node *)malloc(sizeof(Node));
    list->head = head;
    list->head->next = NULL;

    return list;
}

void insert_List(LinkedList* list, void *value) {
    Node* node = create_node(value);
    push_node(list, node);
    list->size += 1;
}

/* Funcion usada para Testear. Imprime los datos de la lista, pero requiere casting para imprimir sin error */
void print_list(LinkedList* list) {
    Node* aux = list->head->next;
    while (aux != NULL) {
        char *x = (char *) aux->value;
        printf("%c->", *x);
        aux = aux->next;
    }

}
