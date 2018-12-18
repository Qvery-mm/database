//
// Created by aleks on 11.12.2018.
//
#include "algo.h"
#include "data.h"
#include <string.h>

/*
 * Following procedure swap two objects
 * @param a - first pointer void*
 * @param b - second pointer void*
 * @param len - sizeof(a)
 * @return none
 */
void swap_items(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (int i = 0; i != len; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
//size_t id;
//char name[100];
//char manufacturer[100];
//int price;
//int count;
//int size;
//int released;
//int income;
//int profit;
typedef int (*tf) (const item *, const item *);

int idCmp(const item *a, const item *b) {return a->id < b->id;}
int priceCmp(const item *a, const item *b) {return a->price < b->price;}
int countCmp(const item *a, const item *b) {return a->count < b->count;}
int sizeCmp(const item *a, const item *b) {return a->size < b->size;}
int releasedCmp(const item *a, const item *b) {return a->released < b->released;}
int incomeCmp(const item *a, const item *b) {return a->income < b->income;}
int profitCmp(const item *a, const item *b) {return a->profit < b->profit;}

int nameCmp(const item *a, const item *b){return (strcmp(a->name, b->name) < 0) ? 1 : 0;}
int manufacturerCmp(const item *a, const item *b) {return (strcmp(a->manufacturer, b->manufacturer) < 0) ? 1 : 0;}

void sort(size_t length, item **data, int reverse, tf cmp)
{
    for(size_t i = 0; i < length; i++)
        for(size_t j = i; j < length; j++)
        {
            if(cmp(data[i], data[j]) ^ reverse)
                swap_items(&data[i], &data[j], sizeof(*data));
        }
}
