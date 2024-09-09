//
// Created by pavel on 08/09/2024.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef enum {
    false,
    true
} Bool;

typedef struct dlist_node
{
    int value;
    struct dlist_node *next;
    struct dlist_node *prev;

} dlist_node;

typedef struct Dlist
{
    int length;
    struct dlist_node *head;
    struct dlist_node *tail;

} Dlist;

Dlist *create_dlist();
dlist_node *create_dlist_node(int value);
Bool is_dlist_empty(Dlist *list);
Dlist *push_front_list(Dlist *list, int value);
Dlist *push_back_list(Dlist *list, int value);
Dlist *pop_front_dlist(Dlist *list);
Dlist *pop_back_dlist(Dlist *list);
void print_dlist(Dlist *list);
Dlist *clear_list(Dlist *list);

#endif
