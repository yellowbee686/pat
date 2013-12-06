#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct stu
{
	char num[14];
	int score;
	int loc;
}ss[30000];

bool cmp(const stu &a, const stu &b)
{
	bool ret;
	if(a.score>b.score)
		ret=true;
	else if (a.score<b.score)
		ret=false;
	else
	{
		if(strcmp(a.num,b.num)<0)
			ret=true;
		else
			ret=false;
	}
	return ret;
}

int main()
{
	int N,K,count;
	count=0;
	scanf("%d",&N);
	char tname[14];
	int tscore;
	int index=0;
	int nowrank[101];
	int nowpeople[101];
	int nowscore[101];
	fill(nowrank,nowrank+101,1);
	fill(nowpeople,nowpeople+101,0);
	fill(nowscore,nowscore+101,0);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&K);
		count+=K;
		for(int j=0;j<K;++j)
		{
			scanf("%s%d",&tname,&tscore);
			strcpy(ss[index].num,tname);
			ss[index].loc=i;
			ss[index].score=tscore;
			index++;
		}
	}
	sort(ss,ss+count,cmp);
	int tloc;
	printf("%d\n",count);
	for(int i=0;i<count;++i)
	{
		tloc=ss[i].loc;
		if(ss[i].score==nowscore[0])
		{
			nowpeople[0]++;
		}
		else
		{
			nowrank[0]+=nowpeople[0];
			nowpeople[0]=1;
			nowscore[0]=ss[i].score;
		}
		if(ss[i].score==nowscore[tloc])
		{
			nowpeople[tloc]++;
		}
		else
		{
			nowrank[tloc]+=nowpeople[tloc];
			nowpeople[tloc]=1;
			nowscore[tloc]=ss[i].score;
		}
		printf("%s %d %d %d\n",ss[i].num,nowrank[0],tloc,nowrank[tloc]);
	}
	return 0;
}