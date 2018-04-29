/**************************************************************************************
作者：guiqnglei
时间：2017.6.27
介绍：熟悉进程的相关操作的使用
**************************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**************************************************************************************
函数：fork_study
参数：无
功能：《linux程序设计》一书中创建多进程以及等待子进程结束的代码
**************************************************************************************/
void fork_study()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid = fork();                       //获取PID

    switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
    {
        case -1: perror("fork failed");exit(1);
        case  0: message = "this is the child\n";n=5;exit_code=37;break;
        default: message = "this is the parent\n";n=3;exit_code=0;
                printf("the pid of new fork process in parent is %d\n ",pid);
                break;
    }

    for(; n>0; n--)                     //打印相应的信息
    {
        printf("%s",message);
 //       puts(message);
        sleep(1);
    }

    if(pid != 0)                        //当子进程结束之后才结束主进程
    {
        int sta_val;
        pid_t child_pid;
        child_pid = wait(&sta_val);    //等待子进程结束，返回子进程pid

        printf("child has finished: PID= %d\n",child_pid);

        if(WIFEXITED(sta_val))         //判断子进程是否正常结束，如果正常退出则返回一个退出码
            printf("child exit with the code %d\n",WIFEXITED(sta_val));
        else
            printf("child terminated abnomally");
    }
    exit(exit_code);                    //退出进程并且返回退出码，似乎在函数中无法实现,因为是主函数退出才是结束进程
}
/**************************************************************************************
函数：vfork_study
参数：无
功能：与上一个函数比较，查看他的输出顺序，子父进程的输入输出顺序
**************************************************************************************/
void vfork_study()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting\n");
    pid = vfork();                       //获取PID,vfork下会先运行子进程阻塞父进程

    switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
    {
        case -1: perror("fork failed");exit(1);
        case  0: message = "this is the child\n";n=5;exit_code=37;break;
        default: message = "this is the parent\n";n=3;exit_code=0;
                printf("the pid of new fork process in parent is %d\n ",pid);
                break;
    }

    for(; n>0; n--)                     //打印相应的信息
    {
 //         printf("%s",message);
        puts(message);
        sleep(1);
    }
    exit(0);                           //在使用vfork时，不能少了该语句，否则会造成出错误
                                       //子进程的退出只能使用exit                                    
}

/**************************************************************************************
函数：fork_count/vfork_count
参数：无
功能：比较两个函数的不同，参考国嵌视频
**************************************************************************************/
void fork_count()
{
    int count;
    pid_t pid;

    pid = fork();

    count++;
    switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
    {
        case -1: perror("fork failed");exit(1);
        case  0: printf("the count in child is %d\n",count);break;      //输出为1
        default: printf("the count in parent is %d\n",count);            //输出为1
                 printf("the pid of new fork process in parent is %d\n ",pid);
                 break;
    }
    exit(0);
}

void vfork_count()
{
    int count;
    pid_t pid;

    pid = vfork();

    count++;
    switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
    {
        case -1: perror("fork failed");exit(1);
        case  0: printf("the count in child is %d\n",count);break;      //输出为1
        default: printf("the count in parent is %d\n",count);           //输出为2，与上函数不同的原因，
                                                                        //在于fork会有独立的数据段与栈而vfork没有
                 printf("the pid of new fork process in parent is %d\n ",pid);
                 break;
    }
    exit(0);
}
/**************************************************************************************
函数：while_fork/while_vfork
参数：无
功能：进一步理解两个函数的区别
**************************************************************************************/ 
void while_fork()
{
   int i;
   pid_t pid;
   for (i=0; i<2; i++) 
   {
      pid = fork();
      switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
      {
        case -1: perror("fork failed");exit(1);
        case  0: printf("the - in child\n");break;   //会打印6个符号出来，其中会三个子进程，第一个创建的子进程
        default: printf("the - in parent,and the child pid is %d\n",pid);//以及父进程会输出两个,后面两个进程只是输出一个，
                                                    //其中第一个创建的子进程也创建了一个进程
                break;
      }                            
                                
   }
   exit(0);
}


void while_vfork()
{
   int i;
   pid_t pid;
   for (i=0; i<2; i++) 
   {
      pid = vfork();
      switch(pid)                         //根据pid判断是父进程还是子进程，或者错误，当返回0表示该进程为子进程
      {
        case -1: perror("fork failed");exit(1);
        case  0: printf("the - in child\n");break;   //会打印4个符号出来？？？
        default: printf("the - in parent,and the child pid is %d\n",pid);
                                                    
                break;
      }                            
                                
   }
   exit(0);
}

/**************************************************************************************
函数：system_study
参数：无
功能：system函数的学习
**************************************************************************************/ 
void system_study()
{
    printf("runing ps with system\n");
    system("ps ax &");              //使用system调用shell命令参数，通过查看Done 明白加不加&的区别
    printf("Done. \n");
    exit(0);
}

/**************************************************************************************
函数：execlp_study
参数：无
功能：execlp函数的学习
**************************************************************************************/ 
void execlp_study()
{
    printf("runing ps with execlp\n");
    execlp("ps","ps","ax",0);       //execlp第一个参数是在PATH中寻找可执行文件，其中/bin在path中。第二个第三个则是命令的参数。
                                    //ps会替代execlp程序，ps执行完成转换，不会返回execlp中。（Done是执行不了的）
    printf("Done. \n");
    exit(0);
}


int main(void) 
{
    int number;
    printf("please select your function：\n");           //输出显示
    printf("    1.select fork_study\n");
    printf("    2.select vfork_study\n");
    printf("    3.select fork_count\n");
    printf("    4.select vfork_count\n");
    printf("    5.select while_fork\n");
    printf("    6.select while_vfork\n");
    printf("    7.command ls\n");
    printf("    8.system_study\n");
    printf("    9.execlp_study\n");
    printf("please input number:");
    scanf("%d",&number);                                //选择执行函数
    switch(number)
    {
        case 1: fork_study();break;
        case 2: vfork_study();break;
        case 3: fork_count();break;
        case 4: vfork_count();break;
        case 5: while_fork();break;
        case 6: while_vfork();break;
        case 7: execl("/bin/ls","ls",".",NULL);break;   //替换了原先的进程，不会产生的进程，而fork会产生
        case 8: system_study();break;
        case 9: execlp_study();break;
        default:printf("The input number is wrong");
    }

}