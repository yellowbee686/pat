/*
��ĳ����������������Ƿ��ܴﵽ�Գ��� ��Ϊ��Ӵ�������п��ܵ�100�� �����Ҫ���������洢����
*/
#include <iostream>
int a[100];
int sum[100];

bool ifP(int r)
{
	bool ret=true;
	for(int i=0;i<r/2;++i)
	{
		if(sum[i]!=sum[r-1-i])
		{
			ret=false;
			break;
		}
	}
	return ret;
}

int main()
{
	int k;
	long long n;	
	scanf("%lld%d",&n,&k);
	int right=0;
	while(n>0)
	{
		a[right++]=n%10;
		n/=10;
	}
	int offset;
	int tmp;
	int times=k;
	for(int i=0;i<right;++i)
		sum[i]=a[i];
	for(int i=0;i<k;++i)
	{
		offset=0;
		bool flag=ifP(right);
		if(flag)
		{
			times=i;
			break;
		}
		else
		{
			for(int j=0;j<right;++j)
				a[j]=sum[j];
		}
		for(int j=0;j<right;++j)
		{
			tmp=a[j]+a[right-1-j]+offset;
			sum[j]=tmp%10;
			if(tmp>=10)
				offset=1;
			else
				offset=0;
		}
		if(offset==1)
			sum[right++]=1;
		
	}
	for(int j=0;j<right;++j)
		printf("%d",sum[right-1-j]);
	printf("\n");
	printf("%d\n",times);
	return 0;
}