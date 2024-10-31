#ifndef LIST_FUNC_H
#define LIST_FUNC_H

#include "list.h"

void ListCtor(List* list);

void ListDtor(List* list);

void ListPush(List* list, list_t a, int ind);

void ListPrint(List* list);

#endif // LIST_FUNC_H