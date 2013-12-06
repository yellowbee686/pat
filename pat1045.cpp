/*
������һ�����������������LIS ������DP���
�������ڱ���������ɫ�ĳ�ֽ���Ͻ�ȡ�涨�����ڵ�ֽ��˳�� ��LIS�ı��� ��˿��Խ����������ڵ���ɫֵ��Ϊ-1 ���������ڵ���ɫֵ��������±��ʾ
������ת��Ϊ��׼LIS ����dp[length]�е�dp[i]��Ϊ��s[i]��β���ֽ������ ���dp[i]������״̬ �ֱ�Ϊ��ʼ״̬1��j<i&&s[j]<=s[i]������dp[j]+1
*/
#include <iostream>
#include <algorithm>
int main()
{
	int m,n,k;
	int color[200];
	int s[10000];
	int dp[10000];
	int max=0;
	int tmp;
	bool flag;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<m;++i)
		scanf("%d",&color[i]);
	scanf("%d",&k);
	for(int i=0;i<k;++i)
		scanf("%d",&s[i]);
	for(int i=0;i<k;++i)
	{
		tmp=s[i];
		flag=false;
		for(int j=0;j<m;++j)
		{
			if(tmp==color[j])
			{
				flag=true;
				s[i]=j;
				break;
			}
		}
		if(!flag)
			s[i]=-1;
	}
	for(int i=0;i<k;++i)
	{
		dp[i]=1;
		for(int j=0;j<i;++j)
		{
			if(s[j]<=s[i]&&s[j]>=0)
				dp[i]=std::max(dp[i],dp[j]+1);
			
		}
		if(max<dp[i])
				max=dp[i];
	}
	printf("%d\n",max);
	return 0;
}