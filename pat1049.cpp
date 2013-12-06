#include <iostream>

long long onesum(int n)
{
	long long count=0;
	int factor=1;
	int lowerNum=0;
	int currNum=0;
	int higherNum=0;
	while(n/factor!=0)
	{
		lowerNum=n-(n/factor)*factor;
		currNum=(n/factor)%10;
		higherNum=n/(factor*10);
		switch(currNum)
		{
		case 0:
			count+=higherNum*factor;
			break;
		case 1:
			count+=higherNum*factor+lowerNum+1;
			break;
		default:
			count+=(higherNum+1)*factor;
			break;
		}
		factor*=10;
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long ans=onesum(n);
	printf("%lld\n",ans);
	return 0;
}