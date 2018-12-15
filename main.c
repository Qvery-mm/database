#include <stdio.h>
#include "algo.h"
#include "data.h"
#include <string.h>
#include "visualize.h"



int main() {

    item a[2];
    uploadData(2, a, "book.dat");
    printDatabase(2, a);

    return 0;
}