#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

  int rPID, rPID1, rPPID, id1000=getpid(), offset=1000;
  int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12;

      rPID=getpid()-id1000+offset;
      rPPID=getppid()-id1000+offset;
      if (rPPID < 1000 || rPPID > rPID) rPPID=999;
      printf("PARENT PID[%d] \t PPID[%4d]\n", rPID, rPPID);
      fflush(NULL);
      
      p1=fork();
      if(p1==0){
       p2=fork();
       if(p2==0){
       
       }else{
        p3=fork();
        if(p3==0){
        
        }else{}
       }else{}
       }
      }else{}
}
