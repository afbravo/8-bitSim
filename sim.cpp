#include <iostream>
#include <fstream>
#include <string>


void sim(short *mem){
    int run = 1;

    short instruction;

    short pc = 0;
    const short rg0 = 0;
    short rg1 = 0;
    short rh2 = 0;
    short rg4 = 0;

    while(run){
        instruction = mem[pc];

        switch(instruction << 12){
            case 0:
                std::cout << "jump";
        }
    }
}

char* getMemory(const std::string fileName);

int main(){
    int a = 3;
    switch(a){
        case 0:
            std::cout << "0\n";
            break;
        case 1:
            std::cout << "1\n";
            break;
        case 2:
            std::cout << "2\n";
            break;
        default:
            std::cout << "default\n";
    }
    return 0;
}