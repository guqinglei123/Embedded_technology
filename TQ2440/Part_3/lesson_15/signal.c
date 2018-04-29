/**************************************************************************************
作者：guiqnglei
时间：2017.6.27
介绍：熟悉信号的相关操作的使用
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
/**************************************************************************************
函数：fork_study
参数：无
功能：《linux程序设计》一书中模拟一个闹钟的程序，并且使用了sigaction函数进行改善
**************************************************************************************/

static int alarm_fired = 0;

void ding(int sig)                  //接受到信号转换的中断处理函数，在信号处理函数中使用printf是不安全的
{
    alarm_fired = 1;
}

void alarm_signal()
{
    pid_t pid ;
    printf("alarm_signal program starting\n");
    pid = fork();                       //获取PID

    switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
    {
        case -1: perror("fork failed");exit(1);
        case  0:sleep(5), kill(getppid(),SIGALRM);exit(0);  //在子进程中等待5s中，并且向主进程中发送信号
    }

    printf("waiting for alarm to go off\n");                

//    (void) signal(SIGALRM,ding);    //设置信号的处理方式，处理了一次之后该信号会恢复默认处理方式，容易产生竞态情况

    struct sigaction act;

    act.sa_handler = ding;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGALRM,&act,0);        //更有用的信号接口函数，可以消除竞态情况，不过在处理之后不好出现被重置。

    pause();                          //将程序的执行挂起，直到有一个信号出现为止

    if(alarm_fired)
        printf("Ding！\n");
    printf("done\n");
 //   exit(0);

}



int main(int argc, char ** argv)
{
    alarm_signal();
}