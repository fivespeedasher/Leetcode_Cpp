#include "swap.h"

void swap(int *p, int *q)
{
    if (p != q)
    {
        *p = *p ^ *q;
        *q = *p ^ *q;
        *p = *p ^ *q;
    }   
}
