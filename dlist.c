#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
};

typedef struct node* node;
node getnode();
node head = NULL;
node ins_end(node,int);
void display(node);
node ins_pos(node,int,int);
node del_ele(node,int);
int main()
{
	int ch,ele,pos;
	while(ch != 5){
		printf("\n\n1. Insert Back\n2. Display\n3. Insert Position\n4. Delete given Element\n5.Exit\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element\n");
				scanf("%d",&ele);
				head = ins_end(head,ele);
				
				break;
			case 2: display(head);
				break;
			case 3: printf("Enter element\n");
				scanf("%d",&ele);
				printf("Enter position\n");
				scanf("%d",&pos);
				head = ins_pos(head,ele,pos);
				break;
			case 4: printf("Enter element\n");
				scanf("%d",&ele);
				head = del_ele(head,ele);
				break;

		}
	}
}

node getnode()
{
	node temp;
	temp = (node)malloc(sizeof(node));
	temp->rlink = NULL;
	temp->llink = NULL;
	return temp;
}


node ins_end(node head,int ele)
{
	node temp1;
	node temp2;
	temp1=getnode();
	temp1->data = ele;
	if(head==NULL)
	{
		head = temp1;
	}
  else
	{
		temp2 = head;
		while(temp2->rlink!=NULL)
		{
			temp2 = temp2->rlink;
		}
		temp2->rlink = temp1;
		temp1->llink = temp2;
	}
	return head;
}

void display(node head) {
	node temp=head;
	printf("The elements in the list are :\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->rlink;
	}
	printf("\n");
}

node ins_pos(node head,int ele,int pos) {
	node temp;
	node curr=head;
	node prev=NULL;
	int count=1;
	temp = getnode();
	temp->data = ele;
	if(head==NULL) {
		printf("Empty\n");
	}
   else {
		while(count<pos && curr!=NULL)
		{
			prev = curr;
			curr=curr->rlink;
			count++;
		}
		if(curr==NULL && count<pos) {
			printf("Cannot insert\n");
		}
	else if(curr==NULL && count==pos) {
		prev->rlink=temp;
		temp->llink = prev;
		printf("%d inserted  in %d positon\n",ele,pos);
	}
	else {
		temp->rlink = curr;
		temp->llink = (curr->llink);
		(curr->llink)->rlink = temp;
		curr->llink = temp;
		printf("%d inserted  in %d positon\n",ele,pos);
	     }
	}
	return head;
}


node del_ele(node head,int ele) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
	else if(head->rlink == NULL)
	{
	  free(head);
	  return NULL;
	}
  else {
		while(temp->data!=ele && temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		if(temp->data==ele && temp->rlink==NULL) {
			printf("%d deleted \n",temp->data);
			(temp->llink)->rlink=NULL;
			temp->llink = NULL;
			free(temp);
		}
	else if(temp->data!=ele && temp->rlink==NULL)
		{
 			printf("Invalid\n");
		}
	else if(temp->data==ele && temp->llink==NULL) {
		printf("%d deleted \n",temp->data);
		head=temp->rlink;
		(temp->rlink)->llink=NULL;
		free(temp);
	}
	else {
		 printf("%d deleted \n",temp->data);
		(temp->llink)->rlink = temp->rlink;
		(temp->rlink)->llink = temp->llink;
		free(temp);
	}
   }
	return head;
}
