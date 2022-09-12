/*
 *  Compiler for 8 bit computer
 *
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int openfile(char *filename);
int getContent(char *filename);
char compile();
int save_file();


int main(int argc, char **argv)
{
    // options for compiler
    // -h -> help
    // -o -> output file  

    if(argc < 2) //user did not specify any file
    {
        printf("Error: No arguments specified\n");
        printf("Usage: comp [options] file\n");  //CHANGE COMP TO THE NAME OF THE EXECUTABLE
    }

    char* outputFileName = "out.bin";
    char* inputFileName = NULL;

    for(int i = 1; i < argc; i++) //loop through all arguments
    {
        if(argv[i][0] == '-') //if argument is an option
        {
            switch(argv[i][1])
            {
                case 'h': //display help message
                    printf("Usage: comp [options] file\n"); //ADD MORE HELP INFO
                    return 0;
                case 'o': //change output file name
                    outputFileName = argv[i + 1];
                    break;
            }
        
        }
        else //if argument is NOT and option check for file name and type
        {
            //check if it ends in .s
            if(strstr(argv[i], ".s") != NULL)
            {
                inputFileName = argv[i];
            }
        }
    }

    if(inputFileName == NULL) //if no file name was specified exit
    {
        printf("Error: No input file specified or incorrect type\n");
        return 1;
    }

    //open file

}