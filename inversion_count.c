#include<stdio.h>

int merge(int [], int , int, int);
int divide(int [], int, int);

int main()
{
      int a[100], n, i, count=0;

      //input
      printf(“Enter the no. of elements of array\n”);
      scanf(“%d”,&n);

      printf(“Enter the elements of array\n”);
      for(i=0; i<n; i++)
      scanf(“%d”,&a[i]);

      count=divide(a,0,n-1);

      //output
      printf(“Total no.of inversions=%d\n”, count);

      return 0;

 }
int divide(int a[100], int first, int last )
{
      int mid;
      int count=0;

     if(first<last)
     {
         mid=(first+last)/2;

         //dividing array into 2 sub arrays recursively
         count= divide(a,first,mid);
         count+=divide(a,mid+1,last);

         //merging the subarrays
         count+=merge(a, first, mid, last);

      }

 return count;
} //end of divide function

int merge(int a[100], int first, int mid, int last)
{
      int i, j=first, k=mid+1;
      int count=0;

      //declaring a temporary array
      int b[100];

      for(i=first; j<=mid&&k<=last; i++)
     {
          if(a[j]<=a[k])
          {
              b[i]=a[j++];
          }

          else if(a[k]<=a[j])
         {
              b[i]=a[k++];
              count+=mid-i+1; //no.of elements to its left =inversion wrt that element
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
      }

 return count;

}//end of merge
