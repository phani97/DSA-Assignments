#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int data;
struct node *left,*right;
};

struct node* insert(struct node *head,int ele);
void inorder(struct node *head);
void postorder(struct node *head);
void preorder(struct node *head);
struct node* search(struct node *head,int ele);
struct node* delete(struct node *head,int ele);
int find_min(struct node *);
int find_max(struct node*);
int predecessor(struct node* ,int);
int successor(struct node*,int);

int main()
{
struct node* head=NULL,*temp;
char s[10];
int ele,choice;
scanf("%s",s);
do{
if(strcmp(s,"insr")==0)
{
	scanf("%d",&ele);
	if(ele<0) {printf("INVALID INPUT"); return;}
	temp=search(head,ele);
	if(temp!=NULL) {printf("INVALID INPUT\n");return;}
	head=insert(head,ele);
	scanf("%s",s);
}
else if(strcmp(s,"inor")==0)
{
	if(head==NULL) printf("EMPTY");
	inorder(head);
	printf("\n");
	scanf("%s",s);
}
else if(strcmp(s,"prer")==0)
{
	if(head==NULL) printf("EMPTY");
	preorder(head);
	printf("\n");
	scanf("%s",s);
}
else if(strcmp(s,"post")==0)
{
	if(head==NULL) printf("EMPTY");
	postorder(head);
	printf("\n");
	scanf("%s",s);
}
else if(strcmp(s,"srch")==0)
{
	scanf("%d",&ele);
	if(ele<0) {printf("INVALID INPUT"); return;}
	temp=search(head,ele);
	if(temp==NULL) printf("NOT FOUND\n");
	else printf("FOUND\n");
	scanf("%s",s);
}
else if(strcmp(s,"delt")==0)
{
	scanf("%d",&ele);
	if(ele<0) {printf("INVALID INPUT"); return;}
	temp=search(head,ele);
	if(temp==NULL) printf("NOT FOUND\n");
	else
	head=delete(head,ele);
	scanf("%s",s);
}
else if(strcmp(s,"minm")==0)
{
	ele=find_min(head);
	if(ele==-1) printf("NIL\n");
	else
	printf("%d\n",ele);
	scanf("%s",s);
}
else if(strcmp(s,"maxm")==0)
{
	ele=find_max(head);
	if(ele==-1) printf("NIL\n");
	else
	printf("%d\n",ele);
	scanf("%s",s);
}
else if(strcmp(s,"pred")==0)
{
	scanf("%d",&ele);
	if(ele<0) {printf("INVALID INPUT"); return;}
	ele=predecessor(head,ele);
	if(ele==-1) printf("NOT FOUND\n");
	else if(ele==-2) printf("NIL\n");
	else
	printf("%d\n",ele);
	scanf("%s",s);
}
else if(strcmp(s,"succ")==0)
{
	scanf("%d",&ele);
	if(ele<0) {printf("INVALID INPUT"); return;}
	ele=successor(head,ele);
	if(ele==-1) printf("NOT FOUND\n");
	else if(ele==-2) printf("NIL\n");
	else
	printf("%d\n",ele);
	scanf("%s",s);
}
else if(strcmp(s,"stop")==0) return;
else 
{
printf("INVALID CHOICE\n");
scanf("%s",s);
}
}while(1);
}


struct node* insert(struct node *head,int ele)
{
if(head==NULL){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	temp->left=NULL;
	temp->right=NULL;
	head=temp;
}
else if(head->data > ele)
	head->left=insert(head->left,ele);
else head->right=insert(head->right,ele);
return head;
}

struct node* search(struct node *head,int ele)
{
struct node* temp;
if(head==NULL)
	return NULL;
if(head->data==ele) return head;
else if(head->data > ele)
	return search(head->left,ele);
else return search(head->right,ele);
}

struct node* delete(struct node* head,int ele)
{
if(head==NULL) return head;
else if(head->data > ele){
	head->left= delete(head->left,ele);}
else if(head->data < ele){
	head->right= delete(head->right,ele);}
else if(head->left==NULL && head->right==NULL){
	head= NULL;}
else if(head->left!=NULL && head->right==NULL){
	head= head->left;}
else if(head->left==NULL && head->right!=NULL){
	head= head->right;}
else {
	head->data=find_min(head->right);
	head->right=delete(head->right,head->data);	
}
return head;
}

void inorder(struct node *head)
{

if(head!=NULL)
{
inorder(head->left);
printf("%d ",head->data);
inorder(head->right);
}
}

void preorder(struct node *head)
{
if(head!=NULL)
{
printf("%d ",head->data);
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
printf("%d ",head->data);
}
}

int find_min(struct node *head)
{
if(head==NULL)
	return -1;
if(head->left==NULL)
	return head->data;
else return find_min(head->left);
}

int find_max(struct node *head)
{
if(head==NULL)
	return -1;
if(head->right==NULL)
	return head->data;
else return find_max(head->right);
}

int predecessor(struct node *head,int ele)
{
struct node *current,*predecessor=NULL,*temp;
current=search(head,ele);
if(current==NULL) return -1;
else if(current->left!=NULL) return find_max(current->left);
temp=head;
while(temp!=current)
{
if(temp->data < current->data)
{	predecessor=temp;
	temp=temp->right;
}
else temp=temp->left;
}
if(predecessor==NULL) return -2;
else return predecessor->data;
}

int successor(struct node *head,int ele)
{
struct node *current,*successor=NULL,*temp;
current=search(head,ele);
if(current==NULL) return -1;
else if(current->right!=NULL) return find_min(current->right);
temp=head;
while(temp!=current)
{
if(temp->data > current->data)
{	successor=temp;
	temp=temp->left;
}
else temp=temp->right;
}
if(successor==NULL) return -2;
else return successor->data;
}
