#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>

static void child()
{
    printf("子进程，pid %d \n", getpid());
    exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c)
{
    printf("父进程 %d, 子进程 %d \n",getpid(),pid_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret;
    ret = fork();
    if (ret==-1)
        err(EXIT_FAILURE, "fork() failed");
    if (ret==0)
    {
        // fork 返回 0 为子进程
        child();
    }else{
        // 子进程的 id
        parent(ret);
    }
}