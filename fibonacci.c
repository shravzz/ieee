
//Program to find if a number is part of first 100 fibonacci numbers

#include<stdio.h>

void fibo(long long int []);
int binary_search(long long int [], int, int, long long int);

int main()
{
    long long int n;
    long long int a[100];

    printf("Enter the number to be checked\n");
    scanf("%ld",&n);

    fibo(a);


    if(binary_search(a, 0, 99, n)) //checking if no.is fibonacci
    {
        printf("The number is a part of first 100 fibonacci numbers\n");
    }
    else
    {
        printf("The number is not a fibonacci number\n");
    }

    return 0;

}

 void fibo(long long int a[100])
{
    int i;
    a[0]=0;
    a[1]=1;

    //calculating first 100 fibonacci numbers
    for(i=2;i<100;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }

}

int binary_search(long long int a[100], int low, int high, long long int n)
{
    int mid=0;

    if(low<=high)
    {
        mid=(low+high)/2;

        if(a[mid]==n) //search element found
        return 1;

        else if(n<a[mid]) //check the left part of array
        return binary_search(a, low, mid-1, n);

        else //check the right partof array
        return binary_search(a, mid+1, high, n);

    }

    else
    {
         return 0;
    }

} //end of binary_search
