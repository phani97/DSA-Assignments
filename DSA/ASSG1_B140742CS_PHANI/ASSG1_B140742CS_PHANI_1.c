#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
  char s1[100000],s2[100000];
  int i,j,l1,l2;
  printf("enter string1:");
  scanf("%s",s1);
  printf("\nenter string2:");
  j=scanf("%s",s2);
  l1=strlen(s1);
  for(i=0;i<l1;i++)
	if(s1[i]<'a'||s1[i]>'z'||l1==0){printf("Invalid input\n");
		return 1;}
  for(i=0;i<strlen(s2);i++)
	if(s2[i]<'a'||s2[i]>'z'||strlen(s2)==0){printf("Invalid input\n");
		return 1;}
  if(l1==strlen(s2))
  {
      for(i=0;i<l1;i++){
        for(j=0;j<l1;j++)
      {
         if(s1[i]==s2[j])
           {
                s2[j]='A';
                j=l1;
           }
         else if(j==(l1-1))
         {
            goto op;
         }


      }}
      printf("yes\n");

  }
  else
    op:printf("no\n");
}
