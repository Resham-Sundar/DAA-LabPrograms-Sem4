#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[20];
	int empid;
	struct node *prev;
	struct node *next;
}*start =NULL;
void addatbeg();
void addatend();
struct node *deleteatpos(struct node *ptr,int val);
void display();
void search();
main()
{
	int ch,val;
	while(1)
	{
		printf("1.addatbeg");
		printf("2.addatend");
		printf("3.deleteatpos");
		printf("4.display");
		printf("5.search");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:addatbeg();
			break;
			case 2:addatend();
			break;
			case 3:printf("enter position ");
	         scanf("%d",&val);
            	start=deleteatpos(start,val);
			break;
			case 4:display();
			break;
			case 5:search();
			break;
			default:printf("wrong choice");
		 } 
	}
}
void addatbeg()
{
	struct node *temp;
	char n[20];
	int id;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter name and employee id\n");
	scanf("%s %d",n,&id);
	strcpy(temp->name,n);
	temp->empid=id;
	if(start==NULL)
	{
		temp->prev=NULL;
		temp->next=NULL;
		start=temp;
	}
	else
	{
		temp->prev=NULL;
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
void addatend()
{
	struct node *temp,*p;
	char n[20];
	int id;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter name and employee id\n");
	scanf("%s %d",n,&id);
	strcpy(temp->name,n);
	temp->empid=id;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	temp->next=NULL;
	temp->prev=p;
	p->next=temp;
}
struct node *deleteatpos(struct node *start,int pos)
{
	int i;struct node *temp;
	if(pos==1)
	{
	temp=start;
	start=temp->next;
	start->prev=NULL;
}
    else
    {
    	struct node *p=start;
    	for(i=0;i<pos-2;i++)
    	{
    		p=p->next;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next->prev=p;
	}
	free(temp);
	return start;
}
void display()
{
	struct node *p;
	p=start;
	printf("the list is\n");
	while(p!=NULL)
	{
		printf("%s %d",p->name,p->empid);
		p=p->next;
	}
}
void search()
{
	struct node *p=start;
	int pos=0,key;
	printf("enter key id to be searched");
	scanf("%d",&key);
	while(p!=NULL)
	{
		pos++;
		if(p->empid==key)
		{
			printf("employee id is %d,name is %s,position is %d",p->empid,p->name,pos);
			break;
		}
		else 
		p=p->next;
	}
	if(pos==0)
	printf("key not present");
}
