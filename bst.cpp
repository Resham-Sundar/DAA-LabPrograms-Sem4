#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
}*root=NULL;
struct node *insert(struct node *ptr,int ikey);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
main()
{
	int choice,key;
	printf("1.insert\n 2.preorder\n 3.inorder\n 4.postorder\n");
	while(1)
	{
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the key to insert");
			scanf("%d",&key);
			root=insert(root,key);
			break;
			case 2:preorder(root);
			break;
			case 3:inorder(root);
			break;
			case 4:postorder(root);
			break;
			default:printf("invalid choice");
		}
	}
}
struct node *insert(struct node *ptr,int ikey)
{
	if(ptr==NULL)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=ikey;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
		
	}
	else if(ikey<ptr->info)
	{
	ptr->lchild=insert(ptr->lchild,ikey);
}
else if(ikey>ptr->info)
	{
	ptr->rchild=insert(ptr->rchild,ikey);
}
else
{
	printf("no duplicates\n");
}
return ptr;
}
void preorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		printf("%d ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void inorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		inorder(ptr->lchild);
		printf("%d ",ptr->info);
		
		inorder(ptr->rchild);
	}
}
void postorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	else
	{
		
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d ",ptr->info);
	}
}

