#include<stdio.h>
#include<stdlib.h>

int reverse_pairs(int [],int,int);
int reverse_number(int[],int,int,int);
int main()
{
int i,n,k;
if(!scanf("%d",&n) || n<=0)
{printf("invalid input");return 1;}
int a[n];
for(i=0;i<n;i++)
{
	if(!scanf("%d",&a[i]))
	{printf("invalid input");return 1;}
}
k=reverse_pairs(a,0,n-1);
printf("%d\n",k);
}

int reverse_pairs(int a[],int first,int last)
{
int i=0,j=0,k=0,mid=(first+last)/2;
if(first<last){
i=reverse_pairs(a,first,mid);
j=reverse_pairs(a,mid+1,last);
k=reverse_number(a,first,last,mid);
}
return i+j+k;
}
int reverse_number(int arr[],int l,int r,int m)
{
int i, j, k,count=0;
    int a =m-l+1;
    int b =r-m;
    int L[a],R[b];
    for (i=0;i<a;i++)
        L[i] = arr[l+i];
    for (j = 0; j<b; j++)
        R[j] = arr[m+1+j];
	
    i = 0;
    j = 0;
    k = l;
    while (i<a&&j<b)
    {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
	    count+=a-i;
	   
        }
        k++;
    }
    while(i<a)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<b)
    {
        arr[k]=R[j];
        j++;
	count+=a-i;
        k++;
    }
return count;
}

