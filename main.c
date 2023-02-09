#include <stdio.h>
#include "linkedList.h"

int main()
{
    /* Metodo que crea una lista Enlazada */
    LinkedList* list = create_List();
    int valor = 10;
    char x1 = 'a';

    char x2 = 'b';
    char x3 = 'c';



    insert_List(list,&x1);
    insert_List(list,&x2);

    insert_List(list,&x3);

    print_list(list);
    printf("\n");
    printf("Size of list: %d ", list->size);


    
    return 0;
}