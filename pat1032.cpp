/*
ģ������ ���ڵ�ַ����Ϊ5λ ��˿�����int���������ģ�� ����indexΪ��ǰ��ַ ������Ϊָ�����һ����ַ
������һ��ͬ����С�������ʾ�Ƿ���ʹ� �ȱ�����һ������ �ѷ��ʹ��Ķ���Ϊtrue �ڶ����������ʱ��true�ľ����
��Ҫע�������Ϊint��֮�������ʱ��Ҫ��ȫ0 ��˳���-1֮��Ҫ���printf("%05d\n",out);
ͬʱ������ʱ��Ҫ�Ե�û�õ�data�� ��dataΪcharʱ �м�Ŀո�Ҳ��ռ��data �����scanf("%d %c %d",&addr,&data,&naddr);
��scanf�мӿո������õ�
*/
#include <iostream>
#define MAX_N 100000
int next[MAX_N];
bool visited[MAX_N];

int main()
{
	int as,bs,n;
	scanf("%d%d%d",&as,&bs,&n);
	int addr,naddr;
	char data;
	while(n--)
	{
		scanf("%d %c %d",&addr,&data,&naddr);
		next[addr]=naddr;
	}
	addr=as;
	while(addr!=-1)
	{
		visited[addr]=true;
		addr=next[addr];
	}
	addr=bs;
	int out=-1;
	while(addr!=-1)
	{
		if(visited[addr])
		{
			out=addr;
			break;
		}
		else
		{
			addr=next[addr];
		}
	}
	if(out!=-1)
		printf("%05d\n",out);
	else
		printf("-1");
	return 0;
}