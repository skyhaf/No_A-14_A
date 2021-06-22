#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

  int rPID, rPID1, rPPID, id1000=getpid(), offset=1000, temp, temp2, temp3, temp4, temp5, temp6;

  rPID=getpid()-id1000+offset;
  rPPID=getppid()-id1000+offset;
  if (rPPID < 1000 || rPPID > rPID) rPPID=999;
  printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
  fflush(NULL);

  temp=fork();
  wait(NULL);
  if(temp==0){
    temp3=fork();
    wait(NULL);
    if(temp3==0){
      rPID=getpid()-id1000+offset;
      rPPID=getppid()-id1000+offset;
      printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
    } else {
      temp4=fork();
      wait(NULL);
      if(temp4==0){
        rPID=getpid()-id1000+offset;
        rPPID=getppid()-id1000+offset;
        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
      } else {
        rPID=getpid()-id1000+offset;
        rPPID=getppid()-id1000+offset;
        printf("PID[%d] \t PPID[%4d]\n", rPID, 1000);
      }
    }
  }
  fflush(NULL);
  if(temp>0){
    temp2=fork();
    wait(NULL);
    if(temp2==0){
      temp5=fork();
      wait(NULL);
      if(temp5==0){
        rPID=getpid()-id1000+offset;
        rPPID=getppid()-id1000+offset;
        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
      } else {
        temp6=fork();
        wait(NULL);
        if(temp6==0){
          rPID=getpid()-id1000+offset;
          rPPID=getppid()-id1000+offset;
          printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
        } else {
          rPID=getpid()-id1000+offset;
          rPPID=getppid()-id1000+offset;
          printf("PID[%d] \t PPID[%4d]\n", rPID, 1000);
        }
      }
    }
  }
}