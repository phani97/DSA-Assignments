#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int data;
struct node *left,*right,*parent;
};
int p;
struct node_stk{
struct node *data;
struct node_stk *next;
};
struct stack{
struct node_stk *top;
};

struct node_que{
struct node *data;
struct node_que *next;
};
struct queue{
struct node_que *head,*tail;
};

int isempty_que(struct queue *q)
{
if(q->head==NULL)
	return 1;
else return 0;
}

void enqueue(struct queue* q,struct node* element)
{
struct node_que *temp,*temp1;
temp= (struct node_que*)malloc(1*sizeof(struct node_que));
if(q->head==NULL)
{
q->head=temp;
q->tail=temp;
}
else{
temp1=q->tail;
temp1->next=temp;
q->tail=temp;
}
temp->data=element;
temp->next=NULL;
}

struct node* dequeue(struct queue* q)
{
struct node_que *temp;
struct node* data;
if(isempty_que(q)) return NULL;
if(q->head==q->tail)
{
temp=q->head;
data=temp->data;
q->head=NULL;
q->tail=NULL;
free(temp);
return data;
}
else{
temp=q->head;
data=temp->data;
q->head=temp->next;
free(temp);
return data;
}
}




void push(struct stack* s,struct node* element)
{
struct node_stk* temp;
temp=(struct node_stk*)malloc(sizeof(struct node_stk));
temp->data=element;
temp->next=s->top;
s->top=temp;
}

struct node* pop(struct stack *s)
{
struct node_stk *temp;
if(s->top==NULL) return NULL;
temp=s->top;
struct node* data=temp->data;
s->top=temp->next;
free(temp);
return data;
}





struct node* new_node(int data)
{
struct node *temp=(struct node*) malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
};

void preorder(struct node *head)
{
if(head!=NULL) {
printf("%d ",head->data);
preorder(head->left);
preorder(head->right);
}
}

struct node* insert(char str[])
{
p+=2;
int i;
if(p>=strlen(str)) {printf("INVALID INPUT"); exit(0);}
char s[10];
if(str[p]==')') {p++;return NULL;}
for(i=0;str[p]!=' ';i++,p++)
	s[i]=str[p];
s[i]='\0';
i=atoi(s);
p++;
if(p>=strlen(str)) {printf("INVALID INPUT"); exit(0);}
struct node* head=new_node(i);
head->left=insert(str);
p++;
if(p>=strlen(str)) {printf("INVALID INPUT"); exit(0);}
head->right=insert(str);
if(p>=strlen(str)) {printf("INVALID INPUT"); exit(0);}
p+=2;
return head;
}

void zigzag(struct node *root){
int count=0;
struct stack s;
s.top=NULL;
struct queue q;
q.head=NULL;
q.tail=NULL;
push(&s,root);
while(s.top!=NULL){
if(count%2!=0){
while(s.top!=NULL)
{
root=pop(&s);
printf("%d ",root->data);
if(root->right!=NULL) enqueue(&q,root->right);
if(root->left!=NULL) enqueue(&q,root->left);
}
while(q.head!=NULL){
push(&s,dequeue(&q));
}
}
else {
while(s.top!=NULL)
{
root=pop(&s);
printf("%d ",root->data);
if(root->left!=NULL) enqueue(&q,root->left);
if(root->right!=NULL) enqueue(&q,root->right);
}
while(q.head!=NULL){
push(&s,dequeue(&q));
}
}
count++;

}}

main()
{
char str[1000],c;
int i=0;
scanf("%c",&c);
while(c!='\n'){


str[i]=c;
i++;
scanf("%c",&c);
}
str[i]='\0';
if(i==0) {printf("INVALID INPUT"); return;}
p=0;
struct node* head=insert(str);
zigzag(head);
}
