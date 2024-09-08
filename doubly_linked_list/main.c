//
// Created by pavel on 08/09/2024.
//

#include "Doubly_linked_list.h"
#include <stdio.h>

int main(void)
{

    Dlist *liste = create_dlist();

    if (is_dlist_empty(liste))
        printf("La liste est vide !\n");
    else
        printf("La liste n'est pas vide !\n");

    return 0;
}