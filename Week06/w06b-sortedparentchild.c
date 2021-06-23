#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

  int rPID, rPID1, rPPID, id1000=getpid(), offset=1000;
  int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;

  p1=fork();wait(NULL);
  if(p1>0){//1000
    sleep(1);
    rPID=getpid()-id1000+offset;
    rPPID=getppid()-id1000+offset;
    if (rPPID < 1000 || rPPID > rPID) rPPID=999;
    printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	
	
  }else{//1001
  
    p2=fork();
    if(p2>0){//1001
     p3=fork();wait(NULL);
     if(p3>0){//1001
      sleep(1);
      rPID=getpid()-id1000+offset;
      rPPID=getppid()-id1000+offset;
      printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	  
	 } else {//1003
	 
	  p4=fork();
	  if(p4>0){//1003
	   p5=fork();wait(NULL);
	   if(p5>0){//1003
	    sleep(3);
	    rPID=getpid()-id1000+offset;
        rPPID=getppid()-id1000+offset;
        printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
		
	   }else{//1005
	   
		p6=fork();
		if(p6>0){//1005
			
	    p7=fork();wait(NULL);
		if(p7>0){//1005
		 sleep(3);
	     rPID=getpid()-id1000+offset;
         rPPID=getppid()-id1000+offset;
         printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			
		}else{//1007
			
		 p8=fork();
		 if(p8>0){//1007
			 
	      p9=fork();wait(NULL);
		  if(p9>0){//1007
		   sleep(1);
	       rPID=getpid()-id1000+offset;
           rPPID=getppid()-id1000+offset;
           printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			  
		  }else{//1009
			  
	       p10=fork();
		   if(p10>0){//1009
			sleep(1);
	        rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			   
		   }else{//1010
	        rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			   
		   }
			  
		  }
			 
		 }else{//1008
		  sleep(2);
	      rPID=getpid()-id1000+offset;
          rPPID=getppid()-id1000+offset;
          printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			 
		 }
			
		}
			
		}else{//1006
		 sleep(3);
	     rPID=getpid()-id1000+offset;
         rPPID=getppid()-id1000+offset;
         printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			
		}
		
	   }
	   
	  }else{//1004
	   sleep(6);
	   rPID=getpid()-id1000+offset;
       rPPID=getppid()-id1000+offset;
       printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	  }

	 }
	}else{//1002
	 sleep(9);
     rPID=getpid()-id1000+offset;
     rPPID=getppid()-id1000+offset;
     printf("PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	}
  }
}
