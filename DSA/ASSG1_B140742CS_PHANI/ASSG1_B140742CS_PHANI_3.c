#include<stdio.h>
#include<stdlib.h>

struct student 
{
	char s_id[10];
	char s_name[30];
	char s_mark[10];
};

int main(int argc, char*argv[])
{
	struct student s;
	if(argc==1)
	{
		printf("Please provide command line arguments");
		return 0;
	}
	FILE *file=fopen(argv[1],"a");
	if(file==NULL)
	{
	printf("error");
	return 1;
	}
	fclose(file);
	menu:printf("\nMenu:\n1.Add student record to the file\n2.Display the names of students who obtained lessthan 30 marks\n3.Display the names of students who have insufficient attendance\n4.Print the contents of the file\n5.Exit\nEnter your choice:");
	int i,j,count=0;
	scanf("%d",&i);
	switch(i)
	{
		case 1:
		{	file=fopen(argv[1],"a+");
			printf("Enter id name marks");
			scanf("%s %s %s",s.s_id,s.s_name,s.s_mark);
			fprintf(file,"%s\t%s\t%s\n",s.s_id,s.s_name,s.s_mark);
			fclose(file);
			goto menu;
			break;
		}
		case 2:
		{
			file=fopen(argv[1],"r");
		while(1){
			j=fscanf(file,"%s %s %s",s.s_id,s.s_name,s.s_mark);
			int mark=101;
			
			if(j==-1){
				if(count==0){
					printf("No student with marks lessthan 30");}
				fclose(file);
				goto menu;}
			if(s.s_mark[0]!='I' && s.s_mark[0]!='A' && s.s_mark[0]!='i' && s.s_mark[0]!='a')
				mark=atoi(s.s_mark);
			if(mark<30){
				printf("%s\n",s.s_name);count++;}
			
		}
		
		break;}
		case 3:
		{
		file=fopen(argv[1],"r");
		while(1){
			j=fscanf(file,"%s %s %s",s.s_id,s.s_name,s.s_mark);
			if(j==-1){
				if(count==0){
					printf("No student with insufficient attendence");}
				fclose(file);
				goto menu;}
			if(strcmp(s.s_mark,"I")==0 ||strcmp(s.s_mark,"i")==0 ){
				printf("%s\n",s.s_name);count++;}
			
		}
		
		
		break;}
		case 4:
		{
		file=fopen(argv[1],"r");
		if(fscanf(file,"%s %s %s",s.s_id,s.s_name,s.s_mark)!=EOF){
			printf("+----------+----------------------+------------+\n");
			printf("|Student Id|Student Name          |Student Mark|\n");
			printf("+----------+----------------------+------------+\n");}
		else
			printf("No student records in file");
		fclose(file);
		file=fopen(argv[1],"r");
		while(1){
			j=fscanf(file,"%s %s %s",s.s_id,s.s_name,s.s_mark);
			if(j==-1){
				
			if(count!=0)
			printf("+----------+----------------------+------------+\n");
				fclose(file);
				goto menu;}
			printf("|%-10s|%-22s|%-12s|\n",s.s_id,s.s_name,s.s_mark);
			count++;
		}
		
		break;}
		case 5:
			break;
		default:
		{
			printf("Invalid input.\nChoose right option");
			goto menu;
			break;
		}
	}
}


