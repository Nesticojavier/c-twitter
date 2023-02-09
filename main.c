#include <stdio.h>
#include "linkedList.h"

int main()
{
    LinkedList* list = create_List();
    int valor = 10;
    int x1 = 10;

    int x2 = 20;
    int x3 = 30;



    insert_List(list,&x1);
    insert_List(list,&x2);

    insert_List(list,&x3);

    print_list(list);
    printf("\n");
    printf("Size of list: %d ", list->size);


    
    return 0;
}