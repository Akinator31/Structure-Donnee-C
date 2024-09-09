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

void print_dlist(Dlist *list)
{
    if (is_dlist_empty(list)) {
        printf("Rien a afficher, la dlist est vide\n");
        return;
    }

    dlist_node *current = list->head;

    while (current != NULL) {
        printf("[%d] ", current->value);
        current = current->next;
    }
    printf("\n");
}

Dlist *push_front_list(Dlist *list, int value)
{
    if (is_dlist_empty(list)) {
        dlist_node *new_element = create_dlist_node(value);
        list->head = new_element;
        list->tail = new_element;
        return list;
    }

    dlist_node *temp = list->head;
    dlist_node *new_element = create_dlist_node(value);

    temp->prev = new_element;
    list->head = new_element;
    new_element->next = temp;

    list->length++;
    return list;
}

Dlist *push_back_list(Dlist *list, int value)
{
    if (is_dlist_empty(list)) {
        dlist_node *new_element = create_dlist_node(value);
        list->head = new_element;
        list->tail = new_element;
        return list;
    }

    dlist_node *temp = list->tail;
    dlist_node *new_element = create_dlist_node(value);

    temp->next = new_element;
    list->tail = new_element;
    new_element->prev = temp;

    list->length++;
    return list;
}

Dlist *pop_front_dlist(Dlist *list)
{
    if (is_dlist_empty(list)) {
        printf("Rien a supprimer, la liste est vide !\n");
        return list;
    }

    dlist_node *temp = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->length++;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }

    free(temp);
    list->length--;

    return list;
}

Dlist *pop_back_dlist(Dlist *list)
{
    if (is_dlist_empty(list)) {
        printf("Rien a supprimer, la liste est vide !\n");
        return list;
    }

    dlist_node *temp = list->tail;

    if (list->tail == list->head) {
        list->tail = NULL;
        list->head = NULL;
        list->length++;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }

    free(temp);
    list->length--;

    return list;
}

Dlist *clear_list(Dlist *list)
{
    if (is_dlist_empty(list)) {
        printf("La liste est deja vide !\n");
        return list;
    }
    while (list->head != NULL) {
        pop_front_dlist(list);
    }
    return list;
}