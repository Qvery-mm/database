//
// Created by aleks on 11.12.2018.
//
#include "algo.h"

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
