#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int times;
	if(str.size()>=3)
	{
		times = str[0] - '0';
		while(times--)
		{
			cout<<"B";
		}
		str = str.substr(1);
	}
	if(str.size()>=2)
	{
		times = str[0] - '0';
		while(times--)
		{
			cout<<"S";
		}
		str = str.substr(1);
	}
	if(str.size()>=1)
	{
		times = str[0] - '0';
		int i = 1;
		while(times--)
		{
			cout<<i++;
		}
	}
	cout<<endl;
	return 0;
}