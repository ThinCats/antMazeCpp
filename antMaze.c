
#include<stdio.h>
#include<stack>
void antMaze(void)
{
    position current = {START_I, START_J};

    while(1)
    {
        if(current.i == WIN_I && current.j == WIN_J)
        {
            //����ֱ�����
            while(!(current.i == START_I && current.j == START_J))
            {
                current = stack_top();
                stack_del();

                maze[current.i][current.j] = WIN;    //���ʤ��������߳��Թ�·�ߣ�

            }
        }

        //����Ѱ�ҳ�·
        if(maze[current.i][current.j-1] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.j -= 1;
        }

        //����
        if(maze[current.i][current.j+1] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.j += 1;
        }

        //����
        if(maze[current.i+1][current.j] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.i += 1;
        }

        //����
        if(maze[current.i-1][current.j] == 0)
        {
            stack_push(&current);
            maze[current.i][current.j] = ALREADY;

            current.i -= 1;
        }

        //
        else
        {
            //��·���
            maze[current.i][current.j] = DEATH;

            //����
            current = *stack_top();
            stack_del();
            maze[current.i][current.j] = ALLOW;

        }
    }
}
