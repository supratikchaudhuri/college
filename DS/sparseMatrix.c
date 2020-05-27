#include<stdio.h>
#define max 10
void accept(int r, int c, int a[100][100])
{

	int i, j;
	printf("\nEnter elements: ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int r, int c, int a[100][100])
{
	int i, j;
	printf("Your matrix is: \n");
	for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
}

void compact(int a[100][100],int b[100][3], int r, int c)
{
	int i, j, m, n;
	b[0][0]=r;
	b[0][1]=c;

	int k=1;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	b[0][2]= k-1;
	printf("\n\n");
	printf("Compact matrix: \n");
	for(m=0; m<k; m++)
			{
				for(n=0; n<3; n++)
				{
					printf("%d\t",b[m][n]);
				}
				printf("\n");
			}

}

void transpose(int b[100][3],int bt[100][3])
{
	int t;
	int i, j, m, n;
	bt[0][0]=b[0][1];
	bt[0][1]=b[0][0];
	bt[0][2]=b[0][2];
	int k=1;
	t=b[0][2];
	for(i=0; i<b[0][1]; i++)
	{
		for(j=0; j<=t; j++)
		{
			if(i==b[j][1])
			{
				bt[k][0]=i;
				bt[k][1]=b[j][0];
				bt[k][2]=b[j][2];
				k++;
			}
		}
	}
	printf("\n\nSimple Transpose sparse matrix is: \n");
	for(m=0; m<k; m++)
	{
		for(n=0; n<3; n++)
		{
			printf("%d\t",bt[m][n]);
		}
		printf("\n");
	}
}
void ftranspose(int b[100][3],int btf[100][3])
{
	int i, j, m, n, k=1, t, loc;
	int total[max], index[max];
	btf[0][0]=b[0][1];
	btf[0][1]=b[0][0];
	btf[0][2]=b[0][2];
	t=b[0][2];
	for(i=0; i<b[0][1]; i++)
	{
		total[i]=0;
	}
	for(i=0; i<=t; i++)
	{
		j=b[i][1];
		total[j]=total[j]+1;
	}
	index[0]=1;
	for(i=0; i<b[0][1]; i++)
	{
		index[i]=index[i-1]+total[i-1];
	}
	for(i=0; i<=t; i++)
	{
		j=b[i][1];
		loc=index[j];
		index[j]++;
		btf[loc][0]=b[i][1];
		btf[loc][1]=b[i][0];
		btf[loc][2]=b[i][2];
		
	}
	printf("\n\nFast Transpose sparse matrix is: \n");
	for(m=0; m<t+1; m++)
	{
		for(n=0; n<3; n++)
		{
			printf("%d\t",btf[m][n]);
		}
		printf("\n");
	}
}

void main()
{
	int r, c, i, j, a[100][100], b[100][3], bt[100][3], btf[100][3];
	printf("Enter number of rows and coulmn\n");
	scanf("%d%d", &r, &c);
	accept(r, c, a);
	display(r, c, a);
	compact(a, b, r, c);
	transpose(b, bt);
	ftranspose(b, btf);

}