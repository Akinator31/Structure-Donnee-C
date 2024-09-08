#ifndef LISTE_H
#define LISTE_H

typedef enum
{
    false,
    true
} Bool;

typedef struct listElement
{
    int value;
    int indice;
    struct listElement *next;
} listElement, *List;

// Prototype

List new_list(void);
Bool is_empty_list(List lt);
int list_length(List lt);
void print_list(List lt);
List push_back_list(List lt, int x);
List push_front_list(List lt, int x);
List pop_back_list(List lt);
List pop_front_list(List lt);
List clear_list(List lt);
Bool is_element_in_liste(List lt, int x);
int get_list_element_indice(List lt, int indice);

#endif
