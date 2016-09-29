#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
char data;
struct node *left,*right,*parent;
};
int n,p;

int is_operator(char s)
{
if(s=='+' || s=='-' || s=='*' || s=='/' || s=='^') return 1;
return 0;
}

struct node* new_node(char data)
{
struct node *temp=(struct node*) malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
temp->parent=NULL;
return temp;
}
struct node* insert(char str[])
{
char c=str[p];
if((c>='a' && c<='z') || c=='+' || c=='-' || c=='*' || c=='/' ||c=='^'){}
else {printf("INVALID INPUT");exit(0);}
struct node *head=new_node(str[p]);
p--;
if(is_operator(str[p+1]))
{
head->right=insert(str);
if(head->right!=NULL) head->right->parent=head;
head->left=insert(str);
if(head->left!=NULL) head->left->parent=head;
}
return head;
}

void preorder(struct node *head){
struct node *current=head,*prev=head,*next;
while(current!=NULL){
if(current->right==prev){prev=current; current=current->parent;}
else{
if(current->left!=prev){
	printf("%c",current->data);
prev=current;
next=current->left;
if(next==NULL) next=current->right;
if(next==NULL) 
{next=current->parent; }
if(next==NULL) break;
current=next;}
else {
prev =current;
next=current->right;
if(next==NULL) 
{next=current->parent; }
current=next;
}
}
}
}

void inorder(struct node *head)
{
struct node *current=head,*prev=NULL,*next;
while(current!=NULL)
{
if(current->left==prev){
printf("%c",current->data);
prev=current;
current=current->right;
}
else if(current->right==prev)
{
printf(")");
prev=current; 
current=current->parent;}
else {
if(current->left!=NULL)
{	printf("(");
prev=current;
current=current->left;
}
else
{
printf("%c",current->data);
prev=current;
current=current->parent;
}
}
}
}

void postorder(struct node *head){
struct node *current=head,*prev=NULL;
while(current!=NULL){
if(current->right==prev){
printf("%c",current->data);
prev=current;
current=current->parent;
}
else if(current->left==prev){
prev=current;
current=current->right;
}
else if(current->left==NULL){
printf("%c",current->data);
prev=current;
current=current->parent;
}
else 
{
prev=current;
current=current->left;
}
}
}

main()
{
char str[100];
scanf("%s",str);
p=strlen(str)-1;

struct node *head=insert(str);
inorder(head);
printf("\n");
preorder(head);
printf("\n");

postorder(head);
printf("\n");
}
