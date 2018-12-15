//
// Created by aleks on 11.12.2018.
//
#include "visualize.h"
#include "data.h"

void clrscr()
{
    const int N = 100;
    for(int i = 0; i < N; i++)
        printf("\n");
}

void printItem(item a)
{
    printf("%s %d %d\n", a.name, a.count, a.coast);
}

void printDatabase(int n, item *p)
{
    for(int i = 0; i < n; i++)
        printItem(p[i]);
}
