#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

   int rPID, rPPID, id1000=getpid(), offset=1000;
   int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;
   
   rPID=getpid()-id1000+offset;
   rPPID=getppid()-id1000+offset;
   if (rPPID < 1000 || rPPID > rPID) rPPID=999;
   printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   fflush(NULL);
   
   p1 = fork();
   wait(NULL);
   if(p1==0){
   	rPID=getpid()-id1000+offset;
   	rPPID=getppid()-id1000+offset;
   	printf("hrsnya 1001 1000 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   	p2 = fork();
   	wait(NULL);
   	if(p2==0){
   		rPID=getpid()-id1000+offset;
   		rPPID=getppid()-id1000+offset;
   		printf("hrsnya 1002 1001 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   		wait(NULL);
   		p4 = fork();
   		wait(NULL);
   		if(p4==0){
   		   	rPID=getpid()-id1000+offset;
   			rPPID=getppid()-id1000+offset;
   			printf("hrsnya 1004 1002 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   			p6 = fork();
   			if(p6==0){
   			   	rPID=getpid()-id1000+offset;
   				rPPID=getppid()-id1000+offset;
   				printf("hrsnya 1006 1004 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   			}
   		}
   	}
   	if(p2>0){
   		p3 = fork();
   		wait(NULL);
   		if(p3==0){
   		   	rPID=getpid()-id1000+offset;
   			rPPID=getppid()-id1000+offset;
   			printf("hrsnya 1003 1001 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   			p5 = fork();
   			wait(NULL);
   			if(p5==0){
   			   	rPID=getpid()-id1000+offset;
   				rPPID=getppid()-id1000+offset;
   				printf("hrsnya 1005 1003 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   				p7 = fork();
   				if(p7==0){
   			   		rPID=getpid()-id1000+offset;
   					rPPID=getppid()-id1000+offset;
   					printf("hrsnya 1007 1005 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   				}
   			}
   		}
   		if(p3>0){
   			p8 = fork();
   			wait(NULL);
   			if(p8==0){
   			   	rPID=getpid()-id1000+offset;
   				rPPID=getppid()-id1000+offset;
   				printf("hrsnya 1008 1001 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   				p9 = fork();
   				if(p9==0){
   				   	rPID=getpid()-id1000+offset;
   					rPPID=getppid()-id1000+offset;
   					printf("hrsnya 1009 1008 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   				}
   			}
   		}
   	}
   }
   
   if(p1>0){
   	p10 = fork();
   	wait(NULL);
   	if(p10==0){
   	   	rPID=getpid()-id1000+offset;
   		rPPID=getppid()-id1000+offset;
   		printf("hrsnya 1010 1001 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   		p11 = fork();
   		if(p11==0){
   		   	rPID=getpid()-id1000+offset;
   			rPPID=getppid()-id1000+offset;
   			printf("hrsnya 1011 1010 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   		}
   		if(p11>0){
   			p12 = fork();
   			if(p12==0){
   			   	rPID=getpid()-id1000+offset;
   				rPPID=getppid()-id1000+offset;
   				printf("hrsnya 1012 1010 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
   			}
   		}
   	}
   }
   
}
