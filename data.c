//
// Created by aleks on 11.12.2018.
//
#include "data.h"
#include "algo.h"
#include <stdio.h>
#include <stdlib.h>

item *uploadData(size_t *length, const char* filename)
{
    FILE *fp = fopen(filename, "rb");

    if(fread(length, sizeof(size_t), 1, fp) == 0)
    {
        printf("Not found");
        return NULL;
    }
    item *p = malloc(*length * sizeof(item));
    if(fread(p, sizeof(item), *length, fp) == 0)
    {
        printf("Not found");
        return NULL;
    }
    fclose(fp);
    return p;
}


void saveData(size_t n, item *p, const char *filename)
{
    FILE *fp = fopen(filename, "wb");

    fwrite(&n, sizeof(size_t), 1, fp);
    fwrite(p, sizeof(item), n, fp);
    fclose(fp);
}

/*
 *
 * @return 0 - if successful
 * @return 1 - if the same file exists
 * @return 2 - another exception
 */
int new_database(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp !=  NULL) // file exists
    {
        fclose(fp);
        return 1;
    }
    fclose(fp);
    size_t n = 0;
    saveData(0, NULL, filename);
    return 0;
}

item *erase_item(size_t *length, item *data, size_t id, const char *filename)
{
    for(size_t i = 0; i < *length; i++)
    {
        if(data[i].id == id)
        {
            swap_items(&data[i], &data[(*length)-1], sizeof(item));
            (*length)--;
            data = realloc(data, (*length) * sizeof(item));
            break;
        }
    }
    for(size_t i = 0; i < *length; i++)
    {
        data[i].id = i;
    }

    saveData(*length, data, filename);
    return data;
}

