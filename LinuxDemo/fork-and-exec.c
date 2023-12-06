#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>

int hello(void);

static void child()
{
    char *args[] = {"/bin/echo","hello", NULL};
    printf("子进程 %d \n",(int)getpid());
    // fflush(stdout);
    execve("/bin/echo",args, NULL);
    err(EXIT_FAILURE,"exec() failed");
}

static void father(pid_t pid_c)
{
    printf("父进程 %d, 子进程 %d \n",(int)getpid(), (int)pid_c);
    hello();
    exit(EXIT_SUCCESS);  // 修正为成功退出状态
}

int main(void)
{
    pid_t ret;
    ret = fork();
    if (ret == -1)
        err(EXIT_FAILURE,"fork() 出错");
    if (ret==0){
        child();
    }else{
        father(ret);
    }
}
