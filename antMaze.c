
#include<stdio.h>
#include<stack>
void antMaze(void)
{
    position current = {START_I, START_J};

    while(1)
    {
        if(current.i == WIN_I && current.j == WIN_J)
        {
            //回溯直到起点
            while(!(current.i == START_I && current.j == START_J))
            {
                current = stack_top();
                stack_del();

                maze[current.i][current.j] = WIN;    //标记胜利（标记走出迷宫路线）

            }
        }

        //向左寻找出路
        if(maze[current.i][current.j-1] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.j -= 1;
        }

        //向右
        if(maze[current.i][current.j+1] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.j += 1;
        }

        //向上
        if(maze[current.i+1][current.j] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.i += 1;
        }

        //向下
        if(maze[current.i-1][current.j] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.i -= 1;
        }

        //
        else
        {
            //死路标记
            maze[current.i][current.j] = DEATH;

            //回溯
            current = *stack_top();
            stack_del();
            maze[current.i][current.j] = ALLOW;

        }
    }
}
