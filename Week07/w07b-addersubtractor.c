#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "99-myutils.h"

#define T_REHAT 2000
int n;
bool cond = TRUE;
int idmaster = 1;
int sharedInt = 0;
int temp;
int addvar,subvar;
sem_t alusem;

void* adder (void* a) {
	int id;
	id = ++idmaster;
	while(TRUE){
		rehat_acak(T_REHAT);
		sem_wait(&alusem);
		addvar = (rand()%5)+1;
		sharedInt += addvar;
		printf("Thread[%3.3d] \t ADD \t [%3.3d] \t CURRENT VALUE \t [%3.3d] \n",id,addvar,sharedInt);
		sem_post(&alusem);
		temp++;
	}
}


void* substractor (void* a) {
	int id;
	id = ++idmaster;
	while(TRUE){
		rehat_acak(T_REHAT);
		sem_wait(&alusem);
		subvar = (rand()%5)+1;
		sharedInt -= subvar;
		printf("Thread[%3.3d] \t SUB \t [%3.3d] \t CURRENT VALUE \t [%3.3d] \n",id,subvar,sharedInt);
		sem_post(&alusem);
		temp++;
	}
}


void* observer (void* a) {
	int id;
	id = idmaster++;
	while(TRUE){
		rehat_acak(T_REHAT);
		if(temp%(2*n)==0){
			printf("Thread[%3.3d]	OBS	---	CURRENT VALUE	[%3.3d]\n",id,sharedInt);
		temp = 0;
		}
		//sem_wait(&alusem);
		//sem_post(&alusem);
	}
}

int main(int argc, char * argv[])
{  
	sem_init(&alusem, 0, 1);
	int x;
	printf("Hello... \n");
	printf("Please input a positive number (N) : ");
	scanf("%d", &n);
	x=n;
	printf("The input N is : %d \n", n);
	
	for (int i=0; i<n; i++){
		daftar_trit(observer);
		daftar_trit(adder);
		//temp+=1;
		daftar_trit(substractor);
		//temp+=1;
		//if(temp%(2*n)!=0){
			
			//cond = FALSE;
		//}
		//cond = TRUE;
		
	}
	jalankan_trit();
	beberes_trit("Selesai...");
	
}
