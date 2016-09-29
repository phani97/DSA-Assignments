#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};
void insert(int x);
int k_last(struct node*head1,int k);
struct node* head;
int n;
void insert(int x){
struct node* temp,*temp1;
temp= (struct node*) malloc(1*sizeof(struct node));
if(head==NULL)
	head=temp;
else{
	temp1=head;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp1->next=temp;
}

temp->data=x;
temp->next=NULL;
}

int k_last(struct node*head1,int k)
{
int i;
for(i=n;i>k;i--)
head1=head1->next;

return head1->data;
}

main()
{
int i,x,k;
head=NULL;

if(!scanf("%d",&n) || n<1) {printf("invalid input");return 0;}

for(i=0;i<n;i++){
if(!scanf("%d",&x) || x<-1073741824 || x>1073741824){printf("invalid input"); return 0;}
insert(x);
}
if(!scanf("%d",&k) || k<1 || k>n){printf("invalid input"); return 0;}
i=k_last(head,k);
printf("%d",i);
}
