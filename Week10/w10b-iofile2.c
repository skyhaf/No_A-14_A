#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// Definisi nama file output sesuai ketentuan soal
#define Output1 "output_problem_b1.txt"
#define Output2 "output_problem_b2.txt"


void main(void) {
   int n, off, id, ofd1, ofd2;
   
   // Membuat file baru untuk proses writing
   ofd1 = open(Output1, O_RDWR | O_CREAT, 0644);
	ofd2 = open(Output2, O_RDWR | O_CREAT, 0644);

   // Menerima input N untuk iterasi input setelahnya
   scanf("%d", &n);

   // Melakukan iterasi sesuai input yang telah didapatkan sebelumnya
   while (n>0){
	    char str[100];
	    scanf("%s %d %d", str, &off, &id);
	    int strSize = strlen(str);

		if(id==1){
	     	lseek(ofd1, off, SEEK_SET);
	      write(ofd1, str, strSize);
	    }
	    else if(id==2){
	     	lseek(ofd2, off, SEEK_SET);
	      write(ofd2, str, strSize);
	    }
       n--;
	}
	   
	close(ofd1);
	close(ofd2);

   printf("Please see file %s\n", Output1);
   printf("Please see file %s\n", Output2);
   
}
