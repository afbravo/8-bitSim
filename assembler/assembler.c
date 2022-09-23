/*
 *  Compiler for 8 bit computer
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 16

void processArgs(int argc, char **argv, char **inputFile, char **outputFile);
void openFile(FILE **file, char *fileName);
char *compile(FILE *file);
int save_file(char *fileName, char *data);
unsigned char translate(const char *instruction);

void processArgs(int argc, char **argv, char **inputFile, char **outputFile)
{
    if (argc < 2) // user did not specify any file
    {
        printf("Error: No arguments specified\n");
        printf("Usage: comp [options] file\n"); // CHANGE COMP TO THE NAME OF THE EXECUTABLE
        exit(1);
    }

    for (int i = 1; i < argc; i++) // loop through all arguments
    {
        if (argv[i][0] == '-') // if argument is an option
        {
            switch (argv[i][1])
            {
            case 'h':                                         // display help message
                printf("HELP\nUsage: comp [options] file\n"); // ADD MORE HELP INFO
                exit(0);
            case 'o': // change output file name
                *outputFile = argv[i + 1];
                break;
            }
        }
        else // if argument is NOT an option, check for file name and type
        {
            // check if it ends in .s
            if (strstr(argv[i], ".txt") != NULL)
            {
                *inputFile = argv[i];
            }
        }
    }

    if (*inputFile == NULL) // if no file name was specified exit
    {
        printf("Error: No input file specified or incorrect type\n");
        exit(1);
    }
}

unsigned char *assemble(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    // char *binary = malloc(MEMORY_SIZE * sizeof(char));
    // char *binary;
    unsigned char *binary = (unsigned char *)malloc(MEMORY_SIZE * sizeof(unsigned char));
    int *index = (int *)malloc(sizeof(int));
    *index = 0;
    char instruction[3];
    int number;
    while (feof(file) == 0 && *index < MEMORY_SIZE)
    {
        printf("index: %d\n", *index);
        fscanf(file, "%s %d", instruction, &number);
        printf("index: %d\n", *index);
        number &= 0xFF;
        binary[*index] = translate(instruction) | number;
        printf("%d\n", binary[*index]);
        (*index)++;
    }

    printf("----------\n");

    return binary;
}

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



int main(int argc, char **argv)
{
    // options for assembler
    // -h -> help
    // -o -> output file

    char *outputFileName = "out.bin";
    char *inputFileName = NULL;
    FILE *fptr;

    processArgs(argc, argv, &inputFileName, &outputFileName);

    // open file
    // compile file to binary
    unsigned char *binary = assemble(inputFileName);

    // print binary
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        printf("%d\n", binary[i]);
    }

    // save binary file
    // save_file(outputFileName, binary);
}