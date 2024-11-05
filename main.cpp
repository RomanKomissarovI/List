#include <stdio.h>
#include "list_func.h"
/*
СДЕЛАТЬ 3 МАССИВА PTR_NEXT, PTR_PREV, ELEMS, СТРУКРУТУ LIST_ELEM УБРАТЬ*/

int main()
{
    List a;
    ListCtor(&a);
    
    for(int i = 0; i < 1000; ++i)
    {
        ListPushBack(&a, i);
    }

    ListPrint(&a);
    printf("size: %d, capac: %d\n", a.size, a.capacity);
    
    printf("\n\n\n\n");

    for(int i = 0; i < 500; ++i)
    {
        ListPop(&a, i);
    }

    ListPrint(&a);
    printf("size: %d, capac: %d\n", a.size, a.capacity);
    
    ListDtor(&a);
    return 0;
}