//
// Created by aleks on 11.12.2018.
//

#ifndef DATABASE_ITEM_H
#define DATABASE_ITEM_H
#include <stdio.h>
typedef struct
{
    char name[100];
    int count;
    int coast;
} item;

void saveData(size_t n, item *p, const char *filename);
void uploadData(size_t n, item *p, const char *filename);

#endif //DATABASE_ITEM_H
