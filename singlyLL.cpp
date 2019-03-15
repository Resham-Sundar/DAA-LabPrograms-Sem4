#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[20];
	int rollno;
	int sub1,sub2,sub3;
	struct node *link;
}*start =NULL;
void addatbeg();
void addatend();
struct node *deleteatpos(struct node *ptr,int val);
void display();
void percentcount();
main()
{
	int ch,val;
	while(1)
	{
		printf("1.addatbeg");
		printf("2.addatend");
		printf("3.deleteatpos");
		printf("4.display");
		printf("5.percent");
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
			case 5:percentcount();
			break;
			default:printf("wrong choice");
		 } 
	}
}
void addatbeg()
{
	struct node *temp;
	char n[20];
	int r,s1,s2,s3;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter student name.\nenter student roll no.\nenter three subj marks\n");
	scanf("%s%d%d%d%d",n,&r,&s1,&s2,&s3);
	strcpy(temp->name,n);
	temp->rollno=r;
	temp->sub1=s1;
	temp->sub2=s2;
	temp->sub3=s3;
	temp->link=start;
	start=temp;
}
void addatend()
{
	struct node *temp,*p;
	char n[20];
	int r,s1,s2,s3;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter student name.\nenter student roll no.\nenter three subj marks\n");
	scanf("%s%d%d%d%d",n,&r,&s1,&s2,&s3);
	strcpy(temp->name,n);
	temp->rollno=r;
	temp->sub1=s1;
	temp->sub2=s2;
	temp->sub3=s3;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=temp;
	temp->link=NULL;
}
void display()
{
	struct node *p=start;
	printf("\nThe list is \n");
	while(p!=NULL)
	{
		printf("%s %d %d %d %d",p->name,p->rollno,p->sub1,p->sub2,p->sub3);
		p=p->link;
	}
}
struct node *deleteatpos(struct node *start,int pos)
{
	struct node *temp;int i;
	struct node *p=start;
	
	if(pos==1)
	{
	temp=start;
	start=temp->link;
    }
    else
    {
    	
    	for(i=0;i<pos-2;i++)
    	{
    		p=p->link;
		}
		temp=p->link;
		p->link=temp->link;
	}
	free(temp);
	return start;
}
void percentcount()
{
	struct node *p=start;
	int per,count =0;
	while(p!=NULL)
	{
		per=(p->sub1+p->sub2+p->sub3)/3;
		printf("per is %d",per);
		if((p->sub1>40)&&(p->sub2>40)&&(p->sub3>40))
		count++;
		p=p->link;
	}
	printf("total students passed is %d\n",count);
}
