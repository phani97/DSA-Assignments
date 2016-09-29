#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
};

void insert(struct node **s,int data)
{
struct node *temp,*temp1;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
if(*s==NULL)
	*s=temp;
else {
temp1=*s;
while(temp1->next!=NULL)
	temp1=temp1->next;
temp1->next=temp;
}
}

void print(struct node *s)
{
if(s==NULL)
{
printf("EMPTY");
return;
}
while(s!=NULL)
{
printf("%d ",s->data);
s=s->next;
}
}


struct node *reverse(struct node *list)
{
    struct node *revHead;
    if (list == NULL || list->next == NULL)
    {
        return list;
    }

    revHead = reverse(list->next);
    list->next->next = list;
    list->next = NULL; 

    return revHead;
}

int main()
{
struct node *head;
int n,i,ele;


if(!scanf("%d",&n) || n<=0){printf("invalid input"); return;}
 
for(i=0;i<n;i++)
{
if(!scanf("%d",&ele) || ele<-1073741824 || ele>1073741824){printf("invalid input"); return;}
insert(&head,ele);
}
head=reverse(head);
print(head);
}
