//
// Created by pavel on 08/09/2024.
//

#include "Doubly_linked_list.h"
#include "stdlib.h"
#include "stdio.h"

Dlist *create_dlist()
{
    Dlist *list = malloc(sizeof(*list));

    if (list == NULL) {
        fprintf(stderr, "Problème lors de l'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    list->length = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

dlist_node *create_dlist_node(int value)
{
    dlist_node *element = malloc(sizeof(*element));

    if (element == NULL) {
        fprintf(stderr, "Problème lors de l'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    element->value = value;
    element->next = NULL;
    element->prev = NULL;

    return element;
}

Bool is_dlist_empty(Dlist *list)
{
    if (list->tail == NULL && list->head == NULL) {
        return true;
    }
    return false;
}

Dlist *push_front_list(Dlist *list, int value)
{
    if (is_dlist_empty(list)) {
        dlist_node *new_element = create_dlist_node(value);
        list->head = new_element;
        list->tail = new_element;
        return list;
    }

    dlist_node *temp = list;

    while (temp != NULL) {
        temp = temp->prev;
    }

    list->head = temp;

}
