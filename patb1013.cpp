#include <iostream>
#include <cmath>
#define MAX 10001
int prime[MAX];
int pi;

bool ifPrime(int n)
{
	int i=0;
	bool flag=true;
	if(n>3)
	{
		while(i<pi&&prime[i]<=sqrt(n*1.0))
		{
			if(n%prime[i]==0)
			{
				flag=false;
				break;
			}
			else
			{
				++i;
			}
		}
	}
	else if(n==1)
	{
		flag=false;
	}
	return flag;
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int num=1;
	while(pi<n)
	{
		if(ifPrime(num))
			prime[pi++]=num;
		num++;		
	}
	int cnt=0;
	
	for(int i=m-1;i<n;++i)
	{
		if(cnt==0)
			printf("%d",prime[i]);
		else
			printf(" %d",prime[i]);
		cnt++;
		if(cnt==10)
		{
			printf("\n");
			cnt=0;
		}
	}
	return 0;
}