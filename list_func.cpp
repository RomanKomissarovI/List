#include <stdlib.h>
#include <stdio.h>
#include "list_func.h"

void ListCtor(List* list)
{
    list->list = (List_Elem*) calloc (list->capacity, sizeof(List_Elem));
    for (int i = 0; i < (int) list->capacity; ++i)
    {
        list->list[i].ptr_next = &(list->list[i + 1]);
        list->list[i].ptr_prev = &(list->list[i - 1]);
        list->list[i].elem = 0;
    }
    list->list[0].ptr_prev = nullptr;
    list->list[list->capacity - 1].ptr_next = nullptr;
    list->head = nullptr;
    list->free = &(list->list[0]);
}

void ListDtor(List* list)
{
    free(list->list);
    list->size = 0;
    list->capacity = 0;
    list->free = nullptr;
    list->head = nullptr;
}

void ListPush(List* list, list_t a, int ind)
{
    List_Elem* free_el = list->free;
    //printf("\nnext: %p, prev: %p, free: %p\n\n", list->free->ptr_next, list->free->ptr_prev, list->free);
    list->free = (list->free)->ptr_next;
    //printf("\nfree: %p\n\n", list->free);


    (*free_el).elem = a;
    if (list->head == nullptr)
    {
        (*free_el).ptr_next = nullptr;
        (*free_el).ptr_prev = nullptr;
        list->head = free_el;
    }
    else
    {
        if (ind == -1)
        {
            List_Elem* k = list->head;
            while (k->ptr_next != nullptr)
            {
                k = k->ptr_next;
            }

            (*free_el).ptr_next = nullptr;
            (*free_el).ptr_prev = k;
            k->ptr_next = free_el;
        }
        else
        {
            List_Elem* k = list->head;
            int ind_now = 0;
            while (ind_now != ind)
            {
                k = k->ptr_next;
                ind_now++;
            }

            (*free_el).ptr_next = k;
            (*free_el).ptr_prev = k->ptr_prev;
            (k->ptr_prev)->ptr_next = free_el;
            k->ptr_prev = free_el;
            //printf("prevvvvvv %d\n", (k->ptr_prev)->elem);
        }
    }

    list->size++;
    //printf("size: %d, free: %p, head: %p\n", list->size, list->free, list->head);
    //printf("h_ptr_next: %p, ptr_prev: %p, elem: %d", list->head->ptr_next, list->head->ptr_prev, list->head->elem);
}

void ListPrint(List* list)
{
    List_Elem* k = list->head;
    //printf("%p, size: %d\n", k, list->size);
    for(size_t i = 0; i < list->size; ++i)
    {
        printf("%d ", k->elem);
        k = k->ptr_next;
    }
}