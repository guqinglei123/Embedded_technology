#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	int dst =2000;
	
	/*���豸�ļ�*/
	fd = open("/dev/memdev1",O_RDWR);
	
	/*д������*/
	read(fd, &dst, sizeof(int));
	
	printf("dst is %d\n",dst);
	
	/*�ر��豸*/
	close(fd);
	
	return 0;	

}
