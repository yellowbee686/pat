/*
long longΪ64λ ������ߵĺͼ�����long long���洢���п������ �����֮��ֻ��Ҫ�жϺ͵ķ����Ƿ�ı伴�� ��Ϊֻ����������ͬ���ŵĿ����²Ż����
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