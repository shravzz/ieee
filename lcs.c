#include<stdio.h>
#include<string.h>

int max(int , int);
int lcs(char [], char [], int, int );

int main()
{
    char x[100];
    char y[100];
    int m,n;
    int c[100][100];

    printf("Enter the 1st sequence\n");
    gets(x);
    printf("Enter the 2nd sequence\n");
    gets(y);

    m=strlen(x);
    n=strlen(y);

    printf("Length of longest common subsequence of 2 strings is %d ", lcs(x, y,  m-1, n-1));

    return 0;
}

int lcs(char x[100], char y[100],  int m, int n)
{
    static int c[100][100]; //intialise elements of array to 0 only once

    if(m==-1||n==-1)
    return 0;

    if(c[m][n]!=0)  //checking if answer is already calculated
    return c[m][n];

    else
    {

     if(x[m]==y[n])
     return (c[m][n]=1+lcs(x,y,m-1,n-1));

     else
     return (c[m][n]=max(lcs(x,y,m-1,n),lcs(x,y,m,n-1)));

   }

}

int max(int a,int b)
{
    return ((a>b)?a:b);

}
