#include<stdio.h>
struct student
{
	int roll;
	char name[20];
	char div;

};

void accept(struct student s[100], int n)
{
	int i;
	printf("Enter record \n");
	for(i=0; i<n; i++)
	{
		printf("Enter Name: ");
		scanf("%s", s[i].name);
		printf("\nEnter Roll no.: ");
		scanf("%d", &s[i].roll);
		printf("\nEnter Division: ");
		scanf(" %c",&s[i].div);

	}
}

void display(struct student s[100], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("\nName: %s", s[i].name);
		printf("\nRoll: %d", s[i].roll);
		printf("\nDivision: %c", s[i].div);
	}
}

void lsearch(struct student s[100], int n)
{

	int i,r;
	printf("\nEnter Roll no. to be searched: ");
	scanf("%d", &r);
	for(i=0; i<n; i++)
	{
		if(r==s[i].roll)
		{
			printf("\nPresent");
			printf("\nName: %s\nRoll: %d\nDivision: %c\n", s[i].name, s[i].roll, s[i].div);
			break;
		}

	}
	if(i==n){
		printf("\nNot Present");
	}

}

int bsearch(struct student s[100], int n)
{
	int key, mid; 
	int low=0; 
	int high=n-1;

	ssort(s, n);
	printf("Enter roll no. to be searched: \n");
	scanf("%d", &key);
	while(low<=high)
	{
		mid=(low+high)/2;
	
		if(key==s[mid].roll)
		{
			printf("present");
			printf("\nName: %s\nRoll: %d\nDivision: %c\n", s[mid].name, s[mid].roll, s[mid].div);
			break;
		}
		if(s[mid].roll>key)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(low>high)
	{
		printf("not found");
	}
}


int bsearchrec(struct student s[100], int n, int low2, int high2)
{
	int key2, mid2; 
	

	bsort(s, n);
		if(low2>high2)
		{
			return -1;
		}
		else{
			mid2=(low2+high2)/2;
		
			if(key2==s[mid2].roll)
			{
				printf("present");
				printf("\nName: %s\nRoll: %d\nDivision: %c\n", s[mid2].name, s[mid2].roll, s[mid2].div);
				return 2;
			}
			if(s[mid2].roll>key2)
			{
				return (bsearchrec(s, n, low2, mid2-1));
			}
			else
			{
				return(bsearchrec(s, n, mid2+1, high2));
			}
		}
	
}


void bsort(struct student s[100], int n)
{
	printf("\nSorted record is as follows: ");
	struct student temp;
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			if(s[j].roll>s[j+1].roll)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;

			}
		}
	}
}

void ssort(struct student s[100], int n)
{
	struct student temp;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(s[i].roll>s[j].roll)
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
}

void isort(struct student s[100], int n)
{

	int i,j;
	for(i = 1; i<n; i++)
	{
		j=i;
		while( j>0 && s[j].roll<s[j-1].roll)
		{
			struct student temp;
			temp = s[j];
			s[j] = s[j-1];
			s[j-1] = temp;
			j--;
		}
	}
}

int main()
{
	struct student s[10];
	int n, ch, temp, key2;
	int low2=0; 
	int high2=n-1;
	printf("\n enter the number of students: ");
	scanf("%d",&n);
	accept(s,n);
	display(s,n);
	while(ch!=7)
	{
		printf("\n1.Linear Search\n2.Binary Search\n3.Binary Search (RECURSSIVE)\n4.Bubble Sort\n5.Selection Sort\n6.Insertion Sort\n7.Exit");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				lsearch(s, n);
				break;

			case 2:
				bsearch(s, n);

				break;

			case 3:
				printf("Enter roll no. to be searched: \n");
				scanf("%d", &key2);
				temp = bsearchrec(s, n, low2, high2);
				if(temp==-1)
					printf("Not found.");
				break;

			case 4:
				bsort(s, n);
				display(s,n);
				break;

			case 5:
				ssort(s, n);
				display(s,n);
				break;

			case 6:
				isort(s, n);
				display(s,n);
				break;

			case 7:
				printf("Thank You!");
				break;
			
			default:
				printf("\n\n---------------Enter a valid option-------------\n\n");
		}
	}
	return 0;
}