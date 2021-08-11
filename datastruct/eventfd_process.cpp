#include <sys/eventfd.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <pthread.h>
#include <unistd.h>
using namespace std;
int efd;
#define handle_error(msg)   \
    do { perror(msg); exit(EXIT_FAILURE);  } while(0)

int main()
{
    efd = eventfd(0,0);
    int rc;
    uint64_t u;
    if(efd==-1)
    {
        perror("eventfd error!");
    }
    int pid = fork();
    if(pid == 0)
    {
        uint64_t buf = 1;
        while(1)
        {
            rc = write(efd,&buf,sizeof(buf));
            if(rc != 8){
                perror("write");
            }
            sleep(2);
        }//end while
    }
    else
    {
        while(1){
            printf("Parent about to read\n");
            rc = read(efd, &u, sizeof(uint64_t));
            if(rc != sizeof(uint64_t))
                handle_error("read");

            printf("Parent read %llu from efd\n",(unsigned long long)u);
        }
    }
    
    close(efd);
    return 0;
}