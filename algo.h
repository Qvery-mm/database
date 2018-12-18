//
// Created by aleks on 11.12.2018.
//

#ifndef DATABASE_ALGO_H
#define DATABASE_ALGO_H

#include <stdlib.h>
#include "data.h"

void swap_items(void * a, void * b, size_t len);
//void sortByCoast(size_t length, item **data, int reverse);
typedef int (*tf) (const item *, const item *);

int idCmp(const item *a, const item *b);
int priceCmp(const item *a, const item *b);
int countCmp(const item *a, const item *b);
int sizeCmp(const item *a, const item *b);
int releasedCmp(const item *a, const item *b);
int incomeCmp(const item *a, const item *b);
int profitCmp(const item *a, const item *b);

int nameCmp(const item *a, const item *b);
int manufacturerCmp(const item *a, const item *b);

void sort(size_t length, item **data, int reverse, tf cmp);

#endif //DATABASE_ALGO_H
