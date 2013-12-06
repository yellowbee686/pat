/*
�򵥵�������ͼdfs ��Ҷ�ӽڵ�ǡ������weightʱ�������·�� ����ڹ�������vector�洢weight
��Ϊ�ǰ�weight�ķ����ֵ������� ���Կ�����ÿ��·���ڵ㴦ֱ�Ӷ�����·����������
��Ϊ��һ���� ·������ ������ڽӱ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100
struct road
{
	int to;
	int weight;
};
bool cmp(const road &a, const road &b)
{
	return a.weight>b.weight;
}
vector<road> G[MAX_N];
int w[MAX_N];
void dfs(int weight, int node, vector<int> v)
{
	if(weight==0)
	{
		if(G[node].empty()) //�ж�Ҷ�ӽڵ�
		{
			for(int i=0;i<v.size();++i)
				printf("%d ",v[i]);
			printf("%d\n",w[node]);
		}
	}
	else if(weight>0)
	{
		v.push_back(w[node]);
		for(int i=0;i<G[node].size();++i)
		{
			dfs(weight-G[node][i].weight,G[node][i].to,v);
		}
	}
}
int main()
{
	int n,m,weight;
	scanf("%d%d%d",&n,&m,&weight);
	for(int i=0;i<n;++i)
		scanf("%d",&w[i]);
	int roadnum,node;	
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&node,&roadnum);
		while(roadnum--)
		{
			road tmp;
			scanf("%d",&tmp.to);
			tmp.weight=w[tmp.to];
			G[node].push_back(tmp);
		}
		sort(G[node].begin(),G[node].end(),cmp);
	}
	weight-=w[0];
	vector<int> v;
	dfs(weight,0,v);
	return 0;
}