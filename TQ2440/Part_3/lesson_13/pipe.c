/**************************************************************************************
作者：guiqnglei
时间：2017.7.3
介绍：熟悉无名管道的相关操作的使用
**************************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************************************
函数：read_popen/write_popen
参数：无
功能：《linux程序设计》一书中使用popen启动shell来建立管道，并且从标准输出中读取数据，向标准输入中写入数据
**************************************************************************************/
void  read_popen()
{
    FILE *read_fp;
    char buffer[BUFSIZ +1];
    int chars_read;

    memset(buffer,'\0',sizeof(buffer));

    read_fp = popen("uname -a","r");
    if(read_fp != NULL)
    {
        chars_read = fread(buffer,sizeof(char),BUFSIZ/10,read_fp);
        while(chars_read)
        {
            buffer[chars_read - 1] = '/0';
            printf("reading %d:-\n %s\n",BUFSIZ/10,buffer);
            chars_read = fread(buffer,sizeof(char),BUFSIZ/10,read_fp);
        }
        fclose(read_fp);
        exit(0);
    }
    exit(0);

}


void write_popen()
{
    FILE *write_fp;
    char buffer[BUFSIZ +1];

    sprintf(buffer, "once upon a time, there was...\n");
    write_fp = popen("od -c","w");
    if(write_fp != NULL)
    {
        fwrite(buffer,sizeof(char),strlen(buffer),write_fp);
        fclose(write_fp);
        exit(0);
    }
    exit(0);    
}

/**************************************************************************************
函数：read_popen/write_popen
参数：无
功能：《linux程序设计》一书中使用popen启动shell来建立管道，并且从标准输出中读取数据，向标准输入中写入数据
**************************************************************************************/
void data_processed()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "hello data";
    char buffer[BUFSIZ+1];
    pid_t fork_result;

    memset(buffer,'\0',sizeof(buffer));

    if(pipe(file_pipes) == 0)
    {
        fork_result = fork();
        if(fork_result == (pid_t) -1)
        {
            fprintf(stderr,"Fork failure");
            exit(0);
        }

        if(fork_result == 0)
        {
            printf("go into child\n");
            sprintf(buffer,"%d",file_pipes[0]);
            (void) execl("data_consumer","data_consumer",buffer,(char *) 0);
            exit(0);
        }

        else
        {
            data_processed = write(file_pipes[1],some_data,strlen(some_data));
            printf("%d - wrote %d bytes\n",getpid(),data_processed);
        }
    }
    exit(0);
}


/**************************************************************************************
函数：read_popen/write_popen
参数：无
功能：《linux程序设计》一书中使用popen启动shell来建立管道，并且从标准输出中读取数据，向标准输入中写入数据
**************************************************************************************/
void data_processed2()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "hello data";
    char buffer[BUFSIZ+1];
    pid_t fork_result;

    memset(buffer,'\0',sizeof(buffer));

    if(pipe(file_pipes) == 0)
    {
        fork_result = fork();
        if(fork_result == (pid_t) -1)
        {
            fprintf(stderr,"Fork failure");
            exit(0);
        }

        if(fork_result == 0)
        {
            close(0);
            dup(file_pipes[0]);
            close(file_pipes[1]);
            close(file_pipes[0]);
            execlp("od","od","-c",(char *)0 );
            exit(0);
        }

        else
        {
            close(file_pipes[0]);
            data_processed = write(file_pipes[1],some_data,strlen(some_data));
            close(file_pipes[1]);
            printf("%d - worte %d bytes\n",getpid(),data_processed);
        }
    }
    exit(0);
}

int main(int argc,char **argv)
{
    int number;
    printf("please select your function：\n");           //输出显示
    printf("    1.select read_popen\n");
    printf("    2.select write_popen\n");
    printf("    3.select data_processed\n");
    printf("    4.select data_processed2\n");
    printf("before you select 3,you should be have data_consumer file\n");
    printf("please input number:");
    scanf("%d",&number);                                //选择执行函数
    switch(number)
    {
        case 1: read_popen();break;
        case 2: write_popen();break;
        case 3: data_processed();break;
        case 4: data_processed2();break;
        default:printf("The input number is wrong");
    }

}