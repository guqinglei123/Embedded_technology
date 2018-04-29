/*****************************************************************************************************************
作者：guiqnglei
时间：2017.6.26
介绍：通过系统底层调用的方式来访问linux系统文件，代码参考国嵌视频和《linux程序设计》一书
*****************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/*****************************************************************************************************************
函数：file_study
参数：无
介绍：国嵌视频中的熟悉文件操作的代码
*****************************************************************************************************************/
void file_study()
{
    int fd, fd1;
    char * buf="987456123";                                 //要写入字符串
    char buf1[10];
    int nread;

    fd = open("file_study",O_RDWR|O_CREAT,0755);            //按可读可写，不存在则创建的方式，打开文件。并且设置相应的权限。

    if(fd<0)                                                //打开失败的处理方式
    {
        printf("open file failed\n");
        return;
    }

    
    fd1 = dup(fd);                                          //复制文件描述符，？？与直接赋值有什么区别

    write(fd1,buf,7);                                       //将字符串写入打开的文件中

    lseek (fd1,2,SEEK_SET);                                 //将文件的指针定位到文件的第二个字符
    buf1[5] = "/0";                                         //给数组加上结束符号。使输出的字符串更有易读性？处理修改不好？
                                                            //这里使用“/0”，与‘/0’都还有警告？原因？
                                                            //在cpp文件编译时，如果给“/0”会报错，给‘/0’则正常。不过也有警告。
    if((nread = read(fd1,buf1,5)) > 0)                      //阅读数据，返回读取字节数
        printf("the buf is %s\n",buf1);
    printf("the read data size is %d\n",nread);
    close(fd1);                                             //关闭文件描述符

}

/*****************************************************************************************************************
函数：copy_system
参数：无
介绍：《linux程序设计》一书中使用系统底层调用的copy文件例程
*****************************************************************************************************************/

int copy_system()
{
    char block[1024]; 
    int in, out; 
    int nread;

    in = open("file.in", O_RDONLY);                         //以只读方式打开
    out = open("file2.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);//以只写方式打开，如果没有文件则创建，读写权限属于用户
    while((nread = read(in,block,sizeof(block))) > 0)       //按1k读取和写入数据。该方式比系统调用时按字节调用效率高，
        write(out,block,nread);
}



int main(int argc, char ** argv)
{
    int number;
    printf("your argument have %d\n",argc);
    if(argc!=2)                                            //该参数数量包括了文件名字
        printf("you have only one argument,the argument should be 1 or 2\n");
    else
    {
        switch(argv[1][0])                                  //表示第二个参数中的第一个字符，注意这里应该是字符
        {
            case '1': file_study();break;
            case '2': copy_system();break;
            default:printf("The argv is wrong,the argument is %d\n",argv[1][0]);
        }
    }


    return 0;
}