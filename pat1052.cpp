/*
��map<string,Lnode>������addr�Ļ��ᳬʱ map������Ч ����ʹ������ֱ�Ӵ洢 ��Ϊaddr������ͬ ֱ��A[addr]=Lnode;����
��������������ʼ��ַ��-1������ʼ��ַ�Ҳ���ʱ ��� 0 begin
������Ŀ�Ĳ���������δ������������ʼ��ַ����һ�е�next�����ڵ����
*/
#include <iostream>
#include <algorithm>
#define MAX_N 100000
using namespace std;
struct Lnode
{
	int addr;
	int value;
	int next;
}llist[MAX_N],ans[MAX_N];
bool cmp(const Lnode &a, const Lnode &b)
{
	return a.value<b.value;
}
int main()
{
	int n,begin;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++)
	{
		Lnode tmp;
		scanf("%d%d%d",&tmp.addr,&tmp.value,&tmp.next);
		llist[tmp.addr]=tmp;
	}
	int num=0;
	while(begin!=-1)
	{
		ans[num++]=llist[begin];
		begin=llist[begin].next;
	}
	if(num!=0)
	{
		sort(ans,ans+num,cmp);
		int j=0;
		int last=ans[j].value;
		int lastaddr=ans[j++].addr;
		printf("%d %05d\n",num,lastaddr);
		for(;j<num;++j)
		{
			printf("%05d %d %05d\n",lastaddr,last,ans[j].addr);
			lastaddr=ans[j].addr;
			last=ans[j].value;
		}
		printf("%05d %d -1\n",lastaddr,last);
	}
	else
	{
		printf("%d %d\n",0,begin);
	}
	return 0;
}