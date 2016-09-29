#include<stdio.h>
#include<stdlib.h>

int c1,c2,c3,c4;
struct node{
int data;
struct node* prnt;
};

struct hash{
struct node* ele;
int rank;
}h1[10001],h2[10001],h3[10001],h4[10001];

struct node* makeset(int x)
{
struct node* temp=(struct node*) malloc(sizeof(struct node));
temp->data=x;
temp->prnt=temp;
return temp;
}

struct node* findset1(int x)
{
c1++;
if(h1[x].ele==NULL) return NULL;
if(h1[x].ele->prnt==h1[x].ele)
	return h1[x].ele;
else return findset1(h1[x].ele->prnt->data);
}

struct node* findset2(int x)
{
c2++;
if(h2[x].ele==NULL) return NULL;
if(h2[x].ele->prnt==h2[x].ele)
	return h2[x].ele;
else return findset2(h2[x].ele->prnt->data);
}

struct node* findset3(int x)
{
c3++;
if(h3[x].ele==NULL) return NULL;
if(h3[x].ele->prnt==h3[x].ele)
	return h3[x].ele;
else 
{h3[x].ele->prnt= findset3(h3[x].ele->prnt->data); 
return h3[x].ele->prnt;}
}

struct node* findset4(int x)
{
c4++;
if(h4[x].ele==NULL) return NULL;
if(h4[x].ele->prnt==h4[x].ele)
	return h4[x].ele;
else 
{h4[x].ele->prnt= findset4(h4[x].ele->prnt->data); 
return h4[x].ele->prnt;}
}

struct node* uni1(int x,int y)
{
struct node *temp1,*temp2;
temp1=findset1(x);
temp2=findset1(y);
if(temp1==NULL || temp2==NULL) return NULL;
if(temp1==temp2) return temp1;
else{
h1[temp2->data].ele->prnt=temp1;
return temp1;
}
}

struct node* uni3(int x,int y)
{
struct node *temp1,*temp2;
temp1=findset3(x);
temp2=findset3(y);
if(temp1==NULL || temp2==NULL) return NULL;
if(temp1==temp2) return temp1;
else{
h3[temp2->data].ele->prnt=temp1;
return temp1;
}
}

struct node* uni2(int x,int y)
{
struct node *temp1,*temp2;
temp1=findset2(x);
temp2=findset2(y);
if(temp1==NULL || temp2==NULL) return NULL;
if(temp1==temp2) return temp1;
else if(h2[temp1->data].rank > h2[temp2->data].rank)
{
h2[temp2->data].ele->prnt=temp1;
return temp1;
}
else if(h2[temp1->data].rank == h2[temp2->data].rank)
{
h2[temp2->data].ele->prnt=temp1;
h2[temp1->data].rank++;
return temp1;
}
else
{
h2[temp1->data].ele->prnt=temp2;
return temp2;
}
}

struct node* uni4(int x,int y)
{
struct node *temp1,*temp2;
temp1=findset4(x);
temp2=findset4(y);
if(temp1==NULL || temp2==NULL) return NULL;
if(temp1==temp2) return temp1;
else if(h4[temp1->data].rank > h4[temp2->data].rank)
{
h4[temp2->data].ele->prnt=temp1;
return temp1;
}
else if(h4[temp1->data].rank == h4[temp2->data].rank)
{
h4[temp2->data].ele->prnt=temp1;
h4[temp1->data].rank++;
return temp1;
}
else
{
h4[temp1->data].ele->prnt=temp2;
return temp2;
}
}

main()
{
int c,d;
char x;
struct node* temp;
scanf("%c",&x);
while(1){
switch(x)
{
case 'm':
{
scanf("%d",&c);
if(c<0 || c>10000){ printf("INVALID INPUT\n");return;}
if(h1[c].ele==NULL){
h1[c].ele=makeset(c);
h2[c].ele=makeset(c);
h3[c].ele=makeset(c);
h4[c].ele=makeset(c);
h2[c].rank=0;
h4[c].rank=0;
printf("%d\n",c);}
else printf("PRESENT\n");
break;
}
case 'f':
{
scanf("%d",&c);
if(c<0 || c>10000){ printf("INVALID INPUT\n");return;}
temp=findset1(c);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=findset2(c);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=findset3(c);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=findset4(c);
if(temp!=NULL){
printf("%d\n",temp->data);}
else printf("NOT FOUND\n");
break;
}
case 'u':
{
scanf("%d",&c);
scanf("%d",&d);
if(c<0 || c>10000 || d<0 || d>10000){ printf("INVALID INPU\nT");return;}
temp=uni1(c,d);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=uni2(c,d);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=uni3(c,d);
if(temp!=NULL){
printf("%d ",temp->data);}
temp=uni4(c,d);
if(temp!=NULL){
printf("%d\n",temp->data);}
else printf("ERROR\n");
break;
}
case 's':
{
printf("%d %d %d %d\n",c1,c2,c3,c4);
return;
break;
}
default:
{
printf("INVALID INPUT\n");
return;
break;
}
}
scanf("%c",&x);
scanf("%c",&x);
}
}
