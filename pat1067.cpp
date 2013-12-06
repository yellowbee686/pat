/*
模拟swap0会超时 但仔细想来 首先如果有x个数不在自己的位置上，只用swap0的话肯定至少会有x-1次
而如果在swap的过程中，每次0被换回a[0]时 都需要再消耗一次将它换给任意一个不在原位的数 因此cnt再+1
而在求0被换回a[0]时为了不超时 不能每次用for循环去找那个数 观察到用swap0和swap任意两个数其实是等同的
因此可以遍历数组 每次找到不在原位的数就从它开始替换，直到找到一个在原位的数为止 这样一次循环过程中
0肯定回到了a[0]一次
而如果一开始a[0]=0则需要多加2次 因为要先换走最后再换回来
*/
#include <iostream>
#define MAX_N 100000

int main()
{
	int n;
	int a[MAX_N];
	scanf("%d",&n);
	bool f[MAX_N]={false};
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==i)
			f[i]=true;
		else
			cnt++;
	}
	if(f[0])
		cnt+=2;
	int k;
	for(int i=0;i<n;++i)
	{
		k=a[i];
		if(!f[k])
		{
			cnt++;
			while(!f[k])
			{
				f[k]=true;
				k=a[k];
			}
		}
	}
	printf("%d\n",cnt-2);
	return 0;
}