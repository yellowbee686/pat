/*
题目中给的sample input是正整数 但题目中只说明为正数...
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
struct mooncake
{
	double storage;
	double price;
	double unitp;
}mks[MAX_N];

bool cmp(const mooncake &a,const mooncake &b)
{
	return a.unitp>b.unitp;
}

int main()
{
	int n,s;
	double sum=0.0;
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;++i)
		scanf("%lf",&mks[i].storage);
	for(int i=0;i<n;++i)
		scanf("%lf",&mks[i].price);
	for(int i=0;i<n;++i)
		mks[i].unitp=mks[i].price*1.0/mks[i].storage;
	sort(mks,mks+n,cmp);
	int j=0;
	while(s>0&&j<n)
	{
		if(s>=mks[j].storage)
		{			
			sum+=mks[j].price;
			s-=mks[j].storage;
		}
		else
		{			
			sum+=s*mks[j].unitp;
			s=0;
		}
		j++;
	}
	printf("%.2lf\n",sum);
	return 0;
}