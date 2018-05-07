#include <stdio.h>
#include "comm.h"
static int commsemset(int nums,int flags)
{
    key_t _key = ftok(PATHNAME,PROJ_ID);
    if(_key < 0)
    {
        perror("ftok");
        return -1;
    }
    int semid = semget(_key,nums,flags);
    if(semid < 0)
    {
        perror("semid");
        return -2;
    }
    return semid;
}
int createsemset(int nums)
{
    return commsemset(nums,IPC_CREAT|IPC_EXCL|0666);
}
int getsemset(int nums)
{
    return commsemset(nums,IPC_CREAT);
}
int initsem(int semid,int nums,int initval)
{
    union semun _un;
    _un.val = initval;
    if(semctl(semid,nums,SETVAL,_un)<0)
    {
        perror("semctl");
        return -1;
    }
    return 0;
}
static int commPV(int semid,int who,int op)
{
    struct sembuf _sf;
    _sf.sem_num = who;
    _sf.sem_op = op;
    _sf.sem_flg = 0;
    if(semop(semid,&_sf,1)<0)
    {
        perror("semop");
        return -1;
    }
    return 0;
}
int P(int semid,int who)
{
    return commPV(semid,who,-1);
}
int V(int semid,int who) 
{
    return commPV(semid,who,1);

}
int destroysemset(int semid)
{
    if(semctl(semid,0,IPC_RMID)<0)
    {
        perror("semctl");
        return -1;
    }
}
