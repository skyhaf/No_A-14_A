#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "99-myutils.h"


sem_t sem_a, sem_b, sem_c, sem_d;

void* T1 (void* a) {
	sem_wait(&sem_d);
	for(int i=1; i<2; i+=1){
		printf(" T1	Writer	[%d]\n",i);
	}
	sem_post(&sem_a);		
	
}


void* T2 (void* a) {
	sem_wait(&sem_a);
	for(int i=1; i<3; i+=1){
		printf(" T2	Writer	[%d]\n",i);
	}
	sem_post(&sem_b);
}


void* T3 (void* a) {
	sem_wait(&sem_b);
	for(int i=1; i<4; i+=1){
		printf(" T3	Reader	[%d]\n",i);
	}
	sem_post(&sem_c);
}

void* T4 (void* a) {
	sem_wait(&sem_c);
	for(int i=1; i<5; i+=1){
		printf(" T4	Reader	[%d]\n",i);
	}
	sem_post(&sem_d);
}

int main(int argc, char * argv[])
{
	sem_init(&sem_a, 0, 0);
	sem_init(&sem_b, 0, 0);
	sem_init(&sem_c, 0, 0);
	sem_init(&sem_d, 0, 1);

	daftar_trit(T1);
	daftar_trit(T2);
	daftar_trit(T3);
	daftar_trit(T4);

	while(TRUE){
		   jalankan_trit();
		}
	beberes_trit("Selesai...");
}
