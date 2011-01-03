#include <stdio.h>

void print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
        printf("\n");
}

void sort(int a[], int n)
{
    int j, k, i; 
    for (k = 0; k < n-1; k++){
        for (i = k+1; i < n; i++) {
            if (a[k] > a[i]){
                j = a[k];
                a[k] = a[i];
                a[i] = j;
            }
        }
    }
}

void big(int a[], int n)
{
    sort(a,n);
    print(a, n);
    int b[n], h[n], t=0, l, m;
    while(t < n-1){
        l=0;
        for(m=t+1; m<n; m++){
            if(a[t]==a[m])
                ++l;
            else
                break;
        }        
        if(l!=0){
            b[t] = a[t];
            h[t] = l+1;
            printf("the value is: %d\n", b[t]);
            printf("the count is: %d\n", h[t]); 
        }
        if(l==0)
            t++;
        else 
            t+=l+1;
    }           
}

int main()
{
    int a[8]={6,2,4,4,6,1,6,2};
    print(a, 8);
    big(a, 8);
    return 0;
}
