//
// Created by aleks on 11.12.2018.
//
#include "data.h"
#include <stdio.h>

void uploadData(size_t n, item *p, const char* filename)
{
    FILE *fp = fopen(filename, "rb");
    if(fread(p, sizeof(item), n, fp) == 0)
    {
        printf("Not found");
        return;
    }
    fclose(fp);
}


void saveData(size_t n, item *p, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    fwrite(p, sizeof(item), n, fp);
    fclose(fp);
}