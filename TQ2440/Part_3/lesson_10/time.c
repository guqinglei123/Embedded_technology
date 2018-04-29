/**************************************************************************************
作者：guiqnglei
时间：2017.6.27
介绍：熟悉时间的相关操作的使用
**************************************************************************************/


#include<time.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char ** argv)
{
    time_t the_time1,the_time2;
    the_time1 = time((time_t *) 0);//返回从纪元开始到选择的秒数
    printf("the time1 is %ld\n",the_time1);
    sleep(2);                       //系统睡眠2s
    //the_time2 = time((time_t *) 0);
    (void) time(&the_time2);    //和获得time1的方式一样，不同的写法
    printf("the time2 is %ld\n",the_time2);
    printf("the error of time is %d\n",(int)(the_time2-the_time1));//得到时间差
    printf("the diff of time is %f\n",difftime(the_time2,the_time1));

    struct tm *tm_ptr;
    tm_ptr = gmtime(&the_time2);       //将时间转换为标准时间（UTC/GMT），可以在命令行中使用data中获得当时时间

    printf("gmtime: date: %02d/%02d/%02d\n",tm_ptr->tm_year, tm_ptr->tm_mon+1,tm_ptr->tm_mday);
    printf("gmtime: time: %02d:%02d:%02d\n",tm_ptr->tm_hour, tm_ptr->tm_min,tm_ptr->tm_sec);

    tm_ptr = localtime(&the_time2);     //将时间转换为本地时间。
    printf("localmtime: date: %02d/%02d/%02d\n",tm_ptr->tm_year, tm_ptr->tm_mon+1,tm_ptr->tm_mday);
    printf("localmtime: time: %02d:%02d:%02d\n",tm_ptr->tm_hour, tm_ptr->tm_min,tm_ptr->tm_sec);
 
    printf("ctime: the data is:%s",ctime(&the_time2)); //让时间转换为本地时间并且按字符串输出
    printf("asctime: the data is:%s",asctime(tm_ptr)); //让时间转换为本地时间并且按字符串输出

    return 0;
}