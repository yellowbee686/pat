/*
�������n�����n-1���� �����·������ ���ڱߺ��� ������ڽӱ�����ȶ�ά�������Ч��
����˼·��������dfs ��һ����1Ϊ��� �ڶ����Ե�һ��dfs�õ�����Զ����Ϊ��� �����Ϳ����ҵ���Զ��·����
Ҫע�����dfs�е�lenָ����·������ ���ֻ��һ�����ʱ����Ϊ0����Ϊ���ڴ�ʱ����Ψһ��һ����Ž�ȥ ���maxlen�ĳ�ʼֵ��Ϊ-1
ͬʱ�����ڵ�һ�ξͱ����used������ж�ʱʹ��һ��set��������dfsʱ��û��ʹ�õ�ĳЩ��
�����Ŀ���л� ���ʹ������ͼ�ж������ ��ʱֻ��Ҫ��һ���ܹ������˼��ε�dfs�Ϳ���֪���м������� ����Ҫʹ�ò��鼯
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