/*
�Ե���������ģ�� ����ÿ��ѧ����ѡ�ε� Ҫ��ģ��ÿ�ſε�ѧ������ 
����ֱ�ӿ�int�Ķ�ά�����������ѡ�����������ڴ���� ��˿�����char�� Ҳ�������øþ��������ϡ����ת��Ϊ��vector<int>
cnk[]���ڴ��ÿ�ſε�ѡ������ st[]���ڽ���һ�����ѧ�����ֺ��±��struct���� ������vector�оͲ���Ҫ������ֻ��Ҫ���±� ��ʡ�ռ�
�����ڱ�����ÿ�����ֶ�ֻ��4λ ��char�ͱ�ʾ�Ļ�ֱ�Ӵ�����������һ����...
mycompare�ıȽ���ֻҪ����������� ������Ƚϵ���ʲô ��������st�е�name�Ƚ�
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

struct Student
{
	char name[5];
	int id;
}st[40001];

bool mycompare(int a,int b)
{
	return strcmp(st[a].name,st[b].name)<0;
}

int main()
{
	int n,k;
	int cnk[2501]={0};
	vector<int> ve[2501];
	scanf("%d%d",&n,&k);
	int cid,num;
	for(int i=0;i<n;i++)
	{
		st[i].id = i;
		scanf("%s%d",st[i].name,&num);
		for(int j=0;j<num;j++)
		{
			scanf("%d",&cid);
			cnk[cid]++;
			ve[cid].push_back(i);
		}
	}
	for(int i=0;i<=k;i++)
		sort(ve[i].begin(),ve[i].end(),mycompare);

	for(int i=1;i<=k;i++)
	{
		cout<<i<<" "<<ve[i].size()<<endl;
		for(int j=0;j<ve[i].size();j++)
		printf("%s\n",st[ve[i][j]].name);
	}
	return 0;
}