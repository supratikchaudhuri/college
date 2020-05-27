#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};



void create(struct node* head)
{
	struct node *newnode ,*current;
	char ch;
	current=head;
	do{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;

	current->next=newnode;
	current=newnode;

	 printf("\nDo you want to continue : ");
	 scanf(" %c",&ch);
	}
	while(ch=='y'||ch=='Y');
}



void display(struct node *head)
{
	struct node *counter;
	if(head->next==NULL)
	{
		printf("There are no nodes present to display!!\n");
		return;
	}
	printf("The nodes are:\n");
	counter=head->next;
	while(counter!=NULL)
	{
		printf("%d\n",counter->data);
		counter=counter->next;
	}
}


void delete(struct node *head)
{
	int pos1,i;
	struct node *counter,*temp,*temp1;
	printf("Enter position at which node is to be deleted: ");
	scanf("%d",&pos1);
	if(head->next==NULL)
	{
		printf("There are no nodes present to delete!!\n");
		return;
	}
		counter=head->next;
		
		i=1;
		while(i<pos1)
		{
			temp=counter;
			counter=counter->next;
			i++;
		}
		temp1=counter;
		temp->next=counter->next;

		free(temp1);


}



void insert(struct node *head)
{
	int pos,i;
	struct node *temp,*counter;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter position at which node is to be inserted: ");
	scanf("%d",&pos);
	printf("Enter data to be stored in node: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	counter=head;
	i=1;
	while(i<pos)
	{
		counter=counter->next;
		i++;
	}
	temp->next=counter->next;
	counter->next=temp;
}


void sort(struct node *head)
{
	struct node *temp,*prev,*curr;
	temp=head->next;
	int i,j,n=0;
	while(temp!=NULL)
	{
			n++;
			temp=temp->next;
	}

	for(i=0;i<n;i++)
	{
		prev=head;
		temp=head->next;
		for(j=0;j<n-1;j++)
		{
			curr=temp->next;
			if((temp->data) > (curr->data))
			{
				prev->next=curr;
				temp->next=curr->next;
				curr->next=temp;
				prev=temp;
				temp=curr;

			}
			else
			{
				prev=temp;
				temp=temp->next;
			}
		}
	}
	display(head);

}

void reverse(struct node *head)
{
	struct node *p,*q,*r;
	p=NULL;
	q=head->next;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	head->next=p;
	display(head);

}

void merge(struct node *head1,struct node *head2)
{
	struct node *head3,*p,*q,*r;
	head3= (struct node *) malloc (sizeof(struct node *));
	p=head1->next;
	q=head2->next;
	r=head3;

	while(p!=NULL && q!=NULL)
	{
			if((p->data) < (q->data))
			{
				r->next=p;
				p=p->next;
				r=r->next;
			}
			else
			{
				r->next=q;
				q=q->next;
				r=r->next;
			}
	}
	if(p!=NULL)
	{
		r->next=p;

	}

	if(q!=NULL)
		{
			r->next=q;
		}
	r->next=NULL;
	display(head3);
}


int main()
{	int choice;
	char cho;
	struct node *head,*head2;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	head2= (struct node *) malloc (sizeof(struct node *));
	head2->next=NULL;
	while(choice!=8)
	{
		printf("Chose one option from below:-\n");
		printf("1.Create a node\n");
		printf("2.Display nodes\n");
		printf("3.Delete node\n");
		printf("4.Insert a node\n");
		printf("5.Reverse\n");
		printf("6.Sort\n");
		printf("7.Merge\n");
		printf("8.Exit\n");
	printf("Enter choice");
	scanf("%d",&choice);

	switch(choice)
			{
			case 1:
				create(head);
				break;

			case 2:
				display(head);
				break;

			case 3:
				delete(head);
				break;
			case 4:
				insert(head);
				break;
			case 5:
				reverse(head);
				break;
			case 6:
				sort(head);
				break;
			case 7:
				create(head2);
				sort(head);
				sort(head2);
				merge(head,head2);
				break;
			default:
				printf("Program over");
				break;
			}
		}
}
