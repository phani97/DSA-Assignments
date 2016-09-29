#include<stdio.h>
#include<stdlib.h>
void top_right(int a[][100],int,int,int,int);
void right_top(int a[][100],int,int,int,int);
void bottom_left(int a[][100],int,int,int,int);
void left_bottom(int a[][100],int,int,int,int);

int main()
{
int i,j,m,n,k,choice;
printf("Enter rows and columns of the matrix");
i=scanf("%d %d",&m,&n);
if(m<=0||n<=0||i<2||n>100||m>100){
printf("matrix doesn't exist with that configurations");
return 1;} 
int a[100][100];
printf("Enter matrix\n");
for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		k=scanf("%d",&a[i][j]);
		if(k!=1||a[i][j]<0||a[i][j]>2147483647){
			printf("invalid input");
			return 1;}
	}
do{
printf("menu:\n1.Clockwise spiral-order traversal\n2.Anti-Clockwise spiral-order traversal\n3.exit\nEnter ur choice");
k=scanf("%d",&choice);
if(k!=1)
{
printf("invalid choice");
return 1;
}
else{
switch(choice)
{
	case 1:
	{
		top_right(a,0,m-1,0,n-1);
		printf("\n");
		break;
	}
	case 2:
	{
		left_bottom(a,0,m-1,0,n-1);
		printf("\n");
		break;
	}
	case 3:
	break;
	default:
	{
		printf("choose right option");
		printf("\n");
		break;
	}
}}
}while(choice!=3);
}

void top_right(int a[][100],int rf,int rl,int cf,int cl)
{
int i,j;
for(i=cf;i<=cl;i++)
	printf("%d\t",a[rf][i]);


for(j=rf+1;j<=rl;j++)
	printf("%d\t",a[j][cl]);
if(rl-rf>0&&cl!=cf)
	bottom_left(a,rf+1,rl,cf,cl-1);
}
void bottom_left(int a[][100],int rf,int rl,int cf,int cl)
{
int i;
for(i=cl;i>=cf;i--)
	printf("%d\t",a[rl][i]);

for(i=rl-1;i>=rf;i--)
	printf("%d\t",a[i][cf]);
if(rl-rf>0&&cl!=cf)
	top_right(a,rf,rl-1,cf+1,cl);
}
void left_bottom(int a[][100],int rf,int rl,int cf,int cl)
{
int i;
for(i=rf;i<=rl;i++)
	printf("%d\t",a[i][cf]);

for(i=cf+1;i<=cl;i++)
	printf("%d\t",a[rl][i]);

if(rl-rf>0&&cl!=cf)
	right_top(a,rf,rl-1,cf+1,cl);
}
void right_top(int a[][100],int rf,int rl,int cf,int cl)
{
int i;
for(i=rl;i>=rf;i--)
	printf("%d\t",a[i][cl]);
for(i=cl-1;i>=cf;i--)
	printf("%d\t",a[rf][i]);
if(rl-rf>0&&cl!=cf)
	left_bottom(a,rf+1,rl,cf,cl-1);
}
