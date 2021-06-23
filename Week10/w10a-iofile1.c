#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define OFILE "output_problem_a.txt"


void main(void) {
   int n, off, ofd,value,value1;

   // Membuat file baru untuk proses writing
   ofd = open(OFILE, O_RDWR | O_CREAT, 0644);

   // Menerima input N untuk iterasi input setelahnya
   scanf("%d", &n);

   char str[100];
   char strJenis[3];
   scanf("%s %d %s", str, &off, strJenis);
   int strSize = strlen(str);
   
   value=strcmp(strJenis,"A");
   lseek(ofd, off, SEEK_SET);
   write(ofd, str, strSize);

   value=strcmp(strJenis,"T");
   lseek(ofd, off, SEEK_SET);
   write(ofd, str, strSize);

   // Melakukan iterasi sesuai input yang telah didapatkan sebelumnya
   while ((n-1)>0){
      char str[100];
      char strJenis[3];
      scanf("%s %d %s", str, &off, strJenis);
	   int strSize = strlen(str);

      value=strcmp(strJenis,"A");
      if(value==0){

	      write(ofd, str, strSize);
         // printf("BERHASIL");
      }
      
      value1=strcmp(strJenis,"T");
      if(value1==0){
         lseek(ofd, off, SEEK_SET);
	      write(ofd, str, strSize);
         // printf("masuk");
      }
      // lseek(ofd, off, SEEK_SET);
      // write


      n--;
	}
	close(ofd);


   printf("Please see file %s\n", OFILE);


}
