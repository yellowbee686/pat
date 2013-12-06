#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX_N 1011
int n,m,nm,k,ds;
int roads[MAX_N][MAX_N];
int d[MAX_N];
bool used[MAX_N];
struct gas
{
	int no;
	float minr;
	float avgr;
};
vector<gas> ansv;

bool cmp(const gas &a,const gas &b)
{
	bool ret;
	if(a.minr!=b.minr)
		ret=a.minr>b.minr;
	
	else if(a.avgr!=b.avgr)	
		ret=a.avgr<b.avgr;	
	else
		ret=a.no<b.no;
	return ret;
}
void dijk(int s)
{
	fill(d,d+nm,INT_MAX);
	fill(used,used+nm,false);
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<nm;u++)
			if(!used[u]&&(v==-1||d[u]<d[v]))
				v=u;
		if(v==-1)
			break;
		used[v]=true;
		for(int u=1;u<nm;u++)
			if(roads[v][u])
				d[u]=d[u]<(d[v]+roads[v][u])?d[u]:(d[v]+roads[v][u]);
	}
	bool flag=true;
	int sum=0;
	int mind=d[1];
	for(int i=1;i<=n;++i)
	{
		if(d[i]<=ds)
		{
			sum+=d[i];
			if(d[i]<mind)
				mind=d[i];
		}
		else
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		gas g;
		g.avgr=sum*1.0/n;
		g.minr=mind;
		g.no=s;
		ansv.push_back(g);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	nm=n+m+1;
	char tmps[5],tmpe[5];
	int w,s,e;
	while(k--)
	{
		scanf("%s%s%d",&tmps,&tmpe,&w);
		if(tmps[0]!='G')
		{
			s=atoi(tmps);
		}
		else
		{
			if(tmps[2]!='\0')
				s=10+n;
			else
				s=n+tmps[1]-'0';
		}
		if(tmpe[0]!='G')
		{
			e=atoi(tmpe);
		}
		else
		{
			if(tmpe[2]!='\0')
				e=10+n;
			else
				e=n+tmpe[1]-'0';
		}
		roads[s][e]=w;
		roads[e][s]=w;
	}
	for(int i=n+1;i<nm;++i)
		dijk(i);
	if(ansv.size()!=0)
	{
		sort(ansv.begin(),ansv.end(),cmp);
		gas g=ansv[0];
		printf("G%d\n",g.no-n);
		printf("%.1f %.1f\n",g.minr,g.avgr);
	}
	else
		printf("No Solution\n");
	return 0;
}