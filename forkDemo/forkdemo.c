#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int r = 0;
    for (int i=0;i<2;i++){
        // 创建子进程
        pid = fork();
        printf("i:%d ,PID:%d, pid:%d \n",i,getpid(),pid);
        if (pid==0){
            r += 2;
        }else{
            r += 1;
        }
        printf("%d\n",r);
    }
    printf("线程结束：%d\n",getpid());
    return 0;
}
