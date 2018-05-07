#include "comm.h"
int main()
{
    int semid = createsemset(1);
    initsem(semid,0,1);
    pid_t id = fork();
    if(id == 0)
    {
        int _semid = getsemset(0);
        while(1)
        {
            P(_semid,0);
            printf("A");
            fflush(stdout);
            usleep(100000);
            printf("A");
            fflush(stdout);
            usleep(300000);
            V(_semid,0);
        }
    }
    else
    {
        while(1)
        {
            P(semid,0);
            printf("B");
            fflush(stdout);
            usleep(200000);
            printf("B");
            fflush(stdout);
            usleep(120000);
            V(semid,0);

            
        }
        wait(NULL);
    }
    destroysemset(semid);
    return 0;
}
