#include "fifo.h"
#include <ctype.h>

void data_consumer(int mod)
{
    int res;
    int bytes_read = 0;
    char buffer[BUFFER_SIZE + 1];
    int pipe_fd;

    printf("Process %d opening FIFO\n", getpid());
    pipe_fd = open(FIFO_NAME, mod);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if(pipe_fd != -1)
    {
        do
        {
            res = read(pipe_fd,buffer,BUFFER_SIZE);
            bytes_read += res;
        } while(res > 0);

        (void) close(pipe_fd);
    }
    else
    {
        exit(0);
    }
    printf("process %d finished,%d bytes read\n",getpid(),bytes_read);
}

int main(int argc, char **argv)
{
    int open_mode = 0;
    int i;
 
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s <some combination of\
                    O_RDONLY O_WRONLY O_NONBLOCK>\n", *argv);
        exit(1);
    }

    for(i = 1; i < argc; i++) 
    {
        if (strncmp(*++argv, "O_RDONLY", 8) == 0)
                open_mode |= O_RDONLY;
        if (strncmp(*argv, "O_WRONLY", 8) == 0)
                open_mode |= O_WRONLY;
        if (strncmp(*argv, "O_NONBLOCK", 10) == 0)
                open_mode |= O_NONBLOCK;
    }            
    data_consumer(open_mode);
}