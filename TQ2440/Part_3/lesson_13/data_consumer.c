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
void data_consumer(char *arg)
{
     int data_processed;
     char buffer[BUFSIZ + 1];
     int file_descriptor;

     memset(buffer,'\0',sizeof(buffer));
     sscanf(arg,"%d",&file_descriptor);
     data_processed = read(file_descriptor,buffer,BUFSIZ);

     printf("%d - read %d bytes: %s\n",getpid(),data_processed,buffer);
     exit(0);
}
int main(int argc,char **argv)
{
    data_consumer(argv[1]);

}