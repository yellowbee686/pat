/*
���� ��set�����������ȥ�� ͬʱset��Ĭ���ǰ������� �պ�����������
�����������֮�����������α�ֱ�ǰ���ķ����ҵ���ͬ��
printf�����ʱprintf("%.1f%%\n",percent*100); %.1f��ʾ���һλС�� %%��ʾ��ת������һ���桤�ٷֺ�
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