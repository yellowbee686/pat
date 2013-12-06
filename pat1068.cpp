/*
0-1�������� ����һ��Ǯ�����ܷ�ǡ����ϳ�ָ���ı�ֵm
f[i][j]��ʾ��ǰiöӲ������ϳ��Ĳ�����j������ֵ ��˵��ƹ�ʽΪf[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+a[i])
��������f[n-1][m]!=m��˵��û��solution
��ΪҪ��������ֵ�����С������ ��˽�������������� ��Ϊ·����ԭ��ÿ�����Ƿ��ù��ǴӺ���ǰ�ҵ�
ͬʱ��ΪҪά����С�ֵ��� ��f[i-1][j]==f[i-1][j-a[i]]+a[i]ʱ����a[i](a[i]�϶�������ǰ����ʹ�õ�Ǯ�ұ�ֵ)
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
				//���϶��޷�����ʱҪ�ǵø���f[i][j]����Ȼ����Ļ����
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
	//·����ԭ ���h[idx][m]==true ��˵���ﵽm�õ���a[idx]����һ���ټ���h[idx-1][m-a[idx]]
	//���û�õ�a[idx]����� h[idx-1][m]
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