#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void) {

  int rPID, rPID1, rPPID, id1000=getpid(), offset=1000;
  int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;

  p1=fork();wait(NULL);
  if(p1>0){//1000
    rPID=getpid()-id1000+offset;
    rPPID=getppid()-id1000+offset;
    if (rPPID < 1000 || rPPID > rPID) rPPID=999;
    printf("PARENT PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	
  }else{//1001
  
    p2=fork();wait(NULL);
    if(p2>0){//1001
	
     p3=fork();wait(NULL);
     if(p3>0){//1001
	 
      rPID=getpid()-id1000+offset;
      rPPID=getppid()-id1000+offset;
      printf("C1 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	  
	 } else {//1003
	 
	  p4=fork();wait(NULL);
	  if(p4>0){//1003
	   
	   p5=fork();wait(NULL);
	   if(p5>0){//1003
	   
	    rPID=getpid()-id1000+offset;
        rPPID=getppid()-id1000+offset;
        printf("C3 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
		
	   }else{//1005
	   
		p6=fork();wait(NULL);
		if(p6>0){//1005
			
	    p7=fork();wait(NULL);
		if(p7>0){//1005
			
	     rPID=getpid()-id1000+offset;
         rPPID=getppid()-id1000+offset;
         printf("C5 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			
		}else{//1007
			
		 p8=fork();wait(NULL);
		 if(p8>0){//1007
			 
	      p9=fork();wait(NULL);
		  if(p9>0){//1007
			  
	       rPID=getpid()-id1000+offset;
           rPPID=getppid()-id1000+offset;
           printf("C7 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			  
		  }else{//1009
			  
	       p10=fork();wait(NULL);
		   if(p10>0){//1009
			   
	        rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            printf("C9 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			   
		   }else{//1010
			   
	        rPID=getpid()-id1000+offset;
            rPPID=getppid()-id1000+offset;
            printf("C10 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			   
		   }
			  
		  }
			 
		 }else{//1008
			 
	      rPID=getpid()-id1000+offset;
          rPPID=getppid()-id1000+offset;
          printf("C8 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			 
		 }
			
		}
			
		}else{//1006
			
	     rPID=getpid()-id1000+offset;
         rPPID=getppid()-id1000+offset;
         printf("C6 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
			
		}
		
	   }
	   
	  }else{//1004
	  
	   rPID=getpid()-id1000+offset;
       rPPID=getppid()-id1000+offset;
       printf("C4 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	  }

	 }
	}else{//1002
     rPID=getpid()-id1000+offset;
     rPPID=getppid()-id1000+offset;
     printf("C2 PID[%d] \t PPID[%4d]\n", rPID, rPPID);
	}
  }
  wait(NULL);
}
