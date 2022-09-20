#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int main()
// {
//     FILE *fptr;
//     fptr = fopen("test.txt", "r");
//     if (fptr == NULL)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     char instruction[3];
//     int *number;

//     while (fscanf(fptr, "%s %d", instruction, number) == 2)
//     {
//         printf("%s %d\n", instruction, *number);
//     }

//     printf("\n");
//     fclose(fptr);
//     return 0;
// }

unsigned char translate(const char *instruction)
{
    if (strcmp(instruction, "lda") == 0)
    {
        return 1 << 4;
    }
    else if (strcmp(instruction, "sta") == 0)
    {
        return 2 << 4;
    }
    else if (strcmp(instruction, "ldb") == 0)
    {
        return 3 << 4;
    }
    else if (strcmp(instruction, "stb") == 0)
    {
        return 4 << 4;
    }
    else if (strcmp(instruction, "add") == 0)
    {
        return 5 << 4;
    }
    else if (strcmp(instruction, "sub") == 0)
    {
        return 6 << 4;
    }
    else if (strcmp(instruction, "jmp") == 0)
    {
        return 7 << 4;
    }
    else if (strcmp(instruction, "jnz") == 0)
    {
        return 8 << 4;
    }
    else if (strcmp(instruction, "jnc") == 0)
    {
        return 9 << 4;
    }
    else if (strcmp(instruction, "hlt") == 0)
    {
        return 14 << 4;
    }
    else if (strcmp(instruction, "out") == 0)
    {
        return 15 << 4;
    }
    else
    {
        return 0;
    }
}

void something(int **a){
    int *b = malloc(sizeof(int));
    *b = 5;
    printf("b: %p\n", b);
    printf("a: %p\n", a);
    *a = b;
    printf("b: %p\n", b);
    printf("a: %p\n", a);
}

int main()
{
    int *a = malloc(sizeof(int));
    *a = 10;
    printf("%p\n", a);
    something(&a);
    printf("%p\n", a);
    return 0;
}