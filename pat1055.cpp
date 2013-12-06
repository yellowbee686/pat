/*
����ÿ���˵�������Ϣ�������� Ҫ�����Ȱ�worth�� �������ʱֻ����ض�����ε� ����Ȱ����������ҳ�ÿ�������֮����Ҫ�ٶ�С������������Ƚ���
������Ȱ�worth�� ��ÿ��queryʱ�ٱ���һ��Ѱ�ҷ��ϵ�age
����query��k�� ��N���100000 ageΪ200 ��ÿ��age����ƽ�����ܴﵽ500 ����Ŀ��ÿ��case�������100�� ��˰�worth�����ÿ�������101��ʼ�ľͿ�������
���������в�����ɾ�� ������н���һ������index��������Щ������������person��ԭ�����е��±� agenum���ڼ�¼ÿ��age������ ������lazy delete
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