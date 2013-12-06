/*
用dijkstra计算最短距离 同时要记录路径 还加入了cost 相同距离取cost最小的 因此同步更新d c和pre三个数组
最后输出时因为vector中路径是逆序存放的for(vector<int>::reverse_iterator rite=v.rbegin();rite!=v.rend();rite++)
也有逆序迭代器进行访问 此时还是++
同时要注意这种无向图在构图时不管是用二维数组还是表示边的数组+vector的形式 都需要注意把start和end对调存储两遍路径
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 500
struct edge
{
	int to,dist,cost;
};
typedef pair<int,int> P;
vector<edge> G[MAX_N];
int d[MAX_N];
int pre[MAX_N];
int c[MAX_N];
void dijkstra(int s)
{
	d[s]=0;
	c[s]=0;
	priority_queue<P,vector<P>,greater<P>> que;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;
		if(p.first>d[v])
			continue;
		for(int i=0;i<G[v].size();++i)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.dist)
			{
				d[e.to]=d[v]+e.dist;
				c[e.to]=c[v]+e.cost;
				pre[e.to]=v;
				que.push(P(d[e.to],e.to));
			}
			else if(d[e.to]==d[v]+e.dist&&c[e.to]>c[v]+e.cost)
			{
				c[e.to]=c[v]+e.cost;
				pre[e.to]=v;
			}
		}
	}
}

int main()
{
	int n,m,start,end;
	scanf("%d%d%d%d",&n,&m,&start,&end);
	fill(d,d+n,INT_MAX);
	fill(c,c+n,INT_MAX);
	fill(pre,pre+n,-1);
	int s,t,dd,cc;
	while(m--)
	{
		scanf("%d%d%d%d",&s,&t,&dd,&cc);
		edge e1,e2;
		e1.cost=cc;
		e1.to=t;
		e1.dist=dd;
		e2.cost=cc;
		e2.dist=dd;
		e2.to=s;
		G[s].push_back(e1);
		G[t].push_back(e2);
	}
	dijkstra(start);
	vector<int> v;
	int tmp=end;
	while(pre[tmp]!=-1)
	{
		v.push_back(tmp);
		tmp=pre[tmp];
	}
	v.push_back(tmp);
	for(vector<int>::reverse_iterator rite=v.rbegin();rite!=v.rend();rite++)
		printf("%d ",*rite);
	printf("%d %d\n",d[end],c[end]);
	return 0;
}