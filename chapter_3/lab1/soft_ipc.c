#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int wait_flag;
void stop();
int main(void){
    int pid1, pid2, pid3;
    signal(3, stop);
    printf("Register a signal handler for signal 3.\n");
    while((pid1 = fork()) == -1);   //创建子进程1
    if(pid1 > 0)    //是父进程
    {
        printf("Process %d got a signal.\n", pid1);
        while((pid2 = fork()) == -1);   //创建子进程2
        if(pid2 > 0)    //是父进程
        {
            printf("Process %d got a signal.\n", pid2);
            wait_flag = 1;
            sleep(5);
            kill(pid1, 16);
            kill(pid2, 17);
            wait(0);
            printf("Parent processs exit normally!\n");
        }
        else                    //是子进程2
        {
            wait_flag = 1;
            signal(17, stop);
            printf("Child process 2 is killed by parent !!\n");     //打印信息
            while((pid3 = fork()) == -1);
            if(pid3 > 0){
                printf("Precess %d got a signal.\n", pid3);
            }
        }
    }
    else                    //是子进程1
    {
        wait_flag = 1;
        signal(16, stop);
        printf("Child process 1 is killed by parent !!\n");     //打印信息
    }
    return 0;
}
void stop()
{
    wait_flag = 0;
}
