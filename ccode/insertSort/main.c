#include<stdio.h>
#include<stdlib.h>

int X[10], Y[10], NumInputs, NumY = 0;

void getArgs(int n, char **array)
{
    int i;
    NumInputs = n-1;
    for(i = 0; i < NumInputs; i++)
        X[i] = atoi(array[i+1]);
}

void scootOver(int j)
{
    int k;
    for(k = NumY-1; k >= j; k--)  // modify the for loop 
        Y[k+1] = Y[k];
}

void insert(int newY)
{
    int j;
    if (NumY == 0){
        Y[0] = newY;
        return;
    }
    for (j = 0; j < NumY; j++){
        if (newY < Y[j]){
            scootOver(j);
            Y[j] = newY;
            return;
        }
    }
    Y[NumY] = newY; // add the statement
}

void processData()
{
    for (NumY = 0; NumY < NumInputs; NumY++)
        insert(X[NumY]);
}

void printResults()
{
    int i;
    for(i = 0; i < NumInputs; i++)
        printf("%d\n", Y[i]);
}

int main(int argc, char **argv)
{
    getArgs(argc, argv);
    processData();
    printResults();
    return 0;
}
