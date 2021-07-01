#include<stdio.h>
int update( int [], int, int);
int sort(int [], int, int, int);
int T, N, Q, i, x, y, k, num;

int main()
{
	
	scanf("%d",&T);// number of testcases
	printf("\n");
	for ( ;T>0; T-- )
	{
		scanf("%d",&N);//number of shelves
		printf("\n");
		if ( N>0 )
		{
			int shelf[N];

			for ( i=1; i<=N; i++ )
			{
				scanf("%d",&shelf[i]);//number of books
			}
			printf("\n");
			scanf("%d",&Q);//number of Queries
			printf("\n");
		
			for ( ; Q>0; Q-- )
			{
				scanf("%d",&num);
			
				if ( num==1 )
				{
					scanf("%d%d",&x,&k);		
					update(shelf,x,k);
					printf("\n");
				}
					
				else
				{
					scanf("%d%d%d",&x,&y,&k);
					sort(shelf,x,y,k);
				}
			
			}
		
		}
	}
	
	return 0;
}

int update(int shelf[],int x,int k)
{
	shelf[x] = k;
}

int sort(int shelf[],int x,int y,int k)
{
	int j, b, temp;
	for ( j=x; j<=y; j++ )
	{
		for ( b=x; b<=y; b++ )
		{
			if (shelf[b]> shelf[j])
			{
				temp=shelf[j];
				shelf[j]=shelf[b];
				shelf[b]=temp;
			}
		}
	}
	printf("\n%d\n\n",shelf[k]);
}
