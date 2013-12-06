/*
0-1背包问题 给定一堆钱币问能否恰好组合成指定的币值m
f[i][j]表示用前i枚硬币能组合出的不超过j的最大币值 因此递推公式为f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+a[i])
而如果最后f[n-1][m]!=m则说明没有solution
因为要输出的是字典序最小的序列 因此将数组非升序排列 因为路径还原找每个币是否用过是从后向前找的
同时因为要维持最小字典序 当f[i-1][j]==f[i-1][j-a[i]]+a[i]时采用a[i](a[i]肯定不大于前面所使用的钱币币值)
*/
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N=10001;
const int MAX_M=101;
int f[MAX_N][MAX_M];
bool  h[MAX_N][MAX_M];
int main()
{
	int n,m;
	int a[MAX_N];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	for(int j=0;j<=m;++j)	
		if(j>=a[0])
		{
			f[0][j]=a[0];
			h[0][j]=true;
		}
	
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
		{
			if(j-a[i]<0)
			{
				//当肯定无法满足时要记得更新f[i][j]，不然后面的会出错
				f[i][j]=f[i-1][j];
				continue;
			}
			int tmp=f[i-1][j-a[i]]+a[i];
			if(f[i-1][j]<=tmp)
			{
				f[i][j]=tmp;
				h[i][j]=true;
			}
			else
				f[i][j]=f[i-1][j];
		}
	int idx=n-1;
	//路径还原 如果h[idx][m]==true 则说明达到m用到了a[idx]，下一步再检验h[idx-1][m-a[idx]]
	//如果没用到a[idx]则检验 h[idx-1][m]
	if(f[idx][m]==m)
	{
		while(m>0)
		{
			if(h[idx][m])
			{
				m-=a[idx];
				if(m)
					printf("%d ",a[idx]);
				else
					printf("%d\n",a[idx]);
			}
			idx--;
		}
	}
	else
		printf("No Solution\n");
	return 0;
}