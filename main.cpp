#include <stdio.h>
#include "list_func.h"
/*
ПРИ РЕАЛОКЕ У КАЖДОГО ЭЛЕМЕНТА NEXT_PTR И PREV_PTR ДОЛЖНЫ МЕНЯТЬСЯ
*/
int prost[1000];
int size = 0;

int main()
{
    List a;
    ListCtor(&a);
    for(int i = 0; i < 1000; ++i)
    {
        ListPush(&a, i, -1);
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