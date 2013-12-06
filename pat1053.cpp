/*
简单的求有向图dfs 当叶子节点恰好满足weight时输出整个路径 因此在过程中用vector存储weight
因为是按weight的非升字典序排列 所以可以在每个路径节点处直接对所有路径进行排序
因为是一棵树 路径很少 因此用邻接表
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
		if(G[node].empty()) //判断叶子节点
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