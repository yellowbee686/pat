#include <iostream>
#include <math.h>
#define MAX 1000

bool ifPrime(int n)
{
	bool ret=true;
	int i=2;
	while(i<=sqrt(n*1.0))
	{
		if(n%i==0)
		{
			ret=false;
			break;
		}
		++i;
	}
	return ret;
}

int main()
{
	int p[MAX];
	long long n;
	scanf("%lld",&n);
	double limit=sqrt(n*1.0);
	if(n==2||n==3)
		limit=n;
	int size=0;
	int tmp=2;
	while(tmp<=limit&&size<MAX)
	{
		if(ifPrime(tmp))
		{
			p[size++]=tmp;
		}
		++tmp;
	}
	printf("%lld=",n);
	if(n==1)
		printf("1");
	int factor;
	bool first=true;
	int count;	
	for(int i=0;i<size&&n>1;++i)
	{
		count=0;
		factor=p[i];
		while(n%factor==0)
		{
			n/=factor;
			count++;
		}
		if(count)
		{
			if(first)
			{
				printf("%d",factor);
				first=false;
			}
			else
			{
				printf("*%d",factor);
			}
			if(count>1)
				printf("^%d",count);
		}
	}
	printf("\n");
	return 0;
}