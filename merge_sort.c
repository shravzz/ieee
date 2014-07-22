#include<stdio.h>


void merge(int [], int , int, int);
void divide(int [], int, int);
void insertion(int [], int, int);

int main()
{
    int a[100], n, i;

    //input
    printf(“Enter the no. of elements of array\n”);
    scanf(“%d”,&n);

    printf(“Enter the elements of array to be sorted\n”);
    for(i=0; i<n; i++)
    scanf(“%d”,&a[i]);

    divide(a,0,n-1);

     //output
     printf(“Array after merge sorting\n”);
     for(i=0; i<n; i++)
     printf(“%d\t”, a[i]);

     return 0;

}

void divide(int a[100], int first, int last )
{
     int mid;
     if(last-first<20) //perform insertion sort for efficiency
     insertion(a, first, last)

     else //perform merge sort
    {
         if(first<last)
        {
             mid=(first+last)/2;

             //dividing array into 2 sub arrays recursively
             divide(a,first,mid);
             divide(a,mid+1,last);

             //merging the two subarrays
             merge(a, first, mid, last);

        }
     }
} //end of divide function

void merge(int a[100], int first, int mid, int last)
{
      int i, j=first, k=mid+1;

      //declaring a temporary array
      int b[100];

      if(a[mid]<=a[k]) //checking if array is already sorted
      {
         return;
      }
      else if(a[last]<=a[mid]) //checking if the 2nd half is smaller than the 1st half
      {
           for(i=low;k<=last;i++)
           {
             b[i]=a[k+i];
           }
           while(j<=mid)
          {
             b[i++]=a[j++];
          }
       }

      else
      {
            for(i=first; j<=mid&&k<=last; i++)
            {
                 if(a[j]<a[k])
                {
                    b[i]=a[j++];

                }

                else if(a[k]<a[j])
                {
                    b[i]=a[k++];

                 }

                //if both elements are same,add them into the main array in 1step

                 else
                 {
                   b[i]=a[j];
                   b[++i]=a[j];
                   j++;
                   k++;
                 }
            } //end of for loop

            if(j>mid) //check if counter has reached the final element of 1st subarray
            {
                  while(k<=last)
                  {
                     b[i++]=a[k++];

                  }
             }

             else
            {
                  while(j<=mid)
                  {
                     b[i++]=a[j++];

                  }
             }//end of inner else
      } //end of outer else


      //copy contents of temporary array into main array
      for(i=low; i<=last; i++)
      {
         a[i]=b[i];
      }
 }// end of merge

 void insertion(int a[100],int first,int last)
 {
      int i, j, temp;

      //sorting process
      for(i=first; i<=last; i++)
     {
          temp=a[i];

          //Comparing ith element with the sorted array on its left

           for(j=i-1; j>=0&&temp<a[j]; j--)
          {
                a[j]=a[j-1];
           }

           a[j]=temp;
     }
 }//end of insertion sort
