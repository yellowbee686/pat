/*
使用树状数组才AC的题目 同时将cin cout全部换成scanf printf 时间缩短一半以上...
find(k)是找第k小的值
*/
#include <iostream>
#include <stack>
using namespace std;
#define MAX_N 100001

int bit[MAX_N];

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

void add(int i, int x)
{
	while(i<MAX_N)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}

int find(int k)
{
	int lb=0,ub=MAX_N-1,mid;
	while(lb+1<ub)
	{
		mid=(lb+ub)/2;
		if(sum(mid)>=k)
			ub=mid;
		else
			lb=mid;
	}
	return lb+1;
}

int main()
{
	int n;
	scanf("%d",&n);
	char cmd[15];
	stack<int> s;
	int tmp;
	int idx;
	while(n--)
	{
		scanf("%s",&cmd);
		if(cmd[1]=='u')
		{
			scanf("%d",&tmp);
			s.push(tmp);
			add(tmp,1);
		}
		else if(cmd[1]=='o')
		{
			if(s.size())
			{
				tmp=s.top();
				s.pop();
				add(tmp,-1);
				printf("%d\n",tmp);
			}
			else
				printf("Invalid\n");			
		}
		else
		{
			if(s.size())
			{
				idx=(s.size()+1)/2;
				printf("%d\n",find(idx));
			}
			else
				printf("Invalid\n");				
		}
	}
	return 0;
}