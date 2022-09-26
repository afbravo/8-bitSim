#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    /*
    steps:
        1) get arguments
        2) read the file
        3) run simulation
    */
   
   char *fileName = NULL;
   
    process_arguments(argc, argv, fileName);

    // read the file
    unsigned char *memory = read_file(fileName);

    // run simulation
    run_simulation(memory, MAX_PC_STEPS);
}