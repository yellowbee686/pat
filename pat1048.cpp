/*
������Ӳ�Ҵ������� ������Ӳ��������ٶ������϶� ֱ���ö���ѭ���ᳬʱ ����뵽�����������Ӳ������ �±��ʾ��ֵ
*/
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;
	int coins[1001];
	int tmp;
	bool notfound=true;
	memset(coins,0,sizeof(coins));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		coins[tmp]++;
	}
	for(int i=1;i<=m/2;++i)
	{
		if(coins[i]>0)
		{
			coins[i]--;
			if(coins[m-i]>0)
			{
				printf("%d %d\n",i,m-i);
				notfound=false;
				break;
			}
		}
	}
	if(notfound)
		printf("No Solution\n");
	return 0;
}