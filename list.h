#ifndef LIST_H
#define LIST_H

typedef int list_t;

struct List_Elem
{
    list_t elem;
    int ptr_next;
    int ptr_prev;
};

struct List
{
    List_Elem* list;
    int head;
    int free;
    size_t capacity;
    size_t size;
};

#endif // LIST_H