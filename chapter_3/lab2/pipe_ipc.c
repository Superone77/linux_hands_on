#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int pid1, pid2;

int main(){
    int fd[2];
    char OutPipe[100],InPipe[100];
    while(pipe(fd)!=0);
    while((pid1=fork())==-1);
    if(pid1==0) //子进程中
    {
        lockf(fd[0],0,0);
        sprintf(OutPipe,"Child process 1 is sending message!\n");
        write(fd[1],OutPipe,50);
        sleep(5);
        lockf(fd[0],1,0);
        exit(0);
    }
    else{//父进程中
        while((pid2=fork())==-1);
        if(pid2==0)//子进程中
        {
            lockf(fd[0],0,0);//给读管道上锁
            sprintf(OutPipe,"Child process 2 is sending message! \n");
            write(fd[1],OutPipe,50);
            sleep(5);
            lockf(fd[0],1,0);
            exit(0);

        }
        else{
            wait(0);
            read(fd[0],InPipe,50);
            printf("%s\n", InPipe);
            wait(0);
            read(fd[0],InPipe,50);
            printf("%s\n",InPipe);
            exit(0);
        }

    }
}