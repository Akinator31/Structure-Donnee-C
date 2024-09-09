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

    liste = push_front_list(liste, 5);
    liste = push_front_list(liste, 9);
    liste = push_front_list(liste, 3);

    print_dlist(liste);
    liste = clear_list(liste);

    printf("Longueur de la dlist : %d\n", liste->length);

    print_dlist(liste);

    return 0;
}