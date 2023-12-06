cd LinuxDemo
strace 追踪进程的系统调用
`strace -T -o hello.log ./hello`
-T 显示时间

sar 命令用来获取进程分别在用户模式与内核模式下运行的时间比例。
`sar -P ALL 1`

Linux 提供了 ldd 命令，用查看程序所依赖的库。

运行 fork
`cc -o fork fork.c`
./fork

引用的话要一起编译
`cc -o fork-and-exec fork-and-exec.c hello.c`



