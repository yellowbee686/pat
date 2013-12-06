#include <stdio.h>

int main()
{
	int n;
	int distance[100010];
	long long leftDis, rightDis, dis;
	int i, t, start, end, j;
	scanf("%d", &n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&distance[i]);
	}
	scanf("%d", &t);
	for(i=0;i<t;++i)
	{
		scanf("%d%d",&start,&end);
		leftDis = rightDis = 0;
		j = start;
		while(j != end)
		{
			if(j == n)
			{
				rightDis += distance[j];
				j = 1;
			}
			else
			{
				rightDis += distance[j];
				j++;
			}
		}
		j = start;
		while(j != end)
		{
			if(j == 1)
			{
				j = n;
				leftDis += distance[j];			
			}
			else
			{
				j--;
				leftDis += distance[j];				
			}
		}
		if(leftDis <= rightDis)
		{
			dis = leftDis;
		}
		else
		{
			dis = rightDis;
		}
		printf("%d\n", dis);
	}
	return 0;
}