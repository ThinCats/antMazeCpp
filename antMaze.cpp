#include "antMaze.h"
#include<stdio.h>
#include <stack>
#include<cstdlib>
using namespace std;
int maze[SIZE][SIZE]
={
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,1,0,0,0,1,0,1},
{1,0,0,0,0,1,1,0,1,1},
{1,0,1,1,1,0,0,1,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,1,0,0,0,1,0,1,1},
{1,0,1,1,1,1,0,0,1,1},
{1,1,1,0,0,1,1,0,1,1},
{1,1,1,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};


int antMaze(void)
{
    stack<position> s;
    position current = {START_I, START_J};
    if(maze[WIN_I][WIN_J] == 1)
    {
        printf("No solution!\n");
        exit();

    }
    while(1)
    {
        printf("Now i=%d j=%d  :\n",current.i, current.j);
        printTheMaze();

        //判断胜利
        if(current.i == WIN_I && current.j == WIN_J)
        {

            //回溯直到起点
            while(!(current.i == START_I && current.j == START_J))
            {
                current = s.top();
                s.pop();
                //stack_del();

                maze[current.i][current.j] = WIN;//标记胜利（标记走出迷宫路线）

            }
            return 0;
        }

        //向左寻找出路
        else if(maze[current.i][current.j-1] == 0)
        {
            s.push(current);
            maze[current.i][current.j] = ALREADY;

            current.j -= 1;
        }

        //向右
        else if(maze[current.i][current.j+1] == 0)
        {
            s.push(current);
            maze[current.i][current.j] = ALREADY;

            current.j += 1;
        }

        //向下
        else if(maze[current.i+1][current.j] == 0)
        {
           s.push(current);
            maze[current.i][current.j] = ALREADY;

            current.i += 1;
        }

        //向上
        else if(maze[current.i-1][current.j] == 0)
        {
            s.push(current);
            maze[current.i][current.j] = ALREADY;

            current.i -= 1;
        }

        //
        else
        {
            //死路标记
            maze[current.i][current.j] = DEATH;

            //回溯
            current = s.top();
            s.pop();
            //stack_del();
            maze[current.i][current.j] = ALLOW;

        }
    }
}
void printTheMaze(void)
{
    int i, j;
    for(i = 0;i < SIZE;i++)
    {
        for(j = 0;j < SIZE;j++)
        {
            printf("%d", maze[i][j]);
        }
        putchar('\n');
    }

    putchar('\n');
    putchar('\n');
}
