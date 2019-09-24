#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Declaring Global variables.
int i,j,k,m,n;
float a[20][20];
float x[20]={8.0};

//Decalaration of the Function used in the program
void gaussElimination(float a[20][20],int m, int n);
int backSubstitution(float a[20][20],float x[20], int m, int n);
void rowsSwapping(float a[20][20], int r1, int rowlength, int r2);
void solution(float a[20][20],float x[20], int m, int n);

void rowsSwapping(float m[20][20],int r1,int ROWLENGTH,int r2)
{
	int i;
	for (i=1; i<=ROWLENGTH; i++)
	{
		float temp;
		temp = m[r2][i];
		m[r2][i] = m[r1][i];
		m[r1][i] = temp;
	}
}
void userDetails()
{
	int m,n;
	printf("\t\t\tEnter number of columns of matrix:");
	scanf("%d",&n);
	printf("\t\t\tEnter number of rows of matrix:");	
	scanf("%d",&m);

	printf("Enter the Augmented matrix:\n");
	int i,j;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n+1; j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	gaussElimination(a,m,n);
}

void gaussElimination(float a[20][20],int m, int n)
{
	int fu;
	float proportion;
	int i,j;
	for(i=1; i<=m-1; i++)
	{
		int flag=0;
		printf("\n");
		if(a[i][i] == 0)
		{
			for(j=i+1; j<=m; j++)
			{
				if(a[j][i]!=0)
				{
					flag=1;
					rowsSwapping(a,i,n+1,j);
					break;
				}
			}
		}
		if(flag==0 && a[i][i]==0.0)
		{
			continue;
		}
		for(fu=i+1; fu<=m; fu++)
		{
			proportion = a[fu][i]/a[i][i];
			for(k=1; k<=n+1; k++)
			{
				a[fu][k] = a[fu][k] - proportion*a[i][k];
			}
		}
	 }
	for(i=1; i<=n; i++)
		x[i]=8.0;

	backSubstitution(a,x,m,n);
}

int backSubstitution(float a[20][20],float x[20], int m, int n)
{
	int inf_flag=0,jj;
	int temp_cnt=0;
	int free_var=0;
	int ff=0;
	int override_cnt=0;

	int i,j;
	
	for(i=m;i>=1;i--)
	{
		temp_cnt=0;
		ff=0;
		for(j=1;j<=n;j++)
		{
			if(a[i][j]!=0 && (x[j]==8.0 || x[j]==420) )
			{
				temp_cnt++;
			}
		}

		if(temp_cnt==0)
		{
			if(a[i][n+1]!=0 )
			{
				printf("\n");
				printf("-------------------------NO SOLUTION of the Given Equation-------------------- ");
				return 0;
			}
			else
			{
				continue;
			}
		}
		else
		{
			if(temp_cnt==1)
			{
				override_cnt=0;
				int idx1=-1,idx2=-1;
				int j;
				for(j=1;j<=n;j++)
				{
					if(x[j]!=8.0)
					{
						a[i][n+1]=a[i][n+1]-(a[i][j]*x[j]);
					}
				}

				for(j=1; j<=n; j++)
				{
					if(a[i][j]!=0 && x[j]==8.0 && x[j]!=420 )
						x[j]=a[i][n+1]/a[i][j];
					else
						override_cnt++;

				}
				if(override_cnt==n)
				{
					for(j=n; j>=1; j--)
					{
						if(a[i][j]!=0)
						{
							idx1=j;
							break;
						}

					}
					for(j=n; j>=1; j--)
					{
						if(a[i+1][j]!=0)
						{
							idx2=j;
							break;
						}
					}
					if(idx1==idx2)
					{
						if( (a[i][n+1]/a[i][idx1]) != (a[i+1][n+1]/a[i+1][idx2]) )
						{
						    printf("------------No solution of the Given Equation ----------------");
						    printf("\n");
							return 0;
						}
					}
					else
						continue;
				}
			}
			else
			{
				override_cnt=0;
				int idx1=-1,idx2=-1;
			int j;
				for(j=1;j<=n;j++)
				{
					if(x[j]!=8.0)
					{
						a[i][n+1]=a[i][n+1]-(a[i][j]*x[j]);
					}
				}
				inf_flag=1;
				free_var = free_var+ temp_cnt-1;
				for(j=1;j<=n;j++)
				{
					if(ff==(temp_cnt-1))
					{
						break;
					}
					if(a[i][j]!=0 && x[j]==8.0 && x[j]!=420)
					{
					    x[j]=420;
						a[i][n+1]=a[i][n+1]-a[i][j]*x[j];
						ff++;
					}
					else
					override_cnt++;
				}

				if(override_cnt==n)
				{
					for(j=n; j>=1; j--)
					{
						if(a[i][j]!=0)
						{
							idx1=j;
							break;
						}

					}
					for(j=n; j>=1; j--)
					{
						if(a[i+1][j]!=0)
						{
							idx2=j;
							break;
						}

					}
					if(idx1==idx2)
					{
						if( (a[i][n+1]/a[i][idx1]) != (a[i+1][n+1]/a[i+1][idx2]) )
						{
						    printf("------------------------No solution of the given Equation--------------------\n");
							return 0;
						}
					}
					else
						continue;
				}
				printf("\n");
				
				
				for(jj=j;jj<=n;jj++)
				{
					if(a[i][jj]!=0 && x[jj]==8.0)
					{
					x[jj]=a[i][n+1]/a[i][jj];
					}
				}
			}
		}
	}
	int infi_flag=0;
	
	for(i=1;i<=n;i++)
	{
		if(x[i] == 8.0 || x[i]-(float)420 == 0)
		{
			infi_flag=1;
		}
	}

	if(infi_flag==0)
		printf("----------------------UNIQUE SOLUTION of the Given Equation--------------------");
	else
		printf("----------------------INFINITE SOLUTION OF THE Given Equation--------------------");
	printf("\nSolution of the Given Equation is :\n");
	solution(a,x,m,n);

}
void solution(float a[20][20], float x[20],int m, int n)
{
    int i,j;
	for(i=1; i<=n; i++)
	{
		if(x[i]!=8.0)
			printf("x[%d] = %f\n",i, x[i]);
		else
		{
			x[i]=420;
			printf("x[%d] = %f\n",i, x[i]);
		}
	}

}
int main()
{
	userDetails();
	return(0);
}
