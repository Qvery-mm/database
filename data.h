//
// Created by aleks on 11.12.2018.
//

#ifndef DATABASE_ITEM_H
#define DATABASE_ITEM_H


#include <stdio.h>
typedef struct
{
    size_t id;
    char name[100];
    int count;
    int coast;
} item;

void saveData(size_t n, item *p, const char *filename);
item *uploadData(size_t *length, const char *filename);
int new_database(const char *filename);
void new_position(item sample, size_t length, item *data, const char *filename);
item *erase_item(size_t *length, item *data, size_t id, const char *filename);
#endif //DATABASE_ITEM_H
