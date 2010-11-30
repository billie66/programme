#include <stdio.h>
#define N 1000

int main(int argc, const char *argv[])
{
   int n, m; 
   printf("Please input the number of people n:\n");
   scanf("%d", &n);
   printf("the specific number m:\n");
   scanf("%d", &m);
   int i, a[N];
   for (i=0; i<n; i++)
   {
       a[i]=i+1;
   }
   printf("the sequence of people out of round:\n");
   int j=0, k=0, count=1;
   while(j<n)
   {
       if(a[j]!=0)
           k=k+1;
       if(k%m==0&&a[j]!=0)
       {
           printf("%4d: %4d out ", count, a[j]);
           a[j]=0;
           k=0;
           if(count%5==0)
               printf("\n");
           count++;
       }
       if(j==(n-1))
           j=0;
       else
           j++;
       if(count==(n+1))
           break;
   }   
   printf("\n");
       return 0;
}
