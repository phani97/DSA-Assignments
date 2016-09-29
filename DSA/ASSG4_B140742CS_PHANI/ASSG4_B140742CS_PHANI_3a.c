#include<stdio.h>
#include<stdlib.h>

struct node{
char data;
struct node *left,*right;
};

struct node* insert(struct node* head,char ele)
{
struct node *temp;
if(head==NULL)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=ele;
temp->left=NULL;
return temp;
}
if(!(head->data=='+' || head->data=='-' || head->data=='*' || head->data=='/' || head->data=='^'))
	return NULL;
temp=insert(head->left,ele);
if(temp==NULL)
{	
	temp=insert(head->right,ele);
	if(temp==NULL)
		return NULL;
	else 
	{
		head->right=temp;
		return head;
	}
}
else
{
head->left=temp;
return head;
}
}

void inorder(struct node *head)
{
if(head!=NULL)
{
if(head->left!=NULL && head->right!= NULL) printf("(");
inorder(head->left);
printf("%c",head->data);
inorder(head->right);
if(head->left!=NULL && head->right!= NULL) printf(")");
}
}

void preorder(struct node *head)
{
if(head!=NULL)
{
printf("%c",head->data);
preorder(head->left);
preorder(head->right);
}
}

void postorder(struct node *head)
{
if(head!=NULL)
{
postorder(head->left);
postorder(head->right);
printf("%c",head->data);
}
}

main()
{
struct node *head=NULL,*temp;
char c;int count=0;
scanf("%c",&c);
while(c!='\n' && c!=' ')
{
	if((c>='a' && c<='z') || c=='+' || c=='-' || c=='*' || c=='/' ||c=='^') 
	{temp=insert(head,c);
	if(temp==NULL) {printf("INVALID\n"); return;}
	else head=temp;
	count++;
	scanf("%c",&c);	}
	else {printf("INVALID\n"); return;}
	
}
if(head==NULL) {printf("NO EXPRESSION");return;}
if(count%2==0) {printf("INVALID\n");return;} 
inorder(head);
printf("\n");
preorder(head);
printf("\n");
postorder(head);
printf("\n");
}
