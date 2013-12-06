/*
模拟链表 由于地址给定为5位 因此可以用int型数组进行模拟 数组index为当前地址 数组项为指向的下一个地址
再申请一个同样大小的数组表示是否访问过 先遍历第一个链表 把访问过的都设为true 第二个链表遍历时有true的就输出
需要注意的是设为int型之后在输出时需要补全0 因此除了-1之外要输出printf("%05d\n",out);
同时在输入时需要吃掉没用的data项 当data为char时 中间的空格也会占用data 因此用scanf("%d %c %d",&addr,&data,&naddr);
在scanf中加空格是有用的
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