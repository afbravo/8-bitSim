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
void openFile(FILE *file, char *fileName);
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

void openFile(FILE *file, char *fileName)
{
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}

char *assemble(FILE *file)
{
    char *binary = malloc(MEMORY_SIZE * sizeof(char));
    size_t index = 0;
    char instruction[3];
    int *number;
    unsigned char byte;
    while (fscanf(file, "%s %d", instruction, number) == 2)
    {
        byte = translate(instruction) | *number;
        binary[index] = byte;
        index++;
    }
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

// print current binary
void print_binary(char *binary)
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        printf("%d\n", binary[i]);
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
    
    openFile(fptr, inputFileName);

    // compile file to binary
    char *binary = assemble(fptr);

    // print binary
    print_binary(binary);

    // save binary file
    // save_file(outputFileName, binary);
}