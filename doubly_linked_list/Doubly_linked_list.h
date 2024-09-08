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
    int value;                 // Valeur stockée dans le nœud
    struct dlist_node *next;   // Pointeur vers le nœud suivant
    struct dlist_node *prev;   // Pointeur vers le nœud précédent

} dlist_node, *dlistNodePtr;

typedef struct Dlist
{
    int length;               // Nombre d'éléments dans la liste
    struct dlist_node *head;  // Pointeur vers le premier nœud (anciennement 'begin')
    struct dlist_node *tail;  // Pointeur vers le dernier nœud (anciennement 'end')

} Dlist, *DlistPtr;

Dlist *create_dlist();
dlist_node *create_dlist_node(int value);
Bool is_dlist_empty(Dlist *list);
Dlist *push_front_list(Dlist *list, int value);

#endif //DOUBLY_LINKED_LIST_H
