/*
�ж϶���ʽ�󵼵���Ŀ����Ŀ����ܼ򵥣�������Ҫ�ж����㣬һ������ж������������windows�н�������ctrl+z��
��ֻ��Ҫ�ڲ���ʱ���룬oj���������������ļ��Դ������������ֻ��Ҫwhile(cin>>k>>e)�Ϳ����ж��Ƿ�������ɶ�
����Ч������
�ڶ���������Ҫ�жϵ������������ʱ��Ҫ���"0 0\n"
*/
#include <iostream>
using namespace std;

int main()
{
	int k,e;
	bool firstflag=true;
	while(cin>>k>>e)
	{
		if(e)
		{
			k*=e;
			e-=1;
			if(firstflag)
			{
				cout<<k<<" "<<e;
				firstflag=false;
			}
			else
			{
				cout<<" "<<k<<" "<<e;
			}
		}
	}
	if(firstflag)
	{
		cout<<0<<" "<<0;
	}
	cout<<endl;
	return 0;
}