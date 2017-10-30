#include <cstdio>
#include "antMaze.h"
#include <iostream>
using namespace std;
void printTheMaze(void);

int main(void)
{
    //
    printTheMaze();

    //
    antMaze();

    //Output the solution
    printf("You win!!\n");
    printTheMaze();

    return 0;
}


