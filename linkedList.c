#include <stdlib.h>
#include <stdio.h>
#include "user.h"
#include "linkedList.h"

/* Actividad Pendiente: No permitir USERS repeditos. Verificar Passwords. Encriptarlas */

/* Recibe como parametro un apuntador a cualquier tipo de dato. Se crea un nodo asociado*/
Node *create_node(void *value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

/* Funcion que inserta un Nodo en La Lista  */
void push_node(LinkedList *list, Node *node)
{
    Node *aux = list->head;
    node->next = aux->next;
    aux->next = node;
}

/* Funcion que crea la Lista Enlazada  */
LinkedList *create_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    Node *head = (Node *)malloc(sizeof(Node));
    list->head = head;
    list->head->next = NULL;

    return list;
}

/* Recibe la direccion de memoria de lo que se desea guardar. Se inserta sin verificar si el elemento esta en la lista*/
void insert_list(LinkedList *list, void *value)
{
    Node *node = create_node(value);
    push_node(list, node);
    list->size += 1;
}

/* Funcion usada para imprimir La lista. Actualmente imprime objetos tipo User.
Nota: requiere casting de la variable element para imprimir diferentes tipos de datos sin error */
void print_list(LinkedList *list)
{
    /* Head de la lista */
    Node *node = list->head->next;
    while (node != NULL)
    {
        /* NOTA: */
        /* Para imprimir, SE DEBE Castear dependiendo del tipo de dato */
        User *element = (User *)node->value;
        printf("%s: %d\n", element->username, element->password_hash);

        node = node->next;
    }
}

void print_tweets_list(LinkedList *list)
{
    /* Head de la lista */
    Node *node = list->head->next;
    while (node != NULL)
    {
        /* NOTA: */
        /* Para imprimir, SE DEBE Castear dependiendo del tipo de dato */
        char *element = (char *)node->value;
        printf("%s\n", element);

        node = node->next;
    }
}
