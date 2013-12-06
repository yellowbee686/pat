/*
��һ������ͼ���ж��ٸ���ͨ���� ֱ����·������� ��ÿ�η���һ���µ���ͨ����ʱ��BFS�������нڵ����һ��gang
ÿ���ڵ��cnt���Ǹýڵ��weight֮�� ����������ͼÿ��weight������������ thresholdҲҪ*2
���ڱ�Ŷ�ʹ�õ��ַ��� ���ʹ����map������ �������鷳...
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
struct relation
{
	int weight;
	string with;
};

bool cmp(const relation &a,const relation &b)
{
	return a.with<b.with;
}

int main()
{
	int n,threshold;
	scanf("%d%d",&n,&threshold);
	threshold*=2;
	map<string,vector<relation>> mm;
	vector<relation> ans;
	string sa,sb;
	int tmpw;
	map<string,vector<relation>>::iterator ite;
	relation r;
	while(n--)
	{
		cin>>sa>>sb>>tmpw;
		ite=mm.find(sa);
		if(ite==mm.end())
		{
			r.with=sb;
			r.weight=tmpw;
			vector<relation> v;
			v.push_back(r);
			mm.insert(make_pair(sa,v));
		}
		else
		{
			bool flag=true;
			for(int i=0;i<ite->second.size();++i)			
				if(ite->second[i].with==sb)
				{
					ite->second[i].weight+=tmpw;
					flag=false;
					break;
				}
			if(flag)
			{
				r.with=sb;
				r.weight=tmpw;
				ite->second.push_back(r);
			}
		}

		ite=mm.find(sb);
		if(ite==mm.end())
		{
			r.with=sa;
			r.weight=tmpw;
			vector<relation> v;
			v.push_back(r);
			mm.insert(make_pair(sb,v));
		}
		else
		{
			bool flag=true;
			for(int i=0;i<ite->second.size();++i)			
				if(ite->second[i].with==sa)
				{
					ite->second[i].weight+=tmpw;
					flag=false;
					break;
				}
			if(flag)
			{
				r.with=sa;
				r.weight=tmpw;
				ite->second.push_back(r);
			}
		}
	}

	set<string> used;
	map<string,int> gang;
	int sum;
	for(ite=mm.begin();ite!=mm.end();ite++)
		if(used.find(ite->first)==used.end())
		{
			sum=0;
			gang.clear();		
			queue<string> que;
			que.push(ite->first);
			gang.insert(make_pair(ite->first,0));
			while(!que.empty())
			{
				string s=que.front();que.pop();
				map<string,vector<relation>>::iterator it=mm.find(s);
				vector<relation> v=it->second;
				int cnt=0;
				for(int i=0;i<v.size();++i)
				{
					cnt+=v[i].weight;
					if(gang.find(v[i].with)==gang.end())
					{
						que.push(v[i].with);
						gang.insert(make_pair(v[i].with,0));
					}
				}
				sum+=cnt;
				map<string,int>::iterator mit=gang.find(s);
				mit->second+=cnt;
				used.insert(s);
			}
			if(gang.size()>2&&sum>threshold)
			{
				int max=0;
				string maxs;
				for(map<string,int>::iterator mit=gang.begin();mit!=gang.end();mit++)
					if(mit->second>max)
					{
						max=mit->second;
						maxs=mit->first;
					}
				r.with=maxs;
				r.weight=gang.size();
				ans.push_back(r);
			}
		}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans.size()<<endl;
	for(int j=0;j<ans.size();++j)
		cout<<ans[j].with<<" "<<ans[j].weight<<endl;
	return 0;
}