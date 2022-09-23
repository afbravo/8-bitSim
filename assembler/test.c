#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main()
{
    int *a = (int *)malloc(10);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;
    a[6] = 7;
    a[7] = 8;
    a[8] = 9;
    a[9] = 10;
    a[10] = 11;
    a[11] = 12;

    for (int i = 0; i < 12; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}