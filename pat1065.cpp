/*
long long为64位 因此两者的和继续用long long来存储则有可能溢出 而溢出之后只需要判断和的符号是否改变即可 因为只有在两个数同符号的可能下才会溢出
*/
#include <stdio.h>

int main()
{
	int t;
	long long a,b,c;
	long long sum;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("Case #%d: ",i);
		sum = a + b;
		if(a>0&&b>0&&sum<=0)
		{
			printf("true\n");
		}
		else if(a<0&&b<0&&sum>=0)
		{
			printf("false\n");
		}
		else
		{
			if(sum>c)
				printf("true\n");
			else
				printf("false\n");
		}
	}
	return 0;
}