#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list_func.h"

void ListCtor(List* list)
{   
    list->capacity = 5;
    list->size = 0;

    list->list = (List_Elem*) calloc (list->capacity, sizeof(List_Elem));
    for (int i = 0; i < (int) list->capacity; ++i)
    {
        list->list[i].ptr_next = i + 1;
        list->list[i].ptr_prev = i - 1;
        list->list[i].elem = 0;
    }
    list->list[list->capacity - 1].ptr_next = -1;
    list->head = -1;
    list->free = 0;
}

void ListDtor(List* list)
{
    free(list->list);
    list->size = 0;
    list->capacity = 0;
    list->free = -1;
    list->head = -1;
}

void ListPush(List* list, list_t a, int ind)
{
    assert(list != nullptr);

    if (list->size == list->capacity)
    {
        Recalloc(list, (size_t) (list->capacity * 1.4) + 10);
    }

    size_t free_el = list->free;
    list->free = (list->list[list->free]).ptr_next;


    (list->list[free_el]).elem = a;
    if (list->head == -1)
    {
        (list->list[free_el]).ptr_next = -1;
        (list->list[free_el]).ptr_prev = -1;
        list->head = free_el;
    }
    else
    {
        if (ind == -1)
        {
            size_t k = list->head;
            while ((list->list[k]).ptr_next != -1)
            {
                k = (list->list[k]).ptr_next;
            }

            (list->list[free_el]).ptr_next = -1;
            (list->list[free_el]).ptr_prev = k;
            (list->list[k]).ptr_next = free_el;
        }
        else
        {
            size_t k = list->head;
            int ind_now = 0;
            while (ind_now != ind)
            {
                k = (list->list[k]).ptr_next;
                ind_now++;
            }

            (list->list[free_el]).ptr_next = k;
            (list->list[free_el]).ptr_prev = list->list[k].ptr_prev;
            (list->list[(list->list[k]).ptr_prev]).ptr_next = free_el;
            (list->list[k]).ptr_prev = free_el;
        }
    }

    list->size++;
}

void ListPop(List* list,  int ind)
{
    assert(list != nullptr);
    if ((long long) list->size - 1 < (long long) ind)
    {
        printf("Error pop: _ind_ more than size of list\n");
        return;
    }

    if (ind == -1)
    {
        size_t k = list->head;
        while ((list->list[k]).ptr_next != -1)
        {
            k = (list->list[k]).ptr_next;
        }

        (list->list[(list->list[k]).ptr_prev]).ptr_next = -1;

        (list->list[k]).ptr_next = list->free;
        list->free = k;
    }
    else
    {
        size_t k = list->head;
        int ind_now = 0;
        while (ind_now != ind)
        {
            k = (list->list[k]).ptr_next;
            ind_now++;
        }

        if (ind_now != 0)
        {
            (list->list[(list->list[k]).ptr_prev]).ptr_next = (list->list[k]).ptr_next;
        }
        else
        {
            list->head = (list->list[0]).ptr_next;
        }
        
        if ((long long) ind_now != (long long) list->size - 1)
        {
            (list->list[(list->list[k]).ptr_next]).ptr_prev = (list->list[k]).ptr_prev;
        }

        (list->list[k]).ptr_next = list->free;
        list->free = k;
    }
    
    list->size--;
}

void ListPrint(List* list)
{
    size_t k = list->head;
    for(size_t i = 0; i < list->size; ++i)
    {
        printf("%d ", (list->list[k]).elem);
        k = (list->list[k]).ptr_next;
    }
    printf("\n");
}

void Recalloc(List* list, size_t new_capacity)
{
    assert(list != nullptr);

    List_Elem* l = list->list;
    l = (List_Elem*) realloc(list->list, new_capacity * sizeof(List_Elem));
    if (l == nullptr)
    {
        printf("Error recalloc memory\n");
        return;
    }

    list->list = l;
    list->capacity = new_capacity;
    for(size_t i = list->size; i < list->capacity; ++i)
    {
        list->list[i].ptr_next = i + 1;
        list->list[i].ptr_prev = i - 1;
        list->list[i].elem = 0;
    }
    list->list[list->size].ptr_prev = -1;
    list->list[list->capacity - 1].ptr_next = list->free;

    list->free = list->size;
}
