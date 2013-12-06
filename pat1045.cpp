/*
本题是一道最长递增子序列问题LIS 可以用DP解决
本题是在标有数字颜色的长纸带上截取规定数组内的纸带顺序 是LIS的变形 因此可以将不在数组内的颜色值设为-1 而在数组内的颜色值用数组的下标表示
这样就转化为标准LIS 即将dp[length]中的dp[i]设为以s[i]结尾的最长纸带长度 因此dp[i]有两种状态 分别为初始状态1和j<i&&s[j]<=s[i]这样的dp[j]+1
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