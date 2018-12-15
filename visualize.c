//
// Created by aleks on 11.12.2018.
//
#include "visualize.h"
#include "data.h"
#include <string.h>
#include <stdlib.h>

#define NEWFILE "N"
#define ESCAPE "ESC"
#define NEWLINE "NL"
#define SORT "SORT"



void printItem(item a)
{
    printf("%s %d %d\n", a.name, a.count, a.coast);
}

void printDatabase(int n, item *p)
{
    for(int i = 0; i < n; i++)
        printItem(p[i]);
}

void start_menu()
{
    size_t length = 0;
    item *data;

    printf("Enter filename or press %s for creating new datatbase:\n", NEWFILE);
    char s[20];
    gets(s);

    if(strcmp(s, NEWFILE) == 0)
    {
        printf("enter new filename:\n");
        char filename[20];
        gets(filename);
        int callback = new_database(filename);
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
        printf("select action:\n");
        scanf("%20s", action);
        if(!strcmp(action, ESCAPE))
            break;

        system("CLS");
        printDatabase(length, data);
    }
}
