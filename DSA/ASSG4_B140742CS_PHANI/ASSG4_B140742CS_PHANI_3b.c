#include<stdio.h>
#include<stdlib.h>

struct node_bst{
char data;
struct node_bst *left,*right;
};

struct node{
struct node_bst *data;
struct node *next;
};

struct stack{
struct node *top;
};


void initialise (struct stack *s)
{
s->top=NULL;
}
int isempty(struct stack *s)
{
if(s->top==NULL)
	return 1;
else return 0;
}

void push(struct stack* s,struct node_bst *element)
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=element;
temp->next=s->top;
s->top=temp;
}

struct node_bst* pop(struct stack *s)
{
struct node *temp;
if(s->top==NULL) return NULL;
temp=s->top;
struct node_bst *data=temp->data;
s->top=temp->next;
return data;
}


struct node_bst* insert(struct node_bst* head,char ele)
{
struct node_bst *temp;
if(head==NULL)
{
temp=(struct node_bst*)malloc(sizeof(struct node_bst));
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

void preorder(struct node_bst *head)
{
struct stack s;
struct node_bst *temp;
initialise(&s);
if(head==NULL) {printf("EMPTY");return;}
push(&s,head);
while(!isempty(&s))
{
temp=pop(&s);
printf("%c",temp->data);
if(temp->right) push(&s,temp->right);
if(temp->left) push(&s,temp->left);
}
}

void postorder(struct node_bst *head)
{
struct stack s;
struct node_bst *temp=head,*temp1;
initialise(&s);
if(head==NULL) {printf("EMPTY");return;}
do{
while(temp!=NULL)
{
	if(temp->right!=NULL)
		push(&s,temp->right); 
	push(&s,temp);
	temp=temp->left;
}
temp=pop(&s);
temp1=pop(&s);

if(temp->right!=NULL && temp1==temp->right)
{
push(&s,temp);
temp=temp->right;
}
else
{
printf("%c",temp->data);
temp=NULL;
if(temp1!=NULL)
 push(&s,temp1);
}
}while(!isempty(&s));
}



void inorder(struct node_bst *head){
	if(head!=NULL){
	   int i=0;
	   struct stack s;
		s.top=NULL;
	   struct node_bst *temp=head,*temp1=NULL;
	   struct node *t2;
	   do{
	        while(temp!=NULL){
	          push(&s,temp);
				
	          if(i>0)
	            printf("(");
	          i++;
	          temp=temp->left;
	        }
			
	        while(temp==NULL && s.top!=NULL){
	           t2=(s.top);
				if(t2->data==NULL) {printf("jtn");return;}
	           temp=t2->data;
	           if(temp->right==NULL || temp->right==temp1){
	           if(temp->right==NULL)
	             printf("%c",temp->data);
	           else
	             printf(")");
	             temp=pop(&s);
	             //temp=t2->data;
	             temp1=temp;
	             temp=NULL;
	           }
	           else{
	             printf("%c",temp->data);
	             temp=temp->right;}
	        }
	        i=0;
	   }while(s.top!=NULL);
	}
	return;
}

main()
{
struct node_bst *head=NULL,*temp;
char c;int count=0;
scanf("%c",&c);
while(c!='\n' && c!=' ')
{
	if((c>='a' && c<='z') || c=='+' || c=='-' || c=='*' || c=='/' ||c=='^') {
	temp=insert(head,c);
	if(temp==NULL) {printf("INVALID\n"); return;}
	else head=temp;
	count++;
	scanf("%c",&c);}
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
