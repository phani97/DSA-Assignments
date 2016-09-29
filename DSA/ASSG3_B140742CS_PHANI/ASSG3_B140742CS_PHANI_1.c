#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};
int swap(struct node* head1,int a,int b);
void insert(int x);
void print();
struct node* head;

int swap(struct node* head1,int a,int b){
struct node* temp,*temp1,*temp2,*temp3,*temp4;
if(head1->data==a){
temp2=head1;
while((temp2->next)->data!=b &&temp2->next->next!=NULL)
	temp2=temp2->next;
if(temp2->next->data!=b) return 2;
temp3=temp2->next;
temp=temp3->next;
temp1=head1;
head=temp3;
temp2->next=temp1;
head->next=head1->next;
temp1->next=temp;
}

else if(head1->data==b){
temp2=head1;
while((temp2->next)->data!=a&& temp2->next->next!=NULL)
	temp2=temp2->next;
if(temp2->next->data!=a) return 1;
temp3=temp2->next;
temp=temp3->next;
temp1=head1;
head=temp3;
temp2->next=temp1;
head->next=head1->next;
temp1->next=temp;
}

else {
temp1=head1;
while((temp1->next)->data!=a &&temp1->next->next!=NULL)
	temp1=temp1->next;
if(temp1->next->data!=a) return 1;
temp3=head1;
while((temp3->next)->data!=b &&temp3->next->next!=NULL)
	temp3=temp3->next;
if(temp3->next->data!=b) return 2;

temp2=temp1->next;
temp4=temp3->next;
temp=temp1->next;
temp1->next=temp3->next;
temp3->next=temp;

temp=temp2->next;
temp2->next=temp4->next;
temp4->next=temp;

}return 0;
}
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
void print(){
struct node* temp;
temp=head;
while(temp!=NULL){
	printf("%d ",temp->data);
	temp=temp->next;}
}

int main()
{
int n,x,i,y,z;
head=NULL;
if(!scanf("%d",&n) || n<2) {printf("invalid input");return 0;}

for(i=0;i<n;i++){
if(!scanf("%d",&x) || x<-1073741824 || x>1073741824){printf("invalid input"); return 0;}
insert(x);
}
if(scanf("%d%d",&y,&z)!=2 || y<-1073741824 || y>1073741824 || z<-1073741824 || z>1073741824){printf("invalid input"); return 0;}
if(y!=z)
i=swap(head,y,z);
if(i==1 && y!=z) printf("%d NOT FOUND",y);
else if(i==2 && y!=z) printf("%d NOT FOUND",z);
else print();
}

