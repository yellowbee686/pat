/*
判断多项式求导的题目，题目本身很简单，但是需要判断两点，一是如何判断输出结束，在windows中结束符是ctrl+z，
这只需要在测试时输入，oj的判题程序的输入文件自带结束符，因此只需要while(cin>>k>>e)就可以判断是否是输入成对
的有效整数。
第二个点在于要判断当程序本身无输出时需要输出"0 0\n"
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