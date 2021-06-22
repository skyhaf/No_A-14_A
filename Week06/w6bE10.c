#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {
   int rPID, rPPID, id1000=getpid(), offset=1000;

   rPID=getpid()-id1000+offset;
   rPPID=getppid()-id1000+offset;
   if (rPPID < 1000 || rPPID > rPID) rPPID=999;

   if(fork()>0){
      if(fork()>0){
         sleep(6);
         printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
      }else{
         if(fork()>0){
            rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            if (!fork()){
                  rPID=getpid()-id1000+offset;
                  rPPID=getppid()-id1000+offset;
                 if(!fork()){
                     sleep(1);
                     rPID=getpid()-id1000+offset;
                     rPPID=getppid()-id1000+offset;
                     printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                  }
                  else{
                     if(!fork()){
                        rPID=getpid()-id1000+offset;
                        rPPID=getppid()-id1000+offset;
                        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                     }
                     else{
                        sleep(2);
                        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
                     }
                  }
               }
               else{
                  sleep(4);
                  printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
               }
         }
         else{
            sleep(3);
            rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
         }
      }
   }

   else{
         sleep(5);
         rPID=getpid()-id1000+offset;
         rPPID=getppid()-id1000+offset;
         printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   }
}
