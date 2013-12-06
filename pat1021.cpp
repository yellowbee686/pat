/*
本题给出n个点和n-1条边 问最长的路径顶点 由于边很少 因此用邻接表来存比二维数组更有效率
解题思路是用两次dfs 第一次以1为起点 第二次以第一次dfs得到的最远顶点为起点 这样就可以找到最远的路径了
要注意的是dfs中的len指的是路径长度 因此只有一个点的时候设为0，而为了在此时把这唯一的一个点放进去 因此maxlen的初始值设为-1
同时由于在第一次就标记了used，因此判断时使用一个set来标记这次dfs时有没有使用到某些点
如果题目中有环 则会使得整个图有多个部分 此时只需要数一数总共进行了几次的dfs就可以知道有几个部分 不需要使用并查集
*/
#include <iostream>
#include <set>
#include <vector>
#define MAX_N 10010
using namespace std;

vector<int> G[MAX_N];
bool used[MAX_N];
int maxlen=-1;
vector<int> maxv;
set<int> onceused;
void dfs(int n, int len)
{
	used[n]=true;
	onceused.insert(n);
	bool flag=true;
	for(int i=0;i<G[n].size();++i)
	{
		if(onceused.find(G[n][i])==onceused.end())
		{
			dfs(G[n][i],len+1);
			flag=false;
		}
	}
	if(flag)
	{
		if(len>maxlen)
		{
			maxv.clear();
			maxv.push_back(n);
			maxlen=len;
		}
		else if(len==maxlen)
		{
			maxv.push_back(n);
		}
	}
}

int main()
{
	int n,s,t,tmp,cnt=0;
	set<int> ans;	
	scanf("%d",&n);
	for(int i=0;i<n-1;++i)
	{
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		G[t].push_back(s);
	}
	for(int i=1;i<=n;++i)
	{		
		if(!used[i])
		{
			cnt++;
			onceused.clear();
			dfs(i,0);
			tmp=maxv[0];
			ans.insert(maxv[0]);
			onceused.clear();
			maxv.clear();
			maxlen=-1;
			dfs(tmp,0);
		}
	}
	if(cnt==1)
	{
		for(int j=0;j<maxv.size();++j)
			ans.insert(maxv[j]);				
		for(set<int>::iterator ite=ans.begin();ite!=ans.end();++ite)
			printf("%d\n",*ite);
	}
	else if(cnt>1)
	{
		printf("Error: %d components\n",cnt);
	}
	else
	{
		printf("1\n");
	}
	return 0;
}