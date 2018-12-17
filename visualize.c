//
// Created by aleks on 11.12.2018.
//
#include "visualize.h"
#include "data.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NEWFILE "N"
#define ESCAPE "ESC"
#define NEWLINE "NL"
#define DELETE "DEL"
#define SORT "SORT"



void printItem(item a)
{
    printf("| %2lld | %10s | %10d | %10d |\n", a.id, a.name, a.count, a.coast);
}

void printDatabase(int n, item *p)
{
    system("CLS");
    for(int i = 0; i < 45; i++)
        printf("-");
    printf("\n");
    printf("| id |    name    |   count    |    coast   |\n");
    for(int i = 0; i < 45; i++)
        printf("-");
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printItem(p[i]);
        for(int i = 0; i < 45; i++)
            printf("-");
        printf("\n");

    }
    printf("\n");
}

item *get_new_info(size_t *length, item *data, const char *filename)
{
    data = realloc(data, (*length+1) * sizeof(item));
    if(!data)
    {
        printf("error");
        return NULL;
    }

    data[*length].id = *length;
    printf("Enter name:\n");
    getchar();
    gets(data[*length].name);

    //scanf("%s", data[length-1].name);
    printf("Enter coast:\n");
    scanf("%d", &data[*length].coast);
    printf("Enter count:\n");
    scanf("%d", &data[*length].count);
    (*length)++;
    saveData(*length, data, filename);
    return data;
}


void start_menu()
{
    size_t length = 0;
    item *data = malloc(0);

    printf("Enter filename or press %s for creating new datatbase:\n", NEWFILE);
    char s[20];
    gets(s);

    if(strcmp(s, NEWFILE) == 0)
    {
        printf("enter new filename:\n");
        gets(s);
        int callback = new_database(s);
        if(callback == 1) {
            printf("file already exists\n");
            system("PAUSE");
            return;
        }
    }
    else
    {
        data = uploadData(&length, s);
        printDatabase(length, data);
    }

    while(1)
    {
        char action[20];
        printf("select action: (ESC, NL, DEL)\n");
        scanf("%20s", action);
        if(!strcmp(action, ESCAPE))
            break;

        if(!strcmp(action, NEWLINE))
            data = get_new_info(&length, data, s);

        if(!strcmp(action, DELETE))
        {
            size_t id;
            printf("Input id:\n");
            scanf("%lld", &id);
            erase_item(&length, data, id, s);
        }

        //system("CLS");
        printDatabase(length, data);
    }
}
