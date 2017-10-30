
/*antMaze.h*/

#ifndef _TEST_H_
#define _TEST_H_

#define SIZE 11

//some symbols for indicating the situation of the road
#define WIN 3
#define DEATH 2
#define BLOCKS 1
#define ALREADY 4
#define ALLOW 0

#define WIN_I 9
#define WIN_J 8

#define START_I 7
#define START_J 1

extern int maze[SIZE][SIZE];
struct position
{
    int i;
    int j;
};
typedef struct position position;

int antMaze(void);

//clear the death symbols
void clearTheMaze(void);

void printTheMaze(void);
#endif
