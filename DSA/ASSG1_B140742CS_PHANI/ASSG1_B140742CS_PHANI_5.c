#include<stdio.h>
#include<math.h>

void add(float,float);
void sub(float,float);
void mul(float,float);
void div(float,float);

int main()
{
float a,b;int c;
void (*q)(float,float);
printf("\nenter two numbers:");
c=scanf("%f %f",&a,&b);
if(c==0)
	{printf("Invalid input");return 1;}
start:printf("\nMenu:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\nEnter your choice:");
scanf("%d",&c);
switch(c)
	{
		case 1:
		{
		q=&add;
		(*q)(a,b);
		goto start;
		break;
		}
		case 2:
		{
		q=&sub;
		(*q)(a,b);
		goto start;
		break;
		}
		case 3:
		{
		q=&mul;
		(*q)(a,b);
		goto start;
		break;
		}
		case 4:
		{
		q=&div;
		(*q)(a,b);
		goto start;
		break;
		}
		case 5:
		break;
		default:
		{
		printf("\n\"Enter right option\"");
		goto start;
		break;
		}
	}
}

void add(float a,float b)
{
printf("%g",a+b);
}
void sub(float a,float b)
{
printf("%g",a-b);
}
void mul(float a,float b)
{
printf("%g",a*b);
}
void div(float a,float b)
{
printf("%g",a/b);
}
