//
// Created by aleks on 11.12.2018.
//
#include "visualize.h"
#include "data.h"
#include "algo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



#define NEWFILE "NEW"
#define ESCAPE "EXIT"
#define NEWLINE "NL"
#define DELETE "DEL"
#define SORT "SORT"



void printItem(item a)
{
    printf("| %5lld | %11s | %17s | %7d | %13d | %9d | %10d | %10d | %10d |\n",
            a.id, a.name, a.manufacturer, a.price, a.count, a.size, a.released, a.income, a.profit);
}

void printDatabase(size_t n, item **p)
{
    const int N = 120;
    system("CLS");
    for(int i = 0; i < N; i++)
        printf("-");
    printf("\n");
    printf("| id(0) | Название(1) |  Производитель(2) | Цена(3) | Количество(4) | Размер(5) | Продано(6) | Выручка(7) | Прибыль(8) |\n");
    for(int i = 0; i < N; i++)
        printf("-");
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printItem(*p[i]);
        for(int j = 0; j < N; j++)
            printf("-");
        printf("\n");

    }
    printf("\n");
}



item *get_new_info(size_t *length, item *data, const char *filename)
{
    data = realloc(data, ((*length)+1) * sizeof(item));
    if(!data)
    {
        //костыль
        data = malloc(sizeof(item));
        //printf("Ошибка");
        //system("PAUSE");
        //return NULL;
    }


    //size_t id;
    data[*length].id = *length;

    //char name[100];
    printf("Название:\n");
    getchar();
    gets(data[*length].name);

    //char manufacturer[100];
    printf("Производитель:\n");
    //getchar();
    gets(data[*length].manufacturer);

    //int price;
    printf("Цена:\n");
    scanf("%d", &data[*length].price);

    //int count;
    printf("Количество:\n");
    scanf("%d", &data[*length].count);

    //int size;
    printf("Размер:\n");
    scanf("%d", &data[*length].size);

    //int released;
    printf("Продано:\n");
    scanf("%d", &data[*length].released);

    //int income;
    printf("Выручка:\n");
    scanf("%d", &data[*length].income);

    //int profit;
    printf("Прибыль:\n");
    scanf("%d", &data[*length].profit);

    (*length)++;
    saveData(*length, data, filename);
    return data;
}


void start_menu()
{
    //setlocale(LC_ALL, "Russian");
    size_t length = 0;
    item *data = malloc(0);
    item **Pdata = malloc(0);
    printf("Введите имя файла, или введите %s чтобы создать новую базу данных:\n", NEWFILE);
    char s[20];
    gets(s);

    if(strcmp(s, NEWFILE) == 0)
    {
        printf("Введите новое имя файла:\n");
        gets(s);
        int callback = new_database(s);
        if(callback == 1) {
            printf("Файл с таким именем уже существует\n");
            system("PAUSE");
            return;
        }
    }
    else
    {
        data = uploadData(&length, s);
        if(data == NULL)
        {
            printf("Файл не найден.\n");
            system("PAUSE");
            return;
        }
        Pdata = data_to_pointers(length, data, Pdata);
        printDatabase(length, Pdata);
    }

    while(1)
    {
        char action[20];
        printf("Выберите действие: (%s для выхода, %s - добавить строку,"
               " %s - удалить строку, %s - сортировать)\n", ESCAPE, NEWLINE, DELETE, SORT);
        scanf("%10s", action);

        if(!strcmp(action, ESCAPE))
            break;

        if(!strcmp(action, NEWLINE))
        {
            data = get_new_info(&length, data, s);
            Pdata = data_to_pointers(length, data, Pdata);
        }

        if(!strcmp(action, DELETE))
        {
            size_t id;
            printf("Введите id:\n");
            scanf("%lld", &id);
            erase_item(&length, data, id, s);
            Pdata = data_to_pointers(length, data, Pdata);
        }

        if(!strcmp(action, SORT))
        {
            int row, reversed;
            printf("По какому столбцу отсортировать?(0 - 10)\n");
            scanf("%d", &row);
            printf("В обратном порядке? 1 - да, 0 - нет\n");
            scanf("%d", &reversed);
            reversed = !reversed;

            switch(row)
            {
                case 0:
                    sort(length, Pdata, reversed, idCmp);
                    break;
                case 1:
                    sort(length, Pdata, reversed, nameCmp);
                    break;
                case 2:
                    sort(length, Pdata, reversed, manufacturerCmp);
                    break;
                case 3:
                    sort(length, Pdata, reversed, priceCmp);
                    break;
                case 4:
                    sort(length, Pdata, reversed, countCmp);
                    break;
                case 5:
                    sort(length, Pdata, reversed, sizeCmp);
                    break;
                case 6:
                    sort(length, Pdata, reversed, releasedCmp);
                    break;
                case 7:
                    sort(length, Pdata, reversed, incomeCmp);
                    break;
                case 8:
                    sort(length, Pdata, reversed, profitCmp);
                    break;
            }


        }

        //system("CLS");
        printDatabase(length, Pdata);
    }
}
