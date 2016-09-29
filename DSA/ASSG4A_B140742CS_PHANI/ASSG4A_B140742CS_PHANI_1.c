#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *left,*right,*parent;
};
int n,p;
struct node* new_node(int data)
{
struct node *temp=(struct node*) malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct node* insert(int inor[],int pre[],int first,int last)
{
int pos,par;
struct node* head;
par=position(inor,pre[p]);
head=new_node(pre[p]);
p++;

pos=position(inor,pre[p]);
if( pos<=par && pos>=first)
	head->left=insert(inor,pre,first,par);

pos=position(inor,pre[p]);
if(pos <=last && pos>=par)
	head->right=insert(inor,pre,par,last);
return head;
}

int position(int inor[],int ele)
{
int i;
for(i=0;i<n;i++){
	if(inor[i]==ele) return i;
	}
return -1;
}



void preorder(struct node *head)
{
printf("( ");
if(head!=NULL) {
printf("%d ",head->data);
preorder(head->left);
preorder(head->right);
}
printf(") ");
}

main()
{
int i;
scanf("%d",&n);
if(n<=0) {printf("INVALID INPUT");return;}
int inor[n],pre[n];
for(i=0;i<n;i++) scanf("%d",&pre[i]);
for(i=0;i<n;i++) scanf("%d",&inor[i]);
p=0;
struct node* head;
head=insert(inor,pre,0,n-1);
preorder(head);
printf("\n");
}
