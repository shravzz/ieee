#include<stdio.h>

void insertion(int[],int);

int main()
{
    int a[100], n, i;

    printf(“Enter the number of elements\n”);
    scanf(“%d”,&n);

    //Input array elements
    printf(“Enter elements of array\n”);

    for (i=0;i<n;i++)
    scanf(“%d”,&a[i]);

     //function call
      insertion(a,n);

     //Output
     printf(“Array after sorting\n”);

    for(i=0; i<n; i++)
    printf(“%d\t”,a[i]);

    return 0;
}
void insertion(int a[100],int n)
{
    int i, j, temp;

    //sorting process
    for(i=1;i<n;i++)
    {
          temp=a[i];

          //Comparing ith element with the sorted array on its left

          for(j=i-1; j>=0&&temp<a[j]; j--)
         {
             a[j]=a[j-1];
         }
         a[j]=temp;
    }
} //End of insertion sort

