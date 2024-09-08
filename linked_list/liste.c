//
// Created by pavel on 08/09/2024.
//

#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

List new_list(void)
{
    return NULL;
}

Bool is_empty_list(List lt)
{
    if (lt == NULL) {
        return true;
    } else {
        return false;
    }
}

int list_length(List lt)
{
    int size = 0;

    if (!is_empty_list(lt))
    {
        while (lt != NULL) {
            ++size;
            lt = lt->next;
        }
        return size;
    }
    return size;
}

void print_list(List lt)
{
    if (is_empty_list(lt)) {
        printf("La liste est vide\n");
        return;
    }
    while (!is_empty_list(lt))
    {
        printf("[%d] ", lt->value);
        lt = lt->next;
    }
    printf("\n");
}

List push_back_list(List lt, int x)
{
    listElement *new_element;

    new_element = malloc(sizeof(*new_element));

    if (new_element == NULL) {
        printf("Erreur allocation dynamique !\n");
        exit(EXIT_FAILURE);
    }

    new_element->value = x;
    new_element->next = NULL;

    if (is_empty_list(lt)) {
        return new_element;
    }

    listElement *temp = lt;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_element;

    return lt;
}

List push_front_list(List lt, int x)
{
    listElement *new_element;

    new_element = malloc(sizeof(*new_element));

    if (new_element == NULL) {
        printf("Erreur allocation dynamique !\n");
        exit(EXIT_FAILURE);
    }

    new_element->value = x;

    if (is_empty_list(lt)) {
        new_element->next = NULL;
    } else {
        new_element->next = lt;
    }
    return new_element;
}

List pop_back_list(List lt)
{
    if (is_empty_list(lt)) {
        return lt;
    }

    if (lt->next == NULL) {
        free(lt);
        lt = NULL;
        return lt;
    }

    listElement *temp = lt;
    listElement *before = lt;

    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }

    before->next = NULL;
    free(temp);
    temp = NULL;

    return lt;
}

List pop_front_list(List lt)
{
    if (is_empty_list(lt)) {
        return lt;
    }

    listElement *temp = lt->next;

    free(lt);
    lt = NULL;
    return temp;
}

List clear_list(List lt)
{
    if (is_empty_list(lt))
    {
        return lt;
    }

    while (lt != NULL) {
        lt = pop_front_list(lt);
    }

    return lt;
}

Bool is_element_in_liste(List lt, int x)
{
    if (is_empty_list(lt)) {
        return false;
    }

    while (lt != NULL) {
        if (lt->value == x) {
            return true;
        }
        lt = lt->next;
    }
    return false;
}

int get_list_element_indice(List lt, int indice)
{
    if (is_empty_list(lt)) {
        return -1;
    }

    if ((list_length(lt) - 1) < indice) {
        return -1;
    }

    for (int i = 0; i < indice; i++) {
        lt = lt->next;
    }
    return lt->value;
}