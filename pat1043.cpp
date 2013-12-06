#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000

int tellBST(int n, int *a, int*post, int mirrorFlag)
{
	int flag = 1;
	//i代表左子树，j代表右子树
	int flagi, flagj;
	int i, j;
	int numi, numj;

	//n等于1时这个子树肯定是BST
	if(n>1)
	{
		for(i=1;i<n;++i)
		{
			if(!mirrorFlag&&*(a+i)>=*a)
			{
				numi = i-1;
				break;
			}
			if(mirrorFlag&&*(a+i)<*a)
			{
				numi = i-1;
				break;
			}
			if(i == n-1)
			{
				numi = i;
			}
		}
		for(j=numi+1;j<n;++j)
		{
			if(!mirrorFlag&&*(a+j)<*a)
			{
				flag = 0;
				break;
			}
			if(mirrorFlag&&*(a+j)>=*a)
			{
				flag = 0;
				break;
			}
			if(j == n-1)
			{
				numj = n - 1 - numi;
			}
		}
		if(flag)
		{
			if(numi)
			{
				flagi = tellBST(numi,a+1,post, mirrorFlag);
			}
			else
			{
				flagi = 1;
			}
			if(numj)
			{
				flagj = tellBST(numj,a+numi+1,post+numi, mirrorFlag);
			}
			else
			{
				flagj = 1;
			}
			
			if(!flagi || !flagj)
			{
				flag = 0;
			}
		}
	}
	if(n>=1)
	{
		*(post+n-1) = *a;
	}
	return flag;
}

int main()
{
	int n;
	int i;
	int a[MAX];
	int post[MAX];
	int flag1, flag2;

	scanf("%d",&n);
	memset(post,0,MAX*sizeof(int));
	memset(a,0,MAX*sizeof(int));
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	flag1 = tellBST(n,a,post,0);
	flag2 = tellBST(n,a,post,1);
	if(flag1||flag2)
	{
		printf("YES\n");
		for(i = 0; i < n; ++i)
		{
			if(i == n-1)
			{
				printf("%d\n", post[i]);
			}
			else
			{
				printf("%d ", post[i]);
			}
		}

	}
	else
	{
		printf("NO\n");
	}
	return 0;
}