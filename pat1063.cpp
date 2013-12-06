/*
简单题 用set对输入的数据去重 同时set里默认是按升序存放 刚好起到排序作用
输出到数组中之后再用两个游标分别前进的方法找到相同项
printf在输出时printf("%.1f%%\n",percent*100); %.1f表示输出一位小数 %%表示用转义符输出一个真·百分号
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	int m;
	int index;
	int sets[50][10001];
	set<int> tmpset;
	int tmp;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&m);
		tmpset.clear();
		for(int j=0;j<m;++j)
		{
			scanf("%d",&tmp);
			tmpset.insert(tmp);
		}
		sets[i][0]=tmpset.size();
		index=1;
		for(set<int>::iterator ite=tmpset.begin();ite!=tmpset.end();++ite)
		{
			sets[i][index++]=*ite;
		}
	}
	scanf("%d",&k);
	int i1,i2;
	int j1,j2;
	int t1,t2;
	int join;
	float percent;
	for(int i=0;i<k;++i)
	{
		scanf("%d%d",&i1,&i2);
		i1--;
		i2--;
		j1=1;
		j2=1;
		t1=sets[i1][0];
		t2=sets[i2][0];
		join=0;
		while(j1<=t1&&j2<=t2)
		{
			if(sets[i1][j1]>sets[i2][j2])
			{
				j2++;
			}
			else if(sets[i1][j1]<sets[i2][j2])
			{
				j1++;
			}
			else
			{
				j1++;
				j2++;
				join++;
			}
		}
		percent=join*1.0/(t1+t2-join);
		printf("%.1f%%\n",percent*100);
	}
	return 0;
}