#include "fifo.h"
#include <ctype.h>
int data_processed(int mod)
{
    int res;
    int bytes_sent = 0;
    char buffer[BUFFER_SIZE + 1];
    int pipe_fd;

    if(access(FIFO_NAME,F_OK) == -1)
     {
        res = mkfifo(FIFO_NAME,0777);
        if(res != 0)
        {
            fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
            exit(1);            
        }
     }

    printf("Process %d opening FIFO\n", getpid());
    pipe_fd = open(FIFO_NAME, mod);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if(pipe_fd != -1)
    {
        while(bytes_sent < TEN_MEG)
        {
            res = write(pipe_fd,buffer,BUFFER_SIZE);
            if(res == -1)
            {
                fprintf(stderr, "Write error on pipe\n");
                exit(1);
            }
            bytes_sent += res;
        }
        (void) close(pipe_fd);
    }
    else
    {
        exit(0);
    }
    printf("process %d finished\n",getpid());
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
    data_processed(open_mode);
}