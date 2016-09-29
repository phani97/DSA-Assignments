#include<stdio.h>
#include<stdlib.h>
#define ll long long int
int binary_1s(ll n);

int main()
{
    int k;
    ll num;
    printf("enter positive decimal number:");
    k=scanf("%ld",&num);
    if(num<0&&k==0&&num>2147483648)
    {printf("Invalid input");
     return 1;}
    k=binary_1s(num);
    printf("The binary representation of %ld contains %d 1's\n",num,k);
    return 0;
}

int binary_1s(ll n)
{
    if(n==0)
        return 0;
    else
        return n%2+binary_1s(n/2);
}
