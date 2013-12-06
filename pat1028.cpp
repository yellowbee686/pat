#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100000
struct stu
{
	char no[7];
	char name[9];
	int score;
}ss[MAX_N];

bool cmp1(const stu &a,const stu &b)
{
	bool ret;
	if(strcmp(a.no,b.no)<0)
		ret=true;
	else
		ret=false;
	return ret;
}

bool cmp2(const stu &a,const stu &b)
{
	bool ret;
	if(strcmp(a.name,b.name)<0)
		ret=true;
	else if(strcmp(a.name,b.name)>0)
		ret=false;
	else
	{
		if(strcmp(a.no,b.no)<0)
			ret=true;
		else
			ret=false;
	}
	return ret;
}

bool cmp3(const stu &a,const stu &b)
{
	bool ret;
	if(a.score<b.score)
		ret=true;
	else if(a.score>b.score)
		ret=false;
	else
	{
		if(strcmp(a.no,b.no)<0)
			ret=true;
		else
			ret=false;
	}
	return ret;
}

int main()
{
	int N,C;
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;++i)
	{
		scanf("%s%s%d",&ss[i].no,&ss[i].name,&ss[i].score);
	}
	switch (C)
	{
	case 1:
		sort(ss,ss+N,cmp1);
		break;
	case 2:
		sort(ss,ss+N,cmp2);
		break;
	case 3:
		sort(ss,ss+N,cmp3);
		break;
	}
	for(int i=0;i<N;++i)
	{
		printf("%s %s %d\n",ss[i].no,ss[i].name,ss[i].score);
	}
	return 0;
}