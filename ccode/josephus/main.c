/*
 * Using an array for Joephus problem
 * Copyright 2010 Billie Zhang
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
   int n, m; 
   printf("Please input the number of people n(n>0):\n");
   scanf("%d", &n);
   printf("the specific number m(m>0):\n");
   scanf("%d", &m);
   int *a = malloc(n * sizeof(*a));
   if (a == NULL) {
       printf("There is not enough space!\n");
       return 1;
   } else {
       int i;
       for (i = 0; i < n; i++)
           a[i] = i + 1;
       printf("the sequence of people out of round:\n");
       int j, k, count = 1;
       j = k = 0;
       while (j < n) {
           if (a[j] != 0)
               k = k + 1;
           if (k % m == 0 && a[j] != 0) {
               printf("%4d: %4d out ", count, a[j]);
               /* set the proper member kicked out of the group to zero */
               a[j] = 0; 
               k = 0;
               if (count % 5 == 0)
                   printf("\n");
               count++;
           }
           if (j == (n-1))
               j = 0;    
           else
               j++;
           /* when all numbers are zero but one, excute if statement */
           if (count == n && a[j] != 0) {
               printf("%4d: %4d out ", count, a[j]);
               break;
           }
           else if (count - 1 == n)
               break;
       }
       free(a);
       a = NULL;
   }
   printf("\n");
   return 0;
}
