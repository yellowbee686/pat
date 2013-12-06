/*
给定每个人的三条信息进行排序 要求首先按worth排 但在输出时只输出特定年龄段的 如果先按年龄排在找出每个年龄段之后都需要再对小数组调用排序会比较慢
因此首先按worth排 在每次query时再遍历一遍寻找符合的age
由于query有k次 而N最大100000 age为200 则每个age的人平均可能达到500 但题目中每个case至多输出100个 因此按worth排序后每个年龄段101开始的就可以舍弃
由于数组中不好做删除 因此另行建立一个数组index用来存那些被保留下来的person在原数组中的下标 agenum用于记录每个age的人数 这属于lazy delete
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100000
struct person
{
	char name[9];
	int age;
	int worth;
}ss[MAX];
bool cmp(const person &a,const person &b)
{
	bool ret;
	if(a.worth!=b.worth)
		ret=a.worth>b.worth;
	else if(a.age!=b.age)
		ret=a.age<b.age;
	else
	{
		ret=strcmp(a.name,b.name)<=0;
	}
	return ret;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
		scanf("%s%d%d",&ss[i].name,&ss[i].age,&ss[i].worth);
	sort(ss,ss+n,cmp);
	int m,amin,amax;
	int agenum[205]={0};
	int len=0;
	int index[100000];
	for(int i=0;i<n;++i)
	{
		if(agenum[ss[i].age]<=100)
		{
			index[len++]=i;
			agenum[ss[i].age]++;
		}
	}
	int cnt;
	int tmpage;
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d%d",&m,&amin,&amax);
		cnt=0;
		printf("Case #%d:\n",i);
		for(int j=0;j<len&&cnt<m;++j)
		{
			tmpage=ss[index[j]].age;
			if(tmpage>=amin&&tmpage<=amax)
			{
				printf("%s %d %d\n",ss[index[j]].name,ss[index[j]].age,ss[index[j]].worth);
				cnt++;
			}
		}
		if(cnt==0)
			printf("None\n");
	}
	return 0;
}