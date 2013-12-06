/*
一开始出错是因为没有考虑到如果输入就是6174的情况下程序会跳出 
将while循环的break条件写在第一次运算完之后即可
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define N 4
int a[N];
int b[N];
int numa;
int numb;

void getNum()
{
	numa=0;
	numb=0;
	int ex=1;
	for(int i=N-1;i>=0;--i)
	{
		numa+=a[i]*ex;
		ex*=10;
	}
	ex=1;
	for(int i=N-1;i>=0;--i)
	{
		numb+=b[i]*ex;
		ex*=10;
	}
}

void getArray(int x)
{
	int i=0;
	while(x>0)
	{
		b[i++]=x%10;
		x/=10;
	}
	for(int j=i;j<N;++j)
		b[j]=0;
	sort(b,b+N);
	for(int j=0;j<N;++j)
		a[j]=b[N-j-1];
}

int main()
{
	int x;
	scanf("%d",&x);
	while(true)
	{
		getArray(x);
		getNum();
		x=numa-numb;
		printf("%04d - %04d = %04d\n",numa,numb,x);
		if(x==6174||x==0)
			break;
	}
	return 0;
}