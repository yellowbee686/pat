#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef pair<int,int> P;
#define MAX_N 100000
int cash[MAX_N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int k=0;k<n;++k)
		scanf("%d",&cash[k]);
	int i=0;
	int j=0;
	int sum=cash[i];
	int diff=INT_MAX;
	vector<P> v;
	while(true)
	{
		if(i>=n||j>=n)
			break;
		if(sum<m)
		{
			j++;
			sum+=cash[j];
		}
		else
		{
			if(sum-m<diff)
			{
				diff=sum-m;
				v.clear();
				v.push_back(P(i,j));
			}
			else if(sum-m==diff)
			{
				v.push_back(P(i,j));
			}
			sum-=cash[i];
			i++;			
		}
	}
	for(int k=0;k<v.size();++k)
	{
		printf("%d-%d\n",v[k].first+1,v[k].second+1);
	}
	return 0;
}