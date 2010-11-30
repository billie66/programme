#include <stdio.h>

int main(int argc, const char *argv[])
{
   int a[10];
   int i;
   for (i=0; i<10; i++)
   {
       a[i]=i+1;
   }
   for (i=0; i<10; i++)
   {
       printf("a[%d]: %d ", i, a[i]);
   }
   printf("\n");
   
   int j=0, m=3;
   int k=0, n=1;
   while(j<10)
   {
       if(a[j]!=0)
           k=k+1;
       if(k%m==0&&a[j]!=0)
       {
           printf("%d: %d out\n ", n++, a[j]);
           a[j]=0;
           k=0;
       }
       if(j==9)
           j=0;
       else
           j++;
       if(n==11)
           break;
   }   
       return 0;
}
