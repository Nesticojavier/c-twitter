#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "user.h"

int main()
{
    /* Metodo que crea una lista Enlazada */
    LinkedList *list = create_List();

    /* Crear Usuarios */

    /* Usuario 1 */
    User *pedrito = (User *)malloc(sizeof(User));
    pedrito->username = "pedrito";
    pedrito->password_encrypted = "pedritopassword";

    /* Usuario 2 */
    User *Juan1 = (User *)malloc(sizeof(User));
    Juan1->username = "JUAN1";
    Juan1->password_encrypted = "JUAN1PASSWORD";

    /* Usuario 3 */
    User *Juan2 = (User *)malloc(sizeof(User));
    Juan2->username = "Juan2";
    Juan2->password_encrypted = "Juan2password";

    /* Usuario 4 */
    User *Juan3 = (User *)malloc(sizeof(User));
    Juan3->username = "Juan3";
    Juan3->password_encrypted = "Juan3password";

    /* Usuario 5 */
    User *Juan4 = (User *)malloc(sizeof(User));
    Juan4->username = "Juan4";
    Juan4->password_encrypted = "Juan4password";

    insert_List(list, pedrito);
    insert_List(list, Juan1);
    insert_List(list, Juan2);
    insert_List(list, Juan3);
    insert_List(list, Juan4);

    /* Esta funcion debe ser modificada para poder imprimir. Ver linkedList.c */
    print_list(list);

    printf("\n");
    printf("Size of list: %d ", list->size);

    return 0;
}