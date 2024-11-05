#ifndef LIST_H
#define LIST_H

typedef int list_t;
const int init_capacity = 10;

struct List
{
    list_t* list;
    int* ptr_next;
    int* ptr_prev;
    int free;
    size_t capacity;
    size_t size;
};

#endif // LIST_H