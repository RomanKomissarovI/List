#ifndef LIST_H
#define LIST_H

typedef int list_t;

struct List_Elem
{
    list_t elem;
    List_Elem* ptr_next;
    List_Elem* ptr_prev;
};

struct List
{
    List_Elem* list;
    List_Elem* head = nullptr;
    List_Elem* free = nullptr;
    size_t capacity = 1000;
    size_t size = 0;
};

#endif // LIST_H