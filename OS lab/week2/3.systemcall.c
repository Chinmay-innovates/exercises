#include<stdio.h>
#include<fcntl.h>
#include<conio.h>
#include<dirent.h>
int main()
{
 char d[10];
 int c,op;

 DIR*e;

 struct dirent *sd;
 printf("menu\n1.create die\n2.remove dir\n3.read dir\nEnter ypur choice: ");
 scanf("%d",&op);
 switch(op)
 {
  case 1: printf("enter dir name\n");
	  scanf("%s",&d);
	  c=mkdir(d);
	  if(c==1)
	   printf("dir is not created");
	  else
	   printf("dir is created");
	   break;
  case 2:  printf("enter dir name\n");
	  scanf("%s",&d);
	  c=rmdir(d);
	  if(c==1)
	   printf("dir is not removed");
	  else
	   printf("dir is removed");
	   break;
  case 3: printf("Enter dir name to open ");
	  scanf("%s",&d);
	  e=opendir(d);
	  if(e==NULL)
	  printf("dir doesnot exist");
	   else
	   {
	    printf("dir exist");
	     while((sd=readdir(e))!=NULL)
	     printf("%s\t",sd->d_name);
	    }
	    closedir(e);
	    break;
  }
  getch();
  return 0;
}

