#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
 int file=0;
  char buffer[19];
 if((file=open("testfile.txt",O_RDONLY))<-1);
 return 1;

 char buffer[19];
 if(read(file,buffer,19) != 19) 
 return 1;
  printf("%s\n",buffer);

 if(seek(file,10,SEEK_SET) < 0) 
 return 1;
 

 if(read(file,buffer,19) != 19) 
 return 1;
  printf("%s\n",buffer);

return 0;

}