//
// Created by pavel on 08/09/2024.
//
#include "liste.h"
#include <stdio.h>

int main(void)
{
    List my_list = new_list();
    List my_list2 = new_list();

    my_list = push_front_list(my_list, 6);
    my_list2 = push_front_list(my_list2, 6);

    printf("Taille liste : %d\n", list_length(my_list));
    printf("Taille liste : %d\n", list_length(my_list2));

    my_list = push_front_list(my_list, 5);
    my_list2 = push_back_list(my_list2, 5);

    print_list(my_list);
    print_list(my_list2);

    my_list = pop_back_list(my_list);
    my_list2 = pop_back_list(my_list2);

    print_list(my_list);
    print_list(my_list2);

    my_list = push_front_list(my_list, 6);
    my_list2 = push_front_list(my_list2, 6);

    print_list(my_list);
    print_list(my_list2);

    printf("Taille liste : %d\n", list_length(my_list));
    int test = get_list_element_indice(my_list, 2);

    printf("Valeur a l'indice 2 : %d\n", test);

    if (is_element_in_liste(my_list, 5))
        printf("Le chiffre est bien dans la liste my_list !\n");
    else
        printf("Le chiffre n'est pas dans la liste !\n");

    my_list = clear_list(my_list);
    my_list2 = clear_list(my_list2);

    print_list(my_list);
    print_list(my_list2);

    return 0;
}