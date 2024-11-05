#ifndef LIST_FUNC_H
#define LIST_FUNC_H

#include "list.h"

void ListCtor(List* list);

void ListDtor(List* list);

void ListPush(List* list, list_t a, int ind);

void ListPushBack(List* list, list_t a);

void ListPop(List* list,  int ind);

void ListPopBack(List* list);

void ListPrint(List* list);

void Recalloc(List* list, size_t new_capacity);

#endif // LIST_FUNC_H