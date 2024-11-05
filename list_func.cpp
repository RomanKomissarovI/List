#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list_func.h"

void ListCtor(List* list)
{   
    list->capacity = init_capacity;
    list->size = 1;

    list->list = (list_t*) calloc (list->capacity, sizeof(list_t));
    list->ptr_next = (int*) calloc (list->capacity, sizeof(int));
    list->ptr_prev = (int*) calloc (list->capacity, sizeof(int));

    list->ptr_next[0] = 0;
    list->ptr_prev[0] = 0;
    list->list[0] = -1;
    for (int i = 1; i < (int) list->capacity; ++i)
    {
        list->ptr_next[i] = i + 1;
        list->list[i] = 0;
    }
    list->ptr_next[list->capacity - 1] = -1;

    list->free = 1;
}

void ListDtor(List* list)
{
    free(list->list);
    free(list->ptr_next);
    free(list->ptr_prev);
    list->size = 0;
    list->capacity = 0;
    list->free = -1;
}

void ListPush(List* list, list_t a, int ind)
{
    ind++;
    assert(list != nullptr);

    if (list->size == list->capacity)
    {
        Recalloc(list, (size_t) (list->capacity * 1.4) + 10);
    }

    size_t free_el = list->free;
    list->free = list->ptr_next[list->free];


    list->list[free_el] = a;

    size_t k = 0;
    int ind_now = 0;
    while (ind_now != ind)
    {
        k = list->ptr_next[k];
        ind_now++;
    }

    list->ptr_next[free_el] = k;
    list->ptr_prev[free_el] = list->ptr_prev[k];
    list->ptr_next[list->ptr_prev[k]] = free_el;
    list->ptr_prev[k] = free_el;

    list->size++;
}

void ListPushBack(List* list, list_t a)
{
    ListPush(list, a, list->size - 1);
}

void ListPop(List* list, int ind)
{
    ind++;
    assert(list != nullptr);
    if ((long long) list->size - 1 < (long long) ind)
    {
        printf("Error pop: _ind_ more than size of list\n");
        return;
    }

    size_t k = 0;
    int ind_now = 0;
    while (ind_now != ind)
    {
        k = list->ptr_next[k];
        ind_now++;
    }

    list->ptr_next[list->ptr_prev[k]] = list->ptr_next[k];
    list->ptr_prev[list->ptr_next[k]] = list->ptr_prev[k];

    list->ptr_next[k] = list->free;
    list->free = k;
    
    list->size--;
}

void ListPopBack(List* list)
{
    ListPop(list, list->size - 2);
}

void ListPrint(List* list)
{
    size_t k = 0;
    k = list->ptr_next[k];
    for(size_t i = 1; i < list->size; ++i)
    {
        printf("%d ", list->list[k]);
        //printf("k: %d, elem: %d, prev: %d (%d), next: %d (%d)\n", k, list->list[k], list->ptr_prev[k], list->list[list->ptr_prev[k]], list->ptr_next[k], list->list[list->ptr_next[k]]);
        k = list->ptr_next[k];
    }
    printf("\n\n");
}

void Recalloc(List* list, size_t new_capacity)
{
    assert(list != nullptr);

    list->list = (list_t*) realloc(list->list, new_capacity * sizeof(list_t));
    list->ptr_next = (int*) realloc(list->ptr_next, new_capacity * sizeof(list_t));
    list->ptr_prev = (int*) realloc(list->ptr_prev, new_capacity * sizeof(list_t));
    // if (l == nullptr)
    // {
    //     printf("Error recalloc memory\n");
    //     return;
    // }

    list->capacity = new_capacity;
    for(size_t i = list->size; i < list->capacity; ++i)
    {
        list->ptr_next[i] = i + 1;
        list->list[i] = 0;
    }
    list->ptr_prev[list->size] = -1;
    list->ptr_next[list->capacity - 1] = list->free;

    list->free = list->size;
}
