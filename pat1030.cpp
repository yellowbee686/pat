/*
��dijkstra������̾��� ͬʱҪ��¼·�� ��������cost ��ͬ����ȡcost��С�� ���ͬ������d c��pre��������
������ʱ��Ϊvector��·���������ŵ�for(vector<int>::reverse_iterator rite=v.rbegin();rite!=v.rend();rite++)
Ҳ��������������з��� ��ʱ����++
ͬʱҪע����������ͼ�ڹ�ͼʱ�������ö�ά���黹�Ǳ�ʾ�ߵ�����+vector����ʽ ����Ҫע���start��end�Ե��洢����·��
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