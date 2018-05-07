#ifndef _COMM_H_
#define _COMM_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;

};
int cteatesemset(int nums);
int initsem(int semid,int nums,int initval);
int getsemset(int nums);
int P(int semid,int who);
int V(int semid,int who);
int destroysemset(int semid);
#endif
