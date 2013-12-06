/*
对倒排索引的模拟 给出每个学生的选课单 要求模拟每门课的学生名单 
由于直接开int的二维数组用来存放选课情况会出现内存溢出 因此可以用char型 也可以利用该矩阵数组的稀疏性转化为开vector<int>
cnk[]用于存放每门课的选课人数 st[]用于建立一个存放学生名字和下标的struct数组 这样在vector中就不需要存名字只需要存下标 节省空间
不过在本题中每个名字都只有4位 用char型表示的话直接存名字消耗是一样的...
mycompare的比较中只要给出结果即可 不在意比较的是什么 即可以用st中的name比较
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