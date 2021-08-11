#include <sys/eventfd.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <pthread.h>
#include <unistd.h>
using namespace std;
int efd;

void *threadfun(void*)
{
    uint64_t buf;
    int rc;
    while(1)
    {   
        rc = read(efd,&buf,sizeof(uint64_t));
        if(rc == 8)
        {
            printf("notify success");
        }
        printf("rc = %llu, buf = %lu\n",(unsigned long long)rc, buf);
    }
}

int main()
{
    pthread_t tid;
    efd = eventfd(0,0);
    int rc;
    if(efd==-1)
    {
        perror("eventfd error!");
    }
    if(pthread_create(&tid,NULL,threadfun,NULL)<0)
    {
        perror("pthread error!");
    }
    uint64_t buf = 1;
    while(1)
    {
        rc = write(efd,&buf,sizeof(buf));
        if(rc != 8){
            perror("write");
        }
        sleep(2);
    }//end while

    close(efd);
    return 0;
}