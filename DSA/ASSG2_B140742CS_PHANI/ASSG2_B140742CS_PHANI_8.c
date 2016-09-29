#include<stdio.h>
#include<stdlib.h>
void mergesort(int arr[], int min, int max);
void merge(int arr[], int l, int r, int m);

int main()
{
int arr[15000],i,j,c;
FILE *p1=fopen("NUMBERS","r");
if(p1==NULL){
printf("file not pointing");return 1;}
for(i=0; i<=10000;i++){
c=fscanf(p1,"%d",&arr[i]);
if(c==-1) break;
if( c==0) {printf("invalid input");return 0;}
}
if(i>10000){
	printf("elements morethan 10000");
	return 1;}

mergesort(arr,0,i-1);
for(j=0;j<=i-1;j++){
printf("%d",arr[j]);}
fclose(p1);
p1=fopen("output.txt","w");
for(j=0;j<=i-1;j++)
{
fprintf(p1,"%d\n",arr[j]);
}
fclose(p1);
}
void merge(int arr[],int l,int r,int m)
{
    int i, j, k;
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
        k++;
    }
}

void mergesort(int arr[], int min, int max)
{
	if (min < max)
	{
		int mid = (max+min)/2 ;
		mergesort(arr, min, mid) ;
		mergesort(arr, mid+1, max);
		merge(arr,min,max,mid);
	}
}




