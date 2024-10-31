#include <stdio.h>
#include "list_func.h"

int main()
{
    List a;
    ListCtor(&a);
    ListPush(&a, 1, -1);
    ListPush(&a, 3, -1);
    ListPush(&a, 2, 1);
    ListPush(&a, 4, -1);
    ListPush(&a, 10, 2);
    ListPrint(&a);
    ListDtor(&a);
    return 0;
}