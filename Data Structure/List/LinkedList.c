#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

struct node
{
    // Data stored in the node.
    list_data_t data;

    // Successor.
    struct node *next;
};

struct list
{
    // Number of elements.
    int count;

    // Pointer to the header (rank = -1).
    struct node *header;
};

/*******************************
Helper functions implementation.
*******************************/

// Check whether the index is valid (begin <= pos < end).
static inline void check_bounds(int pos, int begin, int end)
{
    if (pos < begin || pos >= end)
    {
        fprintf(stderr, "ERROR: Out of range: %d not in [%d, %d)\n", pos, begin, end);
        exit(EXIT_FAILURE);
    }
}

// Check whether the pointer is a non-null pointer.
static inline void check_pointer(const void *pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

/*******************************
Interface functions implementation.
*******************************/

list_t *LinkedList_Create(void)
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    check_pointer(list);

    list->count = 0;
    list->header = (struct node *)malloc(sizeof(struct node));
    check_pointer(list->header);
    list->header->next = NULL;

    return list;
}

void LinkedList_Destroy(list_t *list)
{
    while (list->header)
    {
        struct node *next = list->header->next;
        free(list->header);
        list->header = next;
    }
    free(list);
}

int LinkedList_Size(const list_t *list)
{
    return list->count;
}

bool LinkedList_IsEmpty(const list_t *list)
{
    return list->count == 0;
}

list_data_t LinkedList_At(const list_t *list, int i) // list[i]
{
    check_bounds(i, 0, list->count);

    struct node *current = list->header->next;

    for (int j = 0; j < i; ++j)
    {
        current = current->next;
    }

    return current->data;
}

int LinkedList_Find(const list_t *list, list_data_t data)
{
    int index = 0;
    struct node *current = list->header->next;

    while (current != NULL && current->data != data)
    {
        current = current->next;
        index++;
    }

    return current ? index : LIST_NOT_FOUND;
}

void LinkedList_Insert(list_t *list, int i, list_data_t data)
{
    check_bounds(i, 0, list->count + 1);

    struct node *node = (struct node *)malloc(sizeof(struct node));
    check_pointer(node);
    node->data = data;

    struct node *tmp = list->header;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;

    ++list->count;
}

void LinkedList_Delete(list_t *list, int i)
{
    check_bounds(i, 0, list->count);

    struct node *tmp = list->header;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    struct node *node = tmp->next;
    tmp->next = node->next;
    free(node);
    node = NULL;

    --list->count;
}

void LinkedList_Traverse(list_t *list, void (*p_trav)(list_data_t data))
{
    for (struct node *cur = list->header->next; cur != NULL; cur = cur->next)
    {
        p_trav(cur->data);
    }
}

void LinkedList_Reverse(list_t *list)
{
    struct node *pre = list->header->next;
    list->header->next = NULL;

    while (pre)
    {
        struct node *tmp = pre;
        pre = pre->next;
        tmp->next = list->header->next;
        list->header->next = tmp;
    }
}
